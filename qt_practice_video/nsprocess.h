#ifndef NSPROCESS_H
#define NSPROCESS_H

#include <QThread>
#include <QtDebug>
#include <QMutex>
#include <QImage>
#include <QElapsedTimer>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/cudafilters.hpp>

#include <iostream>
#include <queue>
#include <unordered_map>

#include "NSFaceSDK.h"
#include "utils_common.h"

typedef struct FrameInfo {
    int frame_idx;
    float iou;
    FaceInfo bbox;
    std::string feature;
    cv::Mat face;
} FrameInfo_T;

typedef struct RecogInfo {
    int user_id;
    FaceInfo bbox;
    cv::Mat face;
} RecogInfo_T;

typedef struct Draw_FaceInfo {
    int user_id;
    cv::Mat face;
    int r_size;
} Draw_FaceInfo_T;

class NSprocess: public QThread
{
    Q_OBJECT
private:
    std::vector<TrackFaceInfo> face_track_infos;
    std::unordered_map<unsigned long, std::vector<FrameInfo_T>> frame_infos;
    std::unordered_map<int, std::vector<RecogInfo_T>> user_infos;

    QMutex *data_lock;
    int frame_count = 0;

    std::string tid, mid;
    std::string find_str;

    Draw_FaceInfo_T draw_info;

    QElapsedTimer timer;
public:
    NSprocess(QMutex *lock);
    ~NSprocess();
    void init();
    void uninit();

protected:

signals:
    void faceImage(std::queue<cv::Mat> *data, int qsize);

public slots:
    void Face_Rect(cv::Mat &frame);
    void NSblurring(cv::Mat &frame);
    void NSfaceindex(cv::Mat *frame, int frame_count);
    void NSregister();
    void NSdrawFace(cv::Mat frame, std::vector<Draw_FaceInfo_T> &qFace_, int frame_count);

    void reset_frame_infos();
    void reset_user_infos();

};

#endif // NSPROCESS_H
