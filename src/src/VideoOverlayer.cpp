#include "../include/VideoOverlayer.h"

VideoOverlay::VideoOverlay(const std::vector <std::string>& files, int frameRate, const std::string& videoCodec, const std::string& fileExtension, const std::string& outFile) : 
    mDecoder(std::make_unique<CVDecoder>(files)), 
    mFilters (std::make_unique<Filters>()) {
    try {
        mDecoder->decode();
        auto video = mDecoder->getDecodedMoveingVideo();
        auto masks = mFilters->findMoveingObject(std::move(video[0]));
        auto background = mDecoder->getBackground();

        auto overlays = mFilters->overlay(background, video[0], masks);
        for (auto & it : overlays) {
            imshow( "Frame", it );
        
            // Press  ESC on keyboard to  exit
            char c = (char)cv::waitKey(27);
        }
       // mEncoder = std::make_unique<CVEncoder>(frameRate, mDecoder->getWidth(), mDecoder->getHeight(), videoCodec, fileExtension, outFile);
      //  mEncoder->encode(masks);
    }
    catch(cv::Exception& e) {
        throw (e.what());
    }

}