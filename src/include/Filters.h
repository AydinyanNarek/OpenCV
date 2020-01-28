#pragma once
#include "BaseVideo.h"
#include <vector>
#include <string>
#include "opencv2/tracking/tracker.hpp"

class Filters : public BaseVideo {

public:
    std::vector<cv::Mat> findMoveingObject(const std::vector< cv::Mat>&);

private:
    std::vector<cv::Mat> subtractBackground(const std::vector<cv::Mat>&);

    struct Contours
    {
        Contours() = default;
        std::vector<std::vector<cv::Point>> mContours;
        std::vector<cv::Vec4i> mHierarchy;
    };

    void filterObjects(const cv::Mat& img, const Contours &, cv::Mat& dst);
    cv::Rect2d ojectTracker(const cv::Rect2d&, cv::Mat& begin, cv::Mat& next, cv::Ptr<cv::Tracker>);
    cv::Rect2d toBoundingBox(const std::vector<cv::Point>&);    
    Contours detectContours(const cv::Mat& mask);
    std::vector<cv::Mat> overlay(const std::vector<cv::Mat>& background, const std::vector<cv::Mat>& moving, const std::vector<cv::Mat>& mask);
};
