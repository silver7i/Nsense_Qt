#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    data_lock = new QMutex();

    ui->saveindex_btn->setEnabled(false);
    ui->replay_btn->setEnabled(false);
    ui->video_silder->setEnabled(false);
    ui->play_btn->setEnabled(false);

    ui->label_2->setText(tr("00:00"));
    ui->label_3->setText(tr("00:00"));

    ui->label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    //ui->face_label1->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

    ui->face_listWidget->setViewMode(QListWidget::IconMode);
    ui->face_listWidget->setIconSize(QSize(256,256));
    ui->face_listWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    ui->face_listWidget->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Maximum);
    //ui->face_listWidget->setAcceptDrops(false);

    capture = new Player(data_lock);
    frameRead1 = new ReadFrame(1, data_lock);
    NS = new NSprocess(data_lock);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete data_lock;
    delete capture;
    delete frameRead1;
    delete NS;
    delete item;
}


void MainWindow::on_cam_open_clicked()
{
    std::cout << "open button clicked" << std::endl;

    if(capture != nullptr){
        std::cout << "camera is already running" << std::endl;
        on_cam_close_clicked();

        capture->Stop();
        disconnect(frameRead1, &ReadFrame::processedImage, this, &MainWindow::read_Frame);
        connect(frameRead1, &ReadFrame::finished, frameRead1, &ReadFrame::deleteLater);
    }
    cv::cuda::setDevice(0);
    NS->init();

    if(ui->radioBtn1->isChecked()){
        //videoPath = "/data/notebook/practice/qt/qt_practice_cam/src/testVideo.mp4";
        //videoPath = "/data/notebook/practice/qt/qt_practice_cam/src/people.mp4";
        //videoPath = "/data/notebook/practice/qt/qt_practice_cam/src/sign_language.mp4";
        //videoPath = "/data/notebook/practice/qt/qt_practice_cam/src/sampleVideo.mp4";
        file_name = QFileDialog::getOpenFileName(this, "Select folder", "/data/notebook/practice/qt/src", "Files(*.mp4)");
    } else if(ui->radioBtn2->isChecked()){
        file_name = "rtsp://admin:wellsystem6279@192.168.1.180/onvif/profile2/media.smp";
    } else if(ui->radioBtn3->isChecked()){
        file_name = "rtsp://admin:wellsystem6279@192.168.1.29/onvif/profile2/media.smp";
    } else {
        std::cout << "press the source" << std::endl;
        QMessageBox::information(this, "error", "press the source");
    }

    if(capture->loadVideo(file_name)){
        NSFS_SetFaceMinSize(0);
        ui->saveindex_btn->setEnabled(true);
        ui->replay_btn->setEnabled(true);
        ui->video_silder->setEnabled(true);
        ui->play_btn->setEnabled(true);

        capture->setCurrentFrame(0);
        ui->video_silder->setMaximum(capture->getNumberOfFrames());
        ui->label_3->setText(getFormattedTime( (int)capture->getNumberOfFrames()/(int)capture->getFrameRate()) );
    }

    //connect(capture, SIGNAL(processedImage()), this, SLOT(update_window()));
    connect(frameRead1, &ReadFrame::processedImage, this, &MainWindow::read_Frame);
    connect(this, &MainWindow::faceindexImg, NS, &NSprocess::NSdrawFace);
    connect(this, &MainWindow::blurringImg, NS, &NSprocess::NSblurring);

    frameRead1->start();
}

void MainWindow::on_play_btn_clicked()
{
    std::cout << "play button clicked" << std::endl;
    if(capture->isStopped())
    {
        capture->Play();
        if(saveindex){
            NS->reset_user_infos();
        }
        ui->play_btn->setText(tr("Stop"));
    } else {
        capture->Stop();
        ui->play_btn->setText(tr("Play"));
    }
}


void MainWindow::on_replay_btn_clicked()
{
    std::cout << "replay button clicked" << std::endl;
    disconnect(capture, &Player::capEnd, NS, &NSprocess::NSregister);

    frameCnt = 0;
    replay = true;
    saveindex = false;
    capture->setFrame();
    capture->Play();

    ui->play_btn->setText(tr("Stop"));
    ui->label_now->setText(tr("  now : face Show "));
}

void MainWindow::on_saveindex_btn_clicked()
{
    std::cout << "save button clicked" << std::endl;
    connect(capture, &Player::capEnd, NS, &NSprocess::NSregister);

    saveindex = true;
    replay = false;
    capture->Play();

    ui->play_btn->setText(tr("Stop"));
    ui->label_now->setText(tr("  now : detecting "));
}

void MainWindow::on_cam_close_clicked()
{
    std::cout << "close button clicked" << std::endl;

    ui->play_btn->setEnabled(false);
    ui->video_silder->setEnabled(false);
    ui->label_2->setText("00:00");
    ui->label_3->setText("00:00");
    ui->video_silder->setValue(0);

    disconnect(this, &MainWindow::faceindexImg, NS, &NSprocess::NSdrawFace);
    disconnect(frameRead1, &ReadFrame::processedImage, this, &MainWindow::read_Frame);
    disconnect(capture, &Player::capEnd, NS, &NSprocess::NSregister);
    disconnect(this, &MainWindow::blurringImg, NS, &NSprocess::NSblurring);

    NS->uninit();
    ui->face_listWidget->clear();
    NS->reset_user_infos();
    NS->reset_frame_infos();

    cv::Mat image = cv::Mat::zeros(cv::Size(), CV_8UC3);
    qt_image = QImage((const unsigned char*) (image.data), image.cols, image.rows, QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(qt_image));
    std::cout << "camera is closed" << std::endl;
}


void MainWindow::read_Frame(cv::Mat *img, int frameCount)
{
    if(!img->empty())
        read_frame = *img;
    update_window(read_frame.clone(), frameCount);

    if(saveindex){
        frameC = read_frame.clone();
        QElapsedTimer etimer;
        etimer.start();
        NS->NSfaceindex(&frameC, frameCount);
        int elapsed_time = etimer.elapsed();
        printf("[main] elapsed_time : %d\n", elapsed_time);
    }
}


/////////////////////////////////////////////////////////////////
/// \brief MainWindow::update_window
/// \param img
/////////////////////////////////////////////////////////////////
void MainWindow::update_window(cv::Mat frame, int frameCnt)
{
    if(frame.empty()){
        frame = cv::Mat::zeros(cv::Size(), CV_8UC3);
        printf("[Main] frame empty ///////////////\n");
    }

    if (ui->NSblurring_CKB->isChecked()){
        emit blurringImg(frame);
    }
    if(replay){
        //emit faceindexImg(frame, vFace, frameCnt);
        NS->NSdrawFace(frame, vFace, frameCnt);
    } else {
        NS->Face_Rect(frame);
    }

    qt_image = QImage((const unsigned char*) (frame.data), frame.cols, frame.rows, QImage::Format_RGB888);
    qt_pixmap = QPixmap::fromImage(qt_image);
    ui->label->setPixmap(qt_pixmap.scaled(ui->label->width(),ui->label->height(),Qt::KeepAspectRatio, Qt::SmoothTransformation));

    ui->video_silder->setValue(capture->getCurrentFrame());
    ui->label_2->setText(getFormattedTime( (int)capture->getCurrentFrame()/(int)capture->getFrameRate()) );

    if(replay){
        if(vFace.empty()){
            return;
            printf("[main] empty");
        } else {
            int size = vFace.size();
            ui->face_listWidget->clear();

            for(int i = 0; i < size; ++i){
                draw_Face = vFace.back().face;
                uid = vFace.back().user_id;
                vFace.pop_back();

                double ratio = (double)draw_Face.cols / (double)draw_Face.rows;
                int h = 128;
                int w = ( ((int)((double)h * ratio) + 3) & ~3 );
                cv::resize(draw_Face, draw_Face, cv::Size(w, h), 0, 0, cv::INTER_AREA);

                qt_image2 = QImage((const unsigned char*) (draw_Face.data), draw_Face.cols, draw_Face.rows, QImage::Format_RGB888);
                qt_pixmap2 = QPixmap::fromImage(qt_image2);
                item = new QListWidgetItem(QIcon(qt_pixmap2), QString("uid-%1").arg(uid));
                ui->face_listWidget->addItem(item);
            }
            if(!vFace.empty()){
                vFace.clear();
            }
        }
    }
}


QString MainWindow::getFormattedTime(int timeInSeconds)
{
    int seconds = (int) (timeInSeconds) % 60;
    int minutes = (int) ((timeInSeconds / 60) % 60);
    int hours = (int) ((timeInSeconds / (60*60)) % 24);

    QTime t(hours, minutes, seconds);
    if(hours == 0){
        return t.toString("mm:ss");
    } else {
        return t.toString("h:mm:ss");
    }
}

void MainWindow::on_video_silder_sliderMoved(int position)
{
    capture->setCurrentFrame(position);
    ui->label_2->setText( getFormattedTime(position/(int)capture->getFrameRate()) );
}

void MainWindow::on_video_silder_sliderPressed()
{
    capture->Stop();
}

void MainWindow::on_video_silder_sliderReleased()
{
    capture->Stop();
    ui->play_btn->setText(tr("Play"));
}



void MainWindow::on_btn_file_clicked()
{
    QString file_name = QFileDialog::getExistingDirectory(this, "Select folder", QDir::currentPath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
}
