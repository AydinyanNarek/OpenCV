#include "../include/VideoOverlayer.h"

VideoOverlay::VideoOverlay(const std::vector <std::string>& files) : 
    mDecoder(std::make_unique<CVDecoder>(files)), 
    mFilters (std::make_unique<Filters>()) {
    mDecoder->decode();
    auto video = mDecoder->getDecodedImages();
    auto masks = mFilters->findMoveingObject(std::move(video[0]));

}