#include "../include/CVEncoder.h"
#include <unordered_map>
#include <unordered_set>
#include "opencv2/video.hpp"
#include "opencv2/videoio/legacy/constants_c.h"
#include "ErrorManager/ErrorRegister.h"

//For future can be added other encoders with other file extensions
static const std::unordered_map<std::string, std::unordered_set<std::string>> videoCodecsWithContainers{
    {"mp4", {"MJPG", "MJ2C", "VP80", "HEVC", "X264", }},
    {"avi", {"ASV1", "ASV2", "FFV1", "MJPG", "HFYU", "MJ2C", "VP80", "SVQ1", "WMV1", "WMV2", "ZLIB"}},
    {"mkv", {"ASV1", "ASV2", "MJ2C", "WMV1", "WMV2", "ZLIB", "MJPG", "VP80"}}
};

int CVEncoder::findEncoder() {

    auto fileExtension = videoCodecsWithContainers.find(mFileExtension);
    if (fileExtension ==  videoCodecsWithContainers.end()) {
        Errors::ErrorRegister::Throw("InvaliedFileFormatError");
    }
    auto codec = fileExtension->second.find(mVideoCodec);
    if (codec ==  fileExtension->second.end()) {
        Errors::ErrorRegister::Throw("InvaliedCodecError");
    }

    return  CV_FOURCC((*codec)[0], (*codec)[1], (*codec)[2], (*codec)[3]);
}

CVEncoder::CVEncoder(int frameRate, int width, int height, const std::string& videoCodec, const std::string& fileExtension, const std::string& outFile) :
    mFramerate(frameRate),
    mWidth(width),
    mHeight(height),
    mVideoCodec(videoCodec), 
    mFileExtension(fileExtension),
    mOutFile(outFile) {}


void CVEncoder::encode(const std::vector<cv::Mat>& imageList) {
    cv::VideoWriter video(mOutFile,  findEncoder(), mFramerate, cv::Size(mWidth, mHeight), false);
    for(const auto & it : imageList) {
        video.write(it);
    }
}
