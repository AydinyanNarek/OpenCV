//
//  CVEncoder.h
//
//  Created by Narek Aydinyan on 01/28/20.
//  Copyright © 2019 Narek Aydinyan. All rights reserved.
//
#pragma once
#include "BaseVideo.h"
#include <vector>

/**
 * @brief CVEncoder for encodeing images to output file
 **/
class CVEncoder {

public:

    /**
     * @brief CVEncoder class default constructor
     **/
    CVEncoder() = default;

    /**
     * @brief CVEncoder class parametrized constructor
     *   @param[in] integer - Framerate for output video
     *   @param[in] integer - Image width for output video
     *   @param[in] integer - Image height for output video
     *   @param[in] string -  Output video encoder
     *   @param[in] string -  Output video file extension
     *   @param[in] string -  Output video file path
     **/
    explicit CVEncoder( int frameRate, int width, int height, const std::string& videoCodec, const std::string& fileExtension, const std::string& outFile);

    /**
     * @brief CVEncoder class destructor
     **/
    ~CVEncoder() = default;

public:

    /**
     * @brief Encodes the images
     *   @param[in] vector -  vector of images to be encoded
     **/
    void encode(const std::vector<cv::Mat>&);
private:

    /**
     * @brief Finds the encoder and checks for container matcheing
     **/
    int findEncoder();
private:

    int mFramerate;
    int mWidth;
    int mHeight;
    std::string mVideoCodec;
    std::string mFileExtension;
    std::string mOutFile;

};