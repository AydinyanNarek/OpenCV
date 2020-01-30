//
//  BaseVideo.h
//
//  Created by Narek Aydinyan on 01/28/20.
//  Copyright © 2019 Narek Aydinyan. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <memory>
#include "opencv2/opencv.hpp"
#include "ErrorManager/ErrorRegister.h"

/**
 * @brief Base class for video processing
 **/
class BaseVideo {

public:
template<class T> 
    static auto CVMAKE(T object) {
        return std::unique_ptr<typename std::remove_pointer<T>::type, void (*)(T)>(object, [](T object) { delete object; });
    }
    /**
     * @brief Registers all project errors
    **/
    static void registerErrors();    

public:
    /**
     * @brief Base class default constructor
     **/
    BaseVideo() = default;

    /**
     *   @brief Base class parametrized constructor
     *   @param[in] file - vector of files to be decodeed
     **/
    explicit BaseVideo(const std::vector<std::string>& file){
        if (file.size() < 2) {
            Errors::ErrorRegister::Throw("InvalidInputArgumentError", "the input must contain at least 2 files");
        }

        mFile = file.at(0);
        for(size_t i = 1; i < file.size(); ++i){
            mOverlays.emplace_back(std::move(file[i]));
        }
    };
    /**
     * @brief Base class destructor
     **/
    virtual ~BaseVideo() = default;

public:
    /**
     *   @brief Get decoded vector of vectors which contains vector of decoded images 
     *   @param[out] vector of vectors - Contains decoded images which should be overlayed
    **/
    const std::vector<std::vector<cv::Mat>>& getDecodedMoveingVideo () { return mOverlayBuffer; }

    /**
     *   @brief Get decoded vector of images for background of the optput video 
     *   @param[out] vector of images - Contains decoded images which should be used as output background
    **/
    const std::vector<cv::Mat>& getBackground () { return mBackground; }

    /**
     *   @brief Get background image width
     *   @param[out] integer -image width
    **/
    const int getWidth() { return mWidth; }

    /**
     *   @brief Get background image height
     *   @param[out] integer -image height
    **/
    const int getHeight() { return mHeight; }

    /**
     *   @brief Decode the input files and stores in vector of Mat type images
    **/
    virtual void decode() {}

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