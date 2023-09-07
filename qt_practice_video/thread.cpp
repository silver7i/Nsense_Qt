#include "thread.h"

Player::Player(QMutex *lock)
    :stop(true), data_lock(lock)
{ }

Player::~Player()
{
    data_lock->lock();
    cap.release();
    stop = true;
    data_lock->unlock();
    wait();
}

bool Player::loadVideo(QString filePath)
{
    //m_hVideoCapture.open(m_strVideoFile.toLocal8Bit().toStdString());
    cv::String videoPath = filePath.toLocal8Bit().toStdString();
    cap.open(videoPath);
    std::cout << "video path : " << videoPath << std::endl;
    if(cap.isOpened()){
        cap_fps = cap.get(cv::CAP_PROP_FPS);
        std::cout << "cap_fps : " << cap_fps << std::endl;
        return true;
    } else {
        return false;
    }
}

void Player::Play()
{
    if(!isRunning()){
        if(isStopped()){
            stop = false;
        }
        start(LowPriority);
    }
}

void Player::Stop()
{
    stop = true;

    if(st_qframe.size() != 0){
        std::swap(st_qframe, empty);
        std::cout << "----------------------------------------thread/ empty : " << st_qframe.empty() << std::endl;
    }
}


void Player::run()
{
    int delay = cvRound(1000/cap_fps);
    std::cout << "----------------------------------------thread/ delay : " << delay << std::endl;
    while (!stop) {
        etimer.start();
        cap >> frame;
        current_frame = cap.get(cv::CAP_PROP_POS_FRAMES);
        if(frame.empty()){
            stop = true;
            break;
        }
        if(frame.channels() == 3){
            cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
        }
        stFrame = {current_frame, frame.clone()};

        data_lock->lock();
        st_qframe.push(stFrame);
//        std::cout << "----------------------------------------thread/ qframe size 1 : " << st_qframe.size()/2 << std::endl;
        data_lock->unlock();
        //cv::String file_path = cv::format("%d_0_capture.jpg",current_frame);
        //cv::imwrite(file_path, frame);
        int elapsed_time = etimer.elapsed();

        this->msleep(delay-elapsed_time);

        if(current_frame == frame_count){
            std::swap(st_qframe, empty);
            stop = true;
            break;
        }
//        std::cout << "----------------------------------------thread/ qframe size 2 : " << st_qframe.size()/2 << std::endl;
    }
    emit capEnd();
}

std::queue<St_Frame> Player::st_qframe;

void Player::setFrame()
{
    cap.set(cv::CAP_PROP_POS_FRAMES, 0);
    frameCnt = 0;
}

void Player::msleep(int ms)
{
    struct timespec ts = {ms / 1000, (ms % 1000) * 1000 * 1000};
    nanosleep(&ts, NULL);
    //std::cout << "----thread/ sleep = sec : " << ts.tv_sec << " nsec : " << ts.tv_nsec << std::endl;
}

bool Player::isStopped() const{
    return this->stop;
}

double Player::getFrameRate()
{
    return cap_fps;
}

double Player::getCurrentFrame()
{
    current_frame = cap.get(cv::CAP_PROP_POS_FRAMES);
    printf("----------------------------------------[thread] current_frame : %d\n", current_frame);

    return current_frame;
}

double Player::getNumberOfFrames()
{
    frame_count = cap.get(cv::CAP_PROP_FRAME_COUNT);
    return frame_count;
}

void Player::setCurrentFrame( int frameNumber )
{
    cap.set(cv::CAP_PROP_POS_FRAMES, frameNumber);
}
