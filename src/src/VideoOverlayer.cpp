#include "../include/VideoOverlayer.h"

VideoOverlay::VideoOverlay(const std::vector <std::string>& files, int frameRate, const std::string& videoCodec, const std::string& fileExtension, const std::string& outFile) : 
    mDecoder(std::make_unique<CVDecoder>(files)), 
    mFilters (std::make_unique<Filters>()) {
    try {
        mDecoder->decode();
        auto video = mDecoder->getDecodedImages();
        auto masks = mFilters->findMoveingObject(std::move(video[0]));
        mEncoder = std::make_unique<CVEncoder>(frameRate, mDecoder->getWidth(), mDecoder->getHeight(), videoCodec, fileExtension, outFile);
        mEncoder->encode(masks);
    }
    catch(cv::Exception& e) {
        throw (e.what());
    }

}