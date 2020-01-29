
#include "../include/VideoOverlayer.h"
#include <stdexcept>

int main () try {

    VideoOverlay ob ({"/home/nareka/Desktop/GITHUBProjects/OpenCV/testData/bacground2.avi", "/home/nareka/Desktop/GITHUBProjects/OpenCV/testData/test2.avi"}, 30, "FFV1", "avi", "out.avi");
}
catch(const char* e){
    std::cout << e;
}
catch(const std::string& e){
    std::cout << e;
}

catch(cv::Exception& e) {
    throw (e.what());
}
catch(const std::exception & e) {
    std::cout << e.what();
}
catch(...) {
  std::cout << "Undefined exception was occured" << std::endl;
}