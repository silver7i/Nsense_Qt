#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFileDialog>
#include <QTime>
#include <QListWidget>

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/cudafilters.hpp>

#include <iostream>
#include <unordered_map>
#include <queue>

#include "thread.h"
#include "readframe.h"
#include "NSFaceSDK.h"
#include "utils_common.h"
#include "nsprocess.h"

#define QFACE_SIZE 3


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void read_Img(cv::Mat img, int count);

    void faceRegister();
    void findPerson();

    void blurringImg(cv::Mat &img);
    void faceindexImg(cv::Mat img, std::vector<Draw_FaceInfo_T> &vFace, int frame_count);
    //void faceindexImg(cv::Mat img, std::queue<Draw_FaceInfo_T> &draw_qFace, int frame_count);

private slots:
    void on_cam_open_clicked();
    void on_cam_close_clicked();

    void read_Frame(cv::Mat *img, int count);
    void update_window(cv::Mat img, int count);

    QString getFormattedTime(int timeInSeconds);

    void on_video_silder_sliderMoved(int position);
    void on_video_silder_sliderPressed();
    void on_video_silder_sliderReleased();
    void on_play_btn_clicked();
    void on_replay_btn_clicked();
    void on_saveindex_btn_clicked();

    void on_btn_file_clicked();

private:
    Ui::MainWindow *ui;

    cv::Mat read_frame;
    cv::Mat frameC;

//    std::queue<cv::Mat> qFace;
//    std::queue<Draw_FaceInfo_T> draw_qFace;
    std::vector<Draw_FaceInfo_T> vFace;
    cv::Mat draw_Face;
    int uid;

    std::queue<int> qsize;

    //std::queue<St_Frame> qframe;

    QMutex *data_lock;
    Player *capture;
    ReadFrame *frameRead1;
    NSprocess *NS;
    cv::Mat currentFrame;

    cv::String videoPath;
    QString file_name;

    int frameCnt;
    bool replay;
    bool saveindex;

    QImage qt_image;
    QPixmap qt_pixmap;
    QImage qt_image2;
    QPixmap qt_pixmap2;

    QListWidgetItem *item;

};
#endif // MAINWINDOW_H
