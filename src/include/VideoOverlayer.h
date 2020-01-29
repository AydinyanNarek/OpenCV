//
//  VideoOverlayer.h
//
//  Created by Narek Aydinyan on 01/28/20.
//  Copyright © 2019 Narek Aydinyan. All rights reserved.
//
#pragma once
#include "BaseVideo.h"
#include <string>
#include "CVDecoder.h"
#include "CVEncoder.h"
#include "Filters.h"
#include <memory>

/**
 * @brief VideoOverlay class for overlaying the videos
 **/
class VideoOverlay {

public:
    /**
     * @brief VideoOverlay class parametrized constructor
     *   @param[in] file - vector of files to be encoded
     *   @param[in] integer - Framerate for output video
     *   @param[in] string -  Output video encoder
     *   @param[in] string -  Output video file extension
     *   @param[in] string -  Output video file path
     **/
    VideoOverlay(const std::vector <std::string>& files, int frameRate, const std::string& videoCodec, const std::string& fileExtension, const std::string& outFile);

private:
    std::unique_ptr<BaseVideo> mDecoder;
    std::unique_ptr<CVEncoder> mEncoder;
    std::unique_ptr<Filters> mFilters;
};
