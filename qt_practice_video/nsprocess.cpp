#include "nsprocess.h"

NSprocess::NSprocess(QMutex *lock)
    :data_lock(lock)
{ }

NSprocess::~NSprocess()
{
    face_track_infos.clear();
    frame_infos.clear();
    user_infos.clear();
}

void NSprocess::init()
{
    NSFS_STATUS status = NSFS_SUCCESS;

    // license key : NSENSE_DEVKOREA
    if ((status = NSFS_Create("33b84e7e-49f8-4609-9608-f46747eda97e")) == NSFS_SUCCESS) {
        std::cout << "init sdk success" << std::endl;
    }
    else {
        std::string err_str = "";
        NSFS_GetErrorString(status, err_str);
        std::cout << "init sdk failed - " << err_str << std::endl;
        return;
    }
}

void NSprocess::uninit()
{
    NSFS_STATUS status = NSFS_SUCCESS;

    if ((status = NSFS_Delete()) == NSFS_SUCCESS) {
        std::cout << "uninit sdk success" << std::endl;
    }
    else {
        std::cout << "uninit sdk failed - %d" << std::endl;
        return;
    }
}


void NSprocess::Face_Rect(cv::Mat &frame)
{
    std::vector<TrackFaceInfo> face_track_infos;
    if (NSFS_TrackFaceInfos(face_track_infos, frame.data, frame.cols, frame.rows) == NSFS_SUCCESS) {
        for(int i = 0; i < face_track_infos.size(); i++){
            TrackFaceInfo tfi = face_track_infos[i];
            int x1 = static_cast<int>(std::round(tfi.face.rect.x1 - tfi.face.rect.width * 0.01));
            int x2 = static_cast<int>(std::round(tfi.face.rect.x2 - tfi.face.rect.width * 0.01));
            int y1 = static_cast<int>(std::round(tfi.face.rect.y1 - tfi.face.rect.width * 0.01));
            int y2 = static_cast<int>(std::round(tfi.face.rect.y2 - tfi.face.rect.width * 0.01));
            x1 = std::max(0, x1); x2 = std::min(frame.cols - 1, x2);
            y1 = std::max(0, y1); y2 = std::min(frame.rows - 1, y2);

            cv::Rect r = cv::Rect(cv::Point(x1,y1), cv::Point(x2,y2));
            cv::rectangle(frame, r, cv::Scalar(0, 255, 0));
            cv::putText(frame, cv::format("%d", i), cv::Point(x1, y1-10), cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(0,0,255), 2);
        }
    }
}

