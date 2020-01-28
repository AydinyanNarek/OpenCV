#pragma once
#include "BaseVideo.h"
#include <string>
#include "CVDecoder.h"
#include "Filters.h"
#include <memory>

class VideoOverlay {

public:
    VideoOverlay(const std::vector <std::string>& files);

private:
    std::unique_ptr<BaseVideo> mDecoder;
    std::unique_ptr<Filters> mFilters;
};
