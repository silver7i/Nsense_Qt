#ifndef READFRAME_H
#define READFRAME_H

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

#include "thread.h"
#include "nsprocess.h"

//extern std::queue<St_Frame> st_qframe;
//extern std::condition_variable queueCV;

class ReadFrame: public QThread
{
    Q_OBJECT
public:
    ReadFrame(int num, QMutex *lock);
    ~ReadFrame() override;


//    void Play();
//    void Stop();
//    bool isStopped() const;

private:
//    bool stop_;
    int th_num;
    QMutex *data_lock;
    std::queue<cv::Mat> qImg;
    int cnt = 1;
    QElapsedTimer etimer;
protected:
    void run() override;

signals:
    void processedImage(cv::Mat *data, int cnt);

};

#endif // READFRAME_H
