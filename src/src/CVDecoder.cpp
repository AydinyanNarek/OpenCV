#include "../include/CVDecoder.h"
#include "opencv2/videoio/legacy/constants_c.h"
#include "opencv2/video/background_segm.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/video.hpp"
#include <future>

void BaseVideo::registerErrors() {
    Errors::ErrorRegister::registerErrors({
        {"FileOpenError",                   "Failed to open input file."},
        {"InvalidInputArgumentError",       "Invalid input argument."},
        {"InvalidFileFormatError",          "Output file format not supported."},
        {"InvalidCodecError",               "Video Encoder not supported or not available for container."},
        {"UnregisteredTypeError",           "Failed to use the type as it is not supported."}
    });
}

CVDecoder::CVDecoder(const std::vector<std::string>& file) : BaseVideo(file), mVideoCap(BaseVideo::CVMAKE<cv::VideoCapture*>(0)) {
    try{
        initialize();
    }
    catch(...) {
        releaseBuffers();
        Errors::ErrorRegister::Throw("FileOpenError");
    }
}

CVDecoder::~CVDecoder() {
    auto future = std::async(&CVDecoder::releaseFrames, this);
    releaseBuffers();
    future.get();
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

void CVDecoder::releaseFrames() {
    for(auto&& overlays : mOverlayBuffer) {
        for(auto&& it : overlays) {
            it.release();
        }
    }
    for(auto&& it : mBackground) {
        it.release();
    }
}

void CVDecoder::openFile() {
    std::lock_guard<std::mutex>lock(mt);
    mVideoCap = BaseVideo::CVMAKE(new cv::VideoCapture(mFile));
    if(!mVideoCap->isOpened()) {
        Errors::ErrorRegister::Throw("FileOpenError");
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
            Errors::ErrorRegister::Throw("FileOpenError");
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
    cv::Mat dest;
    for(;;) {
        cv::Mat frame;
        *(ptr) >> frame;

        if (frame.empty()) {
            break;
        }
        cv::resize(frame, dest, cv::Size(mWidth, mHeight));
        temp.emplace_back(std::move(dest));
        frame.release();
        dest.release();
    }
    return temp;
}

void CVDecoder::decode() {
    auto future = std::async(&CVDecoder::readVideo, this, std::move(mVideoCap));
    for(auto&& it : mVideoCapturesBuffer) {
        auto overlay = readVideo(std::move(it));
        mOverlayBuffer.emplace_back(std::move(overlay));
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