void NSprocess::NSblurring(cv::Mat &frame)
{
    cv::Mat frame_show = cv::Mat::zeros(frame.rows, frame.cols, CV_8UC3);
    cv::Mat frame_draw = frame.clone();
    cv::Mat frame_blur = frame.clone();

    std::vector<TrackFaceInfo> face_track_infos;
    if (NSFS_TrackFaceInfos(face_track_infos, frame.data, frame.cols, frame.rows) == NSFS_SUCCESS) {
        cv::Mat frame_mask = cv::Mat::zeros(frame.rows, frame.cols, CV_8UC3);
        for(int i = 0; i < face_track_infos.size(); i++){
            TrackFaceInfo tfi = face_track_infos[i];
            int x1 = static_cast<int>(std::round(tfi.face.rect.x1 - tfi.face.rect.width * 0.01));
            int x2 = static_cast<int>(std::round(tfi.face.rect.x2 - tfi.face.rect.width * 0.01));
            int y1 = static_cast<int>(std::round(tfi.face.rect.y1 - tfi.face.rect.width * 0.01));
            int y2 = static_cast<int>(std::round(tfi.face.rect.y2 - tfi.face.rect.width * 0.01));
            x1 = std::max(0, x1); x2 = std::min(frame.cols - 1, x2);
            y1 = std::max(0, y1); y2 = std::min(frame.rows - 1, y2);
            int w = x2 - x1, h = y2 - y1;
            cv::Mat mask = cv::Mat::zeros(h, w, CV_8UC3);
            cv::ellipse(mask, cv::Point(w/2,h/2), cv::Size(w/2,h/2), 0, 0, 360, cv::Scalar(255, 255, 255), -1);
            cv::Mat mask_inv;
            cv::bitwise_not(mask, mask_inv);
            cv::Mat mask_g, mask_th;
            cv::cvtColor(mask, mask_g, cv::COLOR_BGR2GRAY);
            cv::threshold(mask_g, mask_th, 125, 255, cv::THRESH_BINARY);
            std::vector<std::vector<cv::Point>> contours;
            std::vector<cv::Vec4i> hierarchy;
            cv::findContours(mask_th, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

            std::vector<cv::Point> poly(contours[0].size());
            float peri = cv::arcLength(contours[0], true);
            cv::approxPolyDP(contours[0], poly, 0.01 * peri, true);
            for (int i=0; i<poly.size(); i++) {
                cv::Point p1 = cv::Point(x1+poly[i].x,y1+poly[i].y);
                if (i == poly.size()-1) {
                    cv::Point p2 = cv::Point(x1+poly[0].x,y1+poly[0].y);
                    cv::line(frame_draw, p1, p2, cv::Scalar(0,255,0), 2);                }
                else {
                    cv::Point p2 = cv::Point(x1+poly[i+1].x,y1+poly[i+1].y);
                    cv::line(frame_draw, p1, p2, cv::Scalar(0,255,0), 2);
                }
                cv::circle(frame_draw, p1, 2, cv::Scalar(0,0,255), -1);
            }
            cv::Rect mask_rect = cv::Rect(cv::Point(x1,y1),cv::Point(x2,y2));
            cv::Mat r_frame = frame_blur(mask_rect);

            cv::cuda::GpuMat gpu_img, gpu_rimg;
            gpu_img.upload(r_frame);
            cv::Ptr<cv::cuda::Filter> ga_filter = cv::cuda::createGaussianFilter(CV_8UC3, CV_8UC3, cv::Size(31,31), 15);
            ga_filter->apply(gpu_img, gpu_rimg);
            cv::Mat blurred_box;
            gpu_rimg.download(blurred_box);

            cv::Mat b_mask;
            cv::bitwise_and(mask, blurred_box, b_mask);
            cv::Mat f_mask;
            cv::bitwise_and(mask_inv, r_frame, f_mask);
            cv::Mat blur_mask;
            cv::add(b_mask, f_mask, blur_mask);

            blur_mask.copyTo(frame_blur(mask_rect));

            //frame_draw.copyTo(frame_show(cv::Rect(0,0,frame_draw.cols,frame_draw.rows)));
            //frame_blur.copyTo(frame_show(cv::Rect(0,frame_blur.rows,frame_blur.cols,frame_blur.rows)));
            frame_blur.copyTo(frame_show);
            frame = frame_show;
        }
    }
}


void NSprocess::NSfaceindex(cv::Mat *img, int frame_count)
{
    std::cout << "-------------------- NSfaceindex in -------------" << std::endl;
    std::cout << "-------------------- frame_count : " << frame_count << std::endl;

    cv::Mat frame = *img;

    cv::Rect detect_rect = cv::Rect(20,20,frame.cols-20,frame.rows-20);

    std::vector<TrackFaceInfo> face_track_infos;
    if (NSFS_TrackFaceInfos(face_track_infos, frame.data, frame.cols, frame.rows) == NSFS_SUCCESS) {
        for (int i=0; i<face_track_infos.size(); i++) {
            TrackFaceInfo tfi = face_track_infos[i];
            std::vector<uint8_t> face_data;
            NSFS_GetFaceImage(face_data, frame.data, frame.cols, frame.rows, tfi.face);
            std::string face_feature;
            // ms()
            timer.start();
            //NSFS_GetFaceFeature(face_feature, face_data.data());
//            int elapsed_time = timer.elapsed();
//            printf("-------------------- elapsed_time : %d\n", elapsed_time);
            //

//            std::cout << "-------------------- faceindex i : " << i << std::endl;
            FrameInfo_T fi;
            fi.frame_idx = frame_count;
            fi.feature = face_feature;
            fi.bbox = tfi.face;
            fi.face = cv::Mat(112,112,CV_8UC(3),face_data.data()).clone();
            cv::Rect face_rect = cv::Rect(tfi.face.rect.x1, tfi.face.rect.y1, tfi.face.rect.width, tfi.face.rect.height);
            cv::Rect img_edge1 = cv::Rect(8,8,8,8);
            cv::Rect img_edge2 = cv::Rect(8,103,8,8);
            cv::Rect img_edge3 = cv::Rect(103,8,8,8);
            cv::Rect img_edge4 = cv::Rect(103,103,8,8);
            cv::Mat face_gray;
            cv::cvtColor(fi.face, face_gray, cv::COLOR_BGR2GRAY);
            if ((face_rect & detect_rect).area() < face_rect.area()*0.9 ||
                    face_rect.width > face_rect.height*1.5 ||
                    (cv::countNonZero(face_gray(img_edge1))==0 || cv::countNonZero(face_gray(img_edge2))==0 ||
                     cv::countNonZero(face_gray(img_edge3))==0 || cv::countNonZero(face_gray(img_edge4))==0)) {
                fi.iou = 0;
            }
            else {
                fi.iou = std::sqrt(std::pow(tfi.face.lmark[0].x-tfi.face.lmark[1].x,2)+std::pow(tfi.face.lmark[0].y-tfi.face.lmark[1].y,2));
            }
            frame_infos[tfi.track_id].push_back(fi);

            //printf("-------------------- frame_infos : %ld\n", frame_infos.size());
        }
    }
}

void NSprocess::reset_frame_infos()
{
    frame_infos.clear();

}

void NSprocess::NSregister()
{
    std::cout << "-------------------- NSregister in -------------" << std::endl;
    for (auto elem1 : frame_infos) {
        std::sort(frame_infos[elem1.first].begin(), frame_infos[elem1.first].end(),
                [](FrameInfo first, FrameInfo second) -> bool {                 // auto -> FrameInfo
            return first.iou > second.iou;
        });
        if (frame_infos[elem1.first].size()>0) {
            std::string fea1, fea2;
            std::string tid = cv::format("tid_%ld",elem1.first);
            if (NSFS_ReadUser(fea1, fea2, tid) == NSFS_ERR_UNREGISTERED_USER) {
                NSFS_AddUser(tid, frame_infos[elem1.first][0].feature);
                if (frame_infos[elem1.first].size()>1) {
                    NSFS_UpdateUser(tid, frame_infos[elem1.first][1].feature);
                }
            }
            else if (fea2.size()==0 && frame_infos[elem1.first].size()>1) {
                NSFS_UpdateUser(tid, frame_infos[elem1.first][1].feature);
            }
        }
    }

    int uid = 0;
    std::cout << "-------------------- NSfind in -------------" << std::endl;
    for (auto elem1 : frame_infos) {
        tid = cv::format("tid_%ld",elem1.first);
        float similarity;
        NSFS_Match1N(mid, similarity, frame_infos[elem1.first][0].feature);

        if (tid!=mid && similarity>=1.0) {
            int tid_int = 0;
            find_str = "tid_";
            std::size_t pos = mid.find(find_str);
            if(pos < mid.find(find_str))
                mid.replace(mid.find(find_str),find_str.length()," ");
            std::stringstream tid_str(mid);
            tid_str >> tid_int;

            std::copy(frame_infos[tid_int].begin(), frame_infos[tid_int].end(), std::back_inserter(frame_infos[elem1.first]));
            frame_infos.erase(tid_int);

            std::sort(frame_infos[elem1.first].begin(), frame_infos[elem1.first].end(),
                    [](FrameInfo first, FrameInfo second) -> bool {
                return first.iou > second.iou;
            });
        }

        for (int i=0; i<frame_infos[elem1.first].size(); i++) {
            int idx = frame_infos[elem1.first][i].frame_idx;
            RecogInfo_T ri;
            ri.bbox = frame_infos[elem1.first][i].bbox;
            ri.face = frame_infos[elem1.first][i].face;
            ri.user_id = uid;
            user_infos[idx].push_back(ri);
        }
        uid++;
//        printf("user_infos size : %ld\n", user_infos.size());
    }
}

void NSprocess::reset_user_infos()
{
    user_infos.clear();
}


void NSprocess::NSdrawFace(cv::Mat frame, std::vector<Draw_FaceInfo_T> &vFace, int frame_count)
{
    std::cout << "NSdraw Face count  -------- : " << frame_count << std::endl;
    cv::VideoWriter writer;

    cv::Mat frame_draw = frame.clone();
    cv::Mat face_channel = cv::Mat::zeros(cv::Size(), CV_8UC3);

//    std::cout << "NSdraw user_infos[frame_count].size()  -------- : " << user_infos[frame_count].size() << std::endl;
    for (int i=0; i<user_infos[frame_count].size(); i++) {
        FaceRect bbox = user_infos[frame_count][i].bbox.rect;
        std::vector<FacePoint2f> lmark = user_infos[frame_count][i].bbox.lmark;
        int uid = user_infos[frame_count][i].user_id;
        cv::Rect r = cv::Rect(cv::Point(bbox.x1,bbox.y1),cv::Point(bbox.x2,bbox.y2));
//        printf("r size : %ld\n", r.size());
        cv::rectangle(frame, r, cv::Scalar(0,255,0));
        cv::putText(frame, cv::format("uid %d",uid), cv::Point(bbox.x1,bbox.y1-10), cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(0,0,255), 2);
        //cv::imwrite(cv::format("/data/notebook/practice/qt/qt_practice_cam/slider_ver/%d_u%d_face.jpg",frame_count,uid), user_infos[frame_count][i].face);

        cv::Mat ch_clone = face_channel.clone();

//        std::cout << "uid : " << uid << std::endl;
        cv::Mat user_face = user_infos[frame_count][i].face;
        user_face.copyTo(ch_clone);

        draw_info.user_id = uid;
        draw_info.face = ch_clone.clone();
        draw_info.r_size = r.size().area() / 1000;

        vFace.push_back(draw_info);
    }
    for (auto elem1 : vFace) {
        std::sort(vFace.begin(), vFace.end(), [](Draw_FaceInfo_T first, Draw_FaceInfo_T second){
           return first.r_size < second.r_size;
        });
    }
}


