#pragma once
#include "BaseVideo.h"

class CVEncoder : public BaseVideo {

public:
    explicit CVEncoder(const std::string& output);
    ~CVEncoder();

public:
    void encode();

private:
    std::string  mOutFile;     
};