#pragma once
#include "BaseVideo.h"
#include <vector>

class CVEncoder {

public:
    CVEncoder() = default;
    explicit CVEncoder( int frameRate, int width, int height, const std::string& videoCodec, const std::string& fileExtension, const std::string& outFile);
    ~CVEncoder() = default;

public:
    void encode(const std::vector<cv::Mat>&);
private:
    int findEncoder();
private:

    int mFramerate;
    int mWidth;
    int mHeight;
    std::string mVideoCodec;
    std::string mFileExtension;
    std::string mOutFile;

};