#ifndef THREAD_H
#define THREAD_H

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

#include "NSFaceSDK.h"
#include "utils_common.h"


typedef struct frameQueue {
    int current_num;
    cv::Mat frame;
} St_Frame;

//extern std::queue<St_Frame> st_qframe;

class Player: public QThread
{
    Q_OBJECT
private:
    bool stop;
    int cameraID;
    cv::String videoPath;
    QMutex *data_lock;
    cv::Mat frame;
    cv::Mat RGBframe;
    QImage img;
    cv::VideoCapture cap;

    int cap_fps;
    int cap_width;
    int cap_height;
    int current_frame;
    int frame_count;

    int frameCnt;
    std::queue<cv::Mat> qFace;

    St_Frame stFrame;
    std::queue<St_Frame> empty;
//    std::queue<cv::Mat> empty;

    QElapsedTimer etimer;

    std::vector<TrackFaceInfo> face_track_infos;

public:
    Player(QMutex *lock);
    ~Player() override;

    bool loadVideo(QString videoPath);
    void Play();
    void Stop();
    bool isStopped() const;
    void msleep(int ms);

    void setCurrentFrame(int frameNumber);
    void setFrame();
    double getFrameRate();
    double getCurrentFrame();
    double getNumberOfFrames();

    //static std::queue<cv::Mat> qframe;
    static std::queue<St_Frame> st_qframe;

protected:
    void run() override;
    
signals:
    void processedImage(cv::Mat *data);
//    void stImage(St_Frame *data);
    void savedImage(cv::Mat *data, int fcount);
    void capEnd();

};

#endif // THREAD_H
