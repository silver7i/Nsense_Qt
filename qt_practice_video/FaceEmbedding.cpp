#include "FaceEmbedding.h"

namespace Engine {

CFaceEmbedding::CFaceEmbedding(FaceModelType model_type, std::string model_path, const int gpu_id)
{
    m_IFaceEmbedding = nullptr;
    init(model_type, model_path, gpu_id);
}

CFaceEmbedding::~CFaceEmbedding()
{
}

cv::Mat CFaceEmbedding::Estimation(cv::Mat frame)
{
        cv::Mat estimated;
    if (m_IFaceEmbedding!=nullptr) {
        m_IFaceEmbedding->Run(frame, estimated);
    }
        return estimated;
}

}
