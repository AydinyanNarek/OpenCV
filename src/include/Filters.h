//
//  Filters.h
//
//  Created by Narek Aydinyan on 01/28/20.
//  Copyright © 2019 Narek Aydinyan. All rights reserved.
//
#pragma once
#include "BaseVideo.h"
#include <vector>
#include <string>
#include "opencv2/tracking/tracker.hpp"

/**
 * @brief class Filters for processing decoded images
 **/
class Filters : public BaseVideo {

public:
    /**
     * @brief Finds moveing object from input images and gets tha mask of images
     *   @param[in] vector -  Vector of images to be processed
     *   @param[out] vector - Vector of image masks
     **/
    std::vector<cv::Mat> findMoveingObject(const std::vector< cv::Mat>&);

    /**
     * @brief Overlayes the moving video to background using masks
     *   @param[in] vector -  Vector of images of background
     *   @param[in] vector -  Vector of moving images to be overlayed
     *   @param[in] vector -  Vector of image masks
     *   @param[out] vector - Vector of overlayed images to background
     **/
    std::vector<cv::Mat> overlay(const std::vector<cv::Mat>& background, const std::vector<cv::Mat>& moving, const std::vector<cv::Mat>& mask);

private:

    /**
     *  @brief Removes background from moveing images using KNN algorithm
     *   @param[in] vector -  Vector of images with  background
     *   @param[out] vector - Vector of images without background
     **/
    std::vector<cv::Mat> subtractBackground(const std::vector<cv::Mat>&);

    /**
     *  @brief Struct Contours - Image cotoures and theyer hierarchy
     **/
    struct Contours
    {
        Contours() = default;
        std::vector<std::vector<cv::Point>> mContours;
        std::vector<cv::Vec4i> mHierarchy;
    };

    /**
     *  @brief Selects only largest components in the binary image
     *   @param[in] img -  Image to be slected
     *   @param[in] cont - Image cotoures and theyer hierarchy
     *   @param[out] dst - Destination image already filtered
     **/
    void filterObjects(const cv::Mat& img, const Contours & cont, cv::Mat& dst);

    /**
     *  @brief Tracks the objet in video
     *   @param[in] rect - Object bounding box
     *   @param[in] begin - Image start for tracking
     *   @param[in] next - Image next for tracking
     *   @param[in] tracker - OpencCV traker for tracking images
     *   @param[out] Rect2d - Returns bounding box
     **/
    cv::Rect2d ojectTracker(const cv::Rect2d& rect, cv::Mat& begin, cv::Mat& next, cv::Ptr<cv::Tracker> tracker);

    /**
     *  @brief Find bounding box around a contour
     *   @param[in] vector - Vector of coordinates
     *   @param[out] Rect2d - Returns bounding box
     **/
    cv::Rect2d toBoundingBox(const std::vector<cv::Point>&);  

    /**
     *  @brief Find contours im image mask
     *   @param[in] mask - Image mask
     *   @param[out] contours - Contours detected from image mask
     **/  
    Contours detectContours(const cv::Mat& mask);
};
