#pragma once
#include "BaseVideo.h"
#include <string>
#include "CVDecoder.h"
#include "CVEncoder.h"
#include "Filters.h"
#include <memory>

class VideoOverlay {

public:
    VideoOverlay(const std::vector <std::string>& files, int frameRate, const std::string& videoCodec, const std::string& fileExtension, const std::string& outFile);

private:
    std::unique_ptr<BaseVideo> mDecoder;
    std::unique_ptr<CVEncoder> mEncoder;
    std::unique_ptr<Filters> mFilters;
};
