#pragma once
#include <string>
#include <vector>
#include <memory>
#include "opencv2/opencv.hpp"

class BaseVideo {

public:
template<class T> 
    static auto CVMAKE(T object) {
        return std::unique_ptr<typename std::remove_pointer<T>::type, void (*)(T)>(object, [](T object) { delete object; });
    }

public:
    BaseVideo() = default;
    explicit BaseVideo(const std::vector<std::string>& file){
        if (file.size() < 2) {
            throw("the input must contain at least 2 files");
        }
        mFile = file.at(0);
        for(size_t i = 1; i < file.size(); ++i){
            mOverlays.emplace_back(std::move(file[i]));
        }
    };
    virtual ~BaseVideo() = default;

public:
    int getWidth() const { return mWidth;}
    int getHeight() const { return mHeight;}
    int getFrameRate() const { return mFrameRate;}
    void setWidth(int width)  { mWidth = width;}
    void setHeight(int height)  { mHeight = height; }
    void setFrameRate(int framerate) { mFrameRate = framerate; }
    const std::vector<std::vector<cv::Mat>>& getDecodedImages () { return mOverlayBuffer; }
    virtual void decode() {};
protected:
    int mWidth = 0;
    int mHeight = 0;
    int mFrameRate = 0;
    int mFrameCount = 0;
    std::string mFile;
    std::vector<std::string> mOverlays;
    std::vector<std::unique_ptr<typename std::remove_pointer<cv::VideoCapture*>::type, void (*)(cv::VideoCapture*)>> mVideoCapturesBuffer;
    std::vector<std::vector<cv::Mat>> mOverlayBuffer;
    std::vector<cv::Mat> mBackground;
};