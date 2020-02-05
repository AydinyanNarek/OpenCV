
#include "../include/VideoOverlayer.h"
#include <stdexcept>
#include <chrono> 
#include <filesystem>

//TODO'S
//1.Add out of core implementation 
//2.Add support for more file formats and video encoders
//3.Add different background subtractor filters
//4.Do memory clean up more generic way
//5.Build OpenCV for Windows and Mac, upgrade CMake file for haveing crossplatform support
//The same project could be also done useing FFMPEG, but I choosed OpenCV for trying something new for me

int main () try {

    auto dataPath = std::filesystem::current_path() / "../" / "testData";
    auto background = (dataPath / "bacground2.avi").string();
    auto overlay = (dataPath / "test2.avi").string();
    auto output  = (dataPath / "/out.avi").string();
    auto start = std::chrono::high_resolution_clock::now();

    VideoOverlay ob ({background, overlay}, 30, "FFV1", "avi", output);

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << elapsed.count() << std::endl;

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