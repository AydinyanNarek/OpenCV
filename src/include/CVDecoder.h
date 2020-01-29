#pragma once 
#include "BaseVideo.h"
#include <string>
#include <memory>
#include <mutex>
#include <thread>
#include "opencv2/video.hpp"
#include "opencv2/core/ocl.hpp"
#include "opencv2/tracking/tracker.hpp"

class CVDecoder : public BaseVideo {

public:
    explicit CVDecoder(const std::vector<std::string>& file);
    ~CVDecoder();

public:
    void initialize();
    void decode();
   // void process();

private:
    using video = cv::VideoCapture*;
    void openFile();
    std::vector<cv::Mat> readVideo(std::unique_ptr<typename std::remove_pointer<video>::type, void (*)(video)> ptr);
    void releaseBuffers();
    void free(std::unique_ptr<typename std::remove_pointer<video>::type, void (*)(video)> ptr);
    std::vector<cv::Mat> resize(const std::vector<cv::Mat>& moving);
    
private:
    
    std::unique_ptr<typename std::remove_pointer<video>::type, void (*)(video)>mVideoCap;
    std::mutex mt;
    std::mutex mVideoReaderMutex;
    //void write(const std::vector<cv::Mat>& img, bool color = false);
};