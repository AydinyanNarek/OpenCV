#include "../include/VideoOverlayer.h"

VideoOverlay::VideoOverlay(const std::vector <std::string>& files, int frameRate, const std::string& videoCodec, const std::string& fileExtension, const std::string& outFile) : 
    mDecoder(std::make_unique<CVDecoder>(files)), 
    mFilters (std::make_unique<Filters>()) {
    try {
        mDecoder->decode();
        auto video = mDecoder->getDecodedMoveingVideo();
        for(const auto& it : video) {
            auto masks = mFilters->findMoveingObject(std::move(it));
            auto background = mDecoder->getBackground();

            auto overlays = mFilters->overlay(background, it, masks);
            mEncoder = std::make_unique<CVEncoder>(frameRate, mDecoder->getWidth(), mDecoder->getHeight(), videoCodec, fileExtension, outFile);
            mEncoder->encode(overlays);
        }
    }
    catch(cv::Exception& e) {
        throw (e.what());
    }

}