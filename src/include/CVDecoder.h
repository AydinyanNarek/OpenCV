//
//  CVDecoder.h
//
//  Created by Narek Aydinyan on 01/28/20.
//  Copyright © 2019 Narek Aydinyan. All rights reserved.
//
#pragma once 
#include "BaseVideo.h"
#include <string>
#include <memory>
#include <mutex>
#include <thread>
#include "opencv2/video.hpp"
#include "opencv2/core/ocl.hpp"
#include "opencv2/tracking/tracker.hpp"

/**
 * @brief CVDecoder for decodeing input files
 **/
class CVDecoder : public BaseVideo {

public:
    /**
     *   @brief CVDecoder class parametrized constructor
     *   @param[in] file - vector of files to be decodeed
     **/
    explicit CVDecoder(const std::vector<std::string>& file);

    /**
     * @brief CVDecoder class destructor which clean ups memory for allocated images
     **/
    ~CVDecoder();

public:
    /**
     * @brief Initialize the input files, get video properties and checks validation of the files
     **/
    void initialize();

    /**
     *   @brief Decode the input files and stores in vector of Mat type images
    **/
    void decode() override;

private:
    using video = cv::VideoCapture*;
    /**
     *   @brief Open the input files
    **/
    void openFile();

    /**
     *   @brief Read video data from file and store in vector of type Mat
     *   @param[in] ptr - Smart pointer of type VideoCapture
     *   @param[out] vector - output vector of Mat objects
    **/
    std::vector<cv::Mat> readVideo(std::unique_ptr<typename std::remove_pointer<video>::type, void (*)(video)> ptr);

    /**
     *   @brief Release all buffers which were allocated for storeing the images.
    **/
    void releaseBuffers();

    /**
     *   @brief Fres the memory which were allocated for creating cv::VideoCapture object
     *   @param[in] ptr - Smart pointer of type VideoCapture
    **/
    void free(std::unique_ptr<typename std::remove_pointer<video>::type, void (*)(video)> ptr);

    /**
     *   @briefResize the overlay image size to background image size and store the image to vector
     *   @param[in] vector - Vector of images to be resized 
     *   @param[out] vector - Vector of images already resized 
    **/
    std::vector<cv::Mat> resize(const std::vector<cv::Mat>& moving);

    void releaseFrames() ;
    
private:
    
    std::unique_ptr<typename std::remove_pointer<video>::type, void (*)(video)>mVideoCap;
    std::mutex mt;
    std::mutex mVideoReaderMutex;
};