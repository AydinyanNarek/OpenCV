#include "../include/CVDecoder.h"
#include "opencv2/videoio/legacy/constants_c.h"
#include "opencv2/video/background_segm.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/video.hpp"
#include <future>

/*void CVDecoder::write(const std::vector<cv::Mat>& img, bool color) {

    cv::VideoWriter video2("outcpp.avi", CV_FOURCC('M','J','P','G'), mFrameRate, cv::Size(mWidth, mHeight), color);
    for(auto & it : img) {
        video2.write(it);
    }
    video2.release();
}*/

CVDecoder::CVDecoder(const std::vector<std::string>& file) : BaseVideo(file), mVideoCap(BaseVideo::CVMAKE<cv::VideoCapture*>(0)) {
    try{
        initialize();
    }
    catch(...) {
        releaseBuffers();
        throw("cant open\n");
    }
}

CVDecoder::~CVDecoder() {
    releaseBuffers();
}

void CVDecoder::free(std::unique_ptr<typename std::remove_pointer<video>::type, void (*)(video)> ptr) {
    if(nullptr != ptr) {
        ptr->release();
        ptr.reset();
    }
}

void CVDecoder::releaseBuffers() {
    free(std::move(mVideoCap));
    for (auto&& it : mVideoCapturesBuffer) {
        free(std::move(it));
    }
}
void CVDecoder::openFile() {
    std::lock_guard<std::mutex>lock(mt);
    mVideoCap = BaseVideo::CVMAKE(new cv::VideoCapture(mFile));
    if(!mVideoCap->isOpened()) {
        throw("cant open\n");
    }
    mFrameRate = mVideoCap->get(CV_CAP_PROP_FPS);
    mWidth = mVideoCap->get(CV_CAP_PROP_FRAME_WIDTH);
    mHeight = mVideoCap->get(CV_CAP_PROP_FRAME_HEIGHT);
    mFrameCount = mVideoCap->get(CV_CAP_PROP_FRAME_COUNT);
}

void CVDecoder::initialize() {
    
    std::thread fileThread(&CVDecoder::openFile, this);
    for(auto&& it : mOverlays) {
        auto temp = BaseVideo::CVMAKE(new cv::VideoCapture(it));
        if(!temp->isOpened()) {
            throw("cant open\n");
        }
        mVideoCapturesBuffer.emplace_back(std::move(temp));
    }
    if (fileThread.joinable()) {
        fileThread.join();
    }
}

std::vector<cv::Mat> CVDecoder::readVideo(std::unique_ptr<typename std::remove_pointer<video>::type, void (*)(video)> ptr) {
    std::lock_guard<std::mutex>lock(mVideoReaderMutex);
    std::vector<cv::Mat> temp;
    for(;;) {
        cv::Mat frame;
        *(ptr) >> frame;

        if (frame.empty()) {
            break;
        }
        temp.emplace_back(std::move(frame));
    }
    return temp;
}

void CVDecoder::decode() {
    auto future = std::async(&CVDecoder::readVideo, this, std::move(mVideoCap));
    for(auto&& it : mVideoCapturesBuffer) {
        auto overlay = readVideo(std::move(it));
        auto temp = resize(overlay);
        mOverlayBuffer.emplace_back(std::move(temp));
    }
    mBackground = future.get();
}

std::vector<cv::Mat> CVDecoder::resize(const std::vector<cv::Mat>& moveing) {
    std::vector<cv::Mat> dest;
    dest.resize(moveing.size());
    int i = 0;
    for (auto & it : moveing) {
        cv::resize(it, dest[i], cv::Size(mWidth, mHeight));
        ++i;
    }
    return dest;
}

/*void CVDecoder::process() {
    std::vector<cv::Mat> temp;
    temp.resize(mOverlayBuffer[0].size());
    resize(mOverlayBuffer[0], temp);
    auto masks = findMoveingObject(temp);
    overlay(mBackground, temp, masks);
}*/

