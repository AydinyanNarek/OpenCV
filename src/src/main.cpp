
#include "../include/VideoOverlayer.h"
#include <stdexcept>

//TODO'S
//1.Add out of core implementation 
//2.Add support for more file formats and video encoders
//3.Add different background subtractor filters
//4.Do memory clean up more generic way
//5.Build OpenCV for Windows and Mac, upgrade CMake file for haveing crossplatform support
//The same project could be also done useing FFMPEG, but I choosed OpenCV for trying something new for me

int main () try {

    VideoOverlay ob ({"/home/nareka/Desktop/GITHUBProjects/OpenCV/testData/bacground2.avi", "/home/nareka/Desktop/GITHUBProjects/OpenCV/testData/test2.avi"}, 30, "FFV1", "avi", "/home/nareka/Desktop/GITHUBProjects/OpenCV/testData/out.avi");
}
catch(const char* e){
    std::cout << e;
}
catch(const std::string& e){
    std::cout << e;
}

catch(cv::Exception& e) {
     std::cout <<  e.what();
}
catch(const std::exception & e) {
    std::cout << e.what();
}
catch(...) {
  std::cout << "Undefined exception was occurred" << std::endl;
}