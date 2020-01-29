#include "../include/Filters.h"

std::vector<cv::Mat> Filters::overlay(const std::vector<cv::Mat>& background, const std::vector<cv::Mat>& moving, const std::vector<cv::Mat>& mask) {
    auto frameNum = std::min(background.size(), moving.size());
    std::vector<cv::Mat> output;
    output.resize(background.size());
    cv::Mat temp1;
    cv::Mat temp2;
    cv::Mat temp3;
    for (int i  = 0; i  < frameNum; ++i) {
        cv::bitwise_not(mask[i], temp3);
        
        temp1 = mask[i].mul(moving[i]);
        temp2 = temp3.mul(background[i]);
        //cv::multiply(mask[i], moving[i], temp1);
        //cv::multiply(temp3, background[i], temp2);
        //moving[i].copyTo(temp1, mask[i]);
        //background[i].copyTo(temp2, temp3);
        auto temp = temp1 + temp2;
            cv::imshow( "Frame", temp3 );
        
            // Press  ESC on keyboard to  exit
            char c = (char)cv::waitKey(27);
        
        output.emplace_back(temp);
    }

    return output;
    //write(output, true);
}


cv::Rect2d Filters::toBoundingBox(const std::vector<cv::Point>& points) {
    int minX = 0;
    int minY = 0;
    int maxX = 0;
    int maxY = 0;
    for(const auto & it : points){
        if(minX > it.x) {
            minX = it.x;
        }
        if(minY > it.y) {
            minY = it.y;
        }
        if(maxX < it.x) {
            maxX = it.x;
        }
        if(maxY < it.y) {
            maxY = it.y;
        }
    }
    return cv::Rect2d (cv::Point(minX, minY), cv::Point(maxX, maxY));
}


cv::Rect2d Filters::ojectTracker(const cv::Rect2d& bBox, cv::Mat& begin, cv::Mat& next, cv::Ptr<cv::Tracker> tracker) {
    cv::Rect2d bBoxTemp;
    tracker->init(begin, bBox);
    // Update the tracking result
    bool ok = tracker->update(next, bBoxTemp);
    if(!ok) {
       return {};
    }
    return bBoxTemp;
}

std::vector<cv::Mat> Filters::findMoveingObject(const std::vector< cv::Mat>& images) {
    //Starting with second frame for haveing referance to track
    std::vector<cv::Mat> result;
    result.resize(images.size());
    
    auto backgrounds = subtractBackground(images); 
    for(size_t i = 0; i < images.size(); ++i) {
        auto counts =  detectContours(backgrounds[i]);
        filterObjects(images[i], counts, result[i]);
    }
    return result;
}

std::vector<cv::Mat> Filters::subtractBackground(const std::vector<cv::Mat>& video) {

    cv::Ptr<cv::BackgroundSubtractor> bgsubtractor = cv::createBackgroundSubtractorKNN(500, 400, false);
    std::vector<cv::Mat> bgmask;
    bgmask.resize(video.size());
    int i = 0;
    for(auto& it: video) {
        bgsubtractor->apply(it, bgmask[i], true ? -1 : 0);
        ++i;
    }
    return bgmask;
}

Filters::Contours Filters::detectContours(const cv::Mat& mask) {
    
    int nIters = 3;//number of iterations
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::Mat temp;

    dilate(mask, temp, cv::Mat(), cv::Point(-1,-1), nIters);
    erode(temp, temp, cv::Mat(), cv::Point(-1,-1), nIters*2);
    dilate(temp, temp, cv::Mat(), cv::Point(-1,-1), nIters);
    cv::findContours( temp, contours, hierarchy, 2, 2);
    if( contours.size() == 0 ) {
        return {};
    }
    return  {contours, hierarchy};
}

void Filters::filterObjects(const cv::Mat& img, const Filters::Contours & cont, cv::Mat& dst) {

    if( (cont.mContours.size() == 0) || (cont.mHierarchy.size() == 0)) {
        return;
    }

    dst = cv::Mat::zeros(img.size(), CV_8UC1);

    // iterate through all the top-level contours,
    // draw each connected component with its own random color
    int idx = 0, largestComp = 0;
    double maxArea = 0;
    for( ; idx >= 0; idx = cont.mHierarchy[idx][0] )
    {
        const std::vector<cv::Point>& c = cont.mContours[idx];
        double area = std::abs(cv::contourArea(cv::Mat(c)));
        if( area > maxArea )
        {
            maxArea = area;
            largestComp = idx;
        }
    }
    cv::Scalar color(255);
    cv::drawContours(dst, cont.mContours, largestComp, color, -1, 8, cont.mHierarchy );
}
