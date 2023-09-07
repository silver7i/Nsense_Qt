#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QWidget *qwidget = new QWidget(this);

//    auto *vbox = new QVBoxLayout(this);
//    auto *hbox = new QHBoxLayout();

//    openBtn = new QPushButton("Open", this);
//    closeBtn = new QPushButton("Close", this);

//    hbox->addWidget(openBtn, 1, Qt::AlignRight);
//    hbox->addWidget(closeBtn, 0);

//    label = new QLabel(this);

//    vbox->addWidget(label);
//    vbox->addStretch(1);

//    vbox->addLayout(hbox);
//    qwidget->setLayout(vbox);
//    setCentralWidget(qwidget);

//    connect(openBtn, &QPushButton::clicked, this, &MainWindow::on_cam_open_clicked);
//    connect(closeBtn, &QPushButton::clicked, this, &MainWindow::on_cam_close_clicked);

    timer = new QTimer(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_cam_open_clicked()
{
    if(ui->radioBtn1->isChecked()){
        cap.open("/data/notebook/practice/qt/qt_practice_cam/testVideo.mp4");
    } else if(ui->radioBtn2->isChecked()){
        cap.open("rtsp://admin:wellsystem6279@192.168.1.180/onvif/profile2/media.smp");
    } else if(ui->radioBtn3->isChecked()){
        cap.open("rtsp://admin:wellsystem6279@192.168.1.29/onvif/profile2/media.smp");
    } else {
        std::cout << "press the source" << std::endl;
        QMessageBox::information(this, "error", "press the source");
    }

    if(!cap.isOpened())
    {
        std::cout << "camera is not open" << std::endl;
    } else {
        std::cout << "camera is open" << std::endl;

        connect(timer, SIGNAL(timeout()), this, SLOT(update_window()));
        timer->start(20);
    }
}

void MainWindow::on_cam_close_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(update_window()));
    cap.release();

    cv::Mat image = cv::Mat::zeros(frame.size(), CV_8UC3);
    qt_image = QImage((const unsigned char*) (image.data), image.cols, image.rows, QImage::Format_RGB888);

    ui->label->setPixmap(QPixmap::fromImage(qt_image));

    //ui->label->resize(ui->label->pixmap()->size());

    std::cout << "camera is closed" << std::endl;
}

void MainWindow::update_window()
{
    cap >> frame;

    cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);

    if(ui->blurring_CkB->isChecked()){
        //connect(ui->blurring_CkB, SIGNAL(isChecked()), this, SLOT(process()));
        //connect(ui->blurring_CkB, SIGNAL(clicked()), this, SLOT(blurring()));
        //blurring();
        process();

    } else {
        //disconnect(ui->blurring_CkB, SIGNAL(isChecked()), this, SLOT(process()));
        //disconnect(this, SIGNAL(clicked()), this, SLOT(blurring()));
    }

    int w = ui->label->width();
    int h = ui->label->height();

    qt_image = QImage((const unsigned char*) (frame.data), frame.cols, frame.rows, QImage::Format_RGB888); /*process data == (frame.data)*/
    qt_pixmap = QPixmap::fromImage(qt_image);
    //ui->label->setPixmap(QPixmap::fromImage(qt_image));
    ui->label->setPixmap(qt_pixmap.scaled(w,h,Qt::KeepAspectRatio));
    ui->label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    //ui->label->resize(ui->label->pixmap()->size());
}

void MainWindow::blurring()
{
    cv::GaussianBlur(frame, frame, cv::Size(31,31), 15);
}




void MainWindow::process()
{
    frame_show = cv::Mat::zeros(frame.rows, frame.cols*2, CV_8UC3);
    cv::Mat frame_draw = frame.clone();
    cv::Mat frame_blur = frame.clone();

    std::vector<TrackFaceInfo> face_track_infos;
    cv::Mat frame_mask = cv::Mat::zeros(frame.rows, frame.cols, CV_8UC3);
    for(int i = 0; i < face_track_infos.size(); i++){
        TrackFaceInfo tfi = face_track_infos[i];
        int x1 = static_cast<int>(std::round(tfi.face.rect.x1 - tfi.face.rect.width * 0.2));
        int x2 = static_cast<int>(std::round(tfi.face.rect.x2 - tfi.face.rect.width * 0.2));
        int y1 = static_cast<int>(std::round(tfi.face.rect.y1 - tfi.face.rect.width * 0.2));
        int y2 = static_cast<int>(std::round(tfi.face.rect.y2 - tfi.face.rect.width * 0.2));
        x1 = std::max(0, x1); x2 = std::min(frame.cols - 1, x2);
        y1 = std::max(0, y1); y2 = std::min(frame.rows - 1, y2);

        int w = x2 - x1, h = y2 - y1;
        cv::Mat mask = cv::Mat::zeros(h, w, CV_8UC3);
        cv::ellipse(mask, cv::Point(w/2,h/2), cv::Size(w/2,h/2), 0, 0, 360, cv::Scalar(255, 255, 255), -1);
        cv::Mat mask_inv;
        cv::bitwise_not(mask, mask_inv);

        cv::Mat mask_g, mask_th;
        cv::cvtColor(mask, mask_g, cv::COLOR_BGR2GRAY);
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
                cv::line(frame_draw, p1, p2, cv::Scalar(0,255,0), 2);
            }
            else {
                cv::Point p2 = cv::Point(x1+poly[i+1].x,y1+poly[i+1].y);
                cv::line(frame_draw, p1, p2, cv::Scalar(0,255,0), 2);
            }
            cv::circle(frame_draw, p1, 2, cv::Scalar(0,0,255), -1);
        }

        cv::Rect mask_rect = cv::Rect(cv::Point(x1,y1),cv::Point(x2,y2));
        cv::Mat r_frame = frame_blur(mask_rect);

        cv::Mat blurred_box;
        cv::GaussianBlur(r_frame, blurred_box, cv::Size(31,31), 15);

//        gpu_img.upload(r_frame);
//        cv::Ptr<cv::cuda::Filter> ga_filter = cv::cuda::createGaussianFilter(CV_8UC3, CV_8UC3, cv::Size(31,31), 15);
//        ga_filter->apply(gpu_img, gpu_rimg);
//        cv::Mat blurred_box;
//        gpu_rimg.download(blurred_box);

        cv::Mat b_mask;
        cv::bitwise_and(mask, blurred_box, b_mask);
        cv::Mat f_mask;
        cv::bitwise_and(mask_inv, r_frame, f_mask);
        cv::Mat blur_mask;
        cv::add(b_mask, f_mask, blur_mask);

        blur_mask.copyTo(frame_blur(mask_rect));

        frame_draw.copyTo(frame_show(cv::Rect(0,0,frame_draw.cols,frame_draw.rows)));
        frame_blur.copyTo(frame_show(cv::Rect(frame_blur.cols,0,frame_blur.cols,frame_blur.rows)));
        frame = frame_show;

    }
}




