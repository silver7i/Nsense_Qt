#include "readframe.h"

ReadFrame::ReadFrame(int num, QMutex *lock)
    :data_lock(lock)
{
    th_num = num;
}

ReadFrame::~ReadFrame()
{
    wait();
}

void ReadFrame::run()
{
    cv::Mat frame;
    cv::Mat frameClone;
    int cnt_num;
    while (true) {

        data_lock->lock();
        if( Player::st_qframe.empty()){
            data_lock->unlock();
            msleep(10);
            continue;
            printf("-------------------------------------------------------------------------------- %d read/ sleep\n", th_num);
        } else {
//            printf("-------------------------------------------------------------------------------- %d read/ qframe size : %ld\n", th_num, Player::st_qframe.size());
            cnt_num = Player::st_qframe.front().current_num;
            frame = Player::st_qframe.front().frame.clone();
            Player::st_qframe.pop();

            etimer.start();
            //cv::imwrite(cv::format("%d_%d_process.jpg",cnt,th_num),frame);
//            printf("-------------------------------------------------------------------------------- %d read/ pop size : %ld\n", th_num, Player::st_qframe.size());
            emit processedImage(&frame, cnt_num);

            data_lock->unlock();

//            int elapsed_time = etimer.elapsed();

//            printf("-------------------------------------------------------------------------------- %d read/ cnt, elapsed_time : %d, %d\n", th_num, cnt_num, elapsed_time);
        }

    }
}

//void ReadFrame::run()
//{
//    std::queue<cv::Mat> qframe_;
//    cv::Mat frame;
//    while (!stop_) {
//        //St_Frame qframe_ = st_qframe.front();
//        //st_qframe.pop();

//        data_lock->lock();
//        if( Player::qframe.empty()){
//            data_lock->unlock();
//            msleep(10);
//            continue;
////            wait();
//            printf("-------------------------------------------------------------------------------- %d read/ sleep\n", th_num);
//        } else {
//            frame = Player::qframe.front().clone();
//            Player::qframe.pop();

//            etimer.start();

//            printf("-------------------------------------------------------------------------------- %d read/ qframe size : %ld\n", th_num, Player::qframe.size());

//            //cv::imwrite(cv::format("%d_%d_process.jpg",cnt,th_num),frame);

//            printf("-------------------------------------------------------------------------------- %d read/ pop size : %ld\n", th_num, Player::qframe.size());

//            emit processedImage(&frame, cnt);
//            data_lock->unlock();
//            int elapsed_time = etimer.elapsed();

//            cnt++;
//            printf("-------------------------------------------------------------------------------- %d read/ cnt, elapsed_time : %d, %d\n", th_num, cnt, elapsed_time);
//        }

//    }
//}

//void ReadFrame::Play()
//{
//    if(!isRunning()){
//        if(isStopped()){
//            stop_ = false;
//        }
//        start(LowPriority);
//    }
//}

//void ReadFrame::Stop()
//{
//    stop_ = true;
//}

//bool ReadFrame::isStopped() const{
//    return this->stop_;
//}
