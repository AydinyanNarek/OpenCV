#include "../include/CVDecoder.h"
#include "../include/VideoOverlayer.h"

#include <iostream>
#include "opencv2/opencv.hpp"
#include <thread>

int main () try {
   //CVDecoder ob({"/home/nareka/Downloads/bacground2.avi", "/home/nareka/Downloads/test2.avi"});
  // ob.decode();
   VideoOverlay ob ({"/home/nareka/Downloads/bacground2.avi", "/home/nareka/Downloads/test2.avi"});
   //ob.process();
   /* cv::VideoCapture cap(0 + cv::CAP_ANY);

    cap.open("/home/nareka/Downloads/test4.mp4"); 
    if(!cap.isOpened()){
    std::cout << "Error opening video stream or file" << std::endl;
    return -1;
  }
     
  while(1){
 
    cv::Mat frame;
    // Capture frame-by-frame
    cap >> frame;
  
    // If the frame is empty, break immediately
    if (frame.empty())
      break;
 
    // Display the resulting frame
    cv::imshow( "Frame", frame );
 
    // Press  ESC on keyboard to exit
    char c=(char)cv::waitKey(25);
    if(c==27)
      break;
  }
  
  // When everything done, release the video capture object
  cap.release();
 
  // Closes all the frames
  cv::destroyAllWindows();*/
}
catch(...){
  std::cout << "bad exception\n";
}