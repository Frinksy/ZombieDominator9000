#include "opencv2/opencv.hpp"
#include <opencv2/videoio.hpp>
#include <vector>
using namespace cv;

void greenSelector (Mat *inputFrame, Mat *outputFrame)
{

    std::vector<int> lows = {60, 100, 80};
    std::vector<int> highs = {130, 255, 255};
    Mat equalizedFrame;
    Mat convertedFrame;
    //equalizeHist(*inputFrame, equalizedFrame);

    cvtColor(*inputFrame, convertedFrame, COLOR_BGR2HSV_FULL);
    //equalizeHist(convertedFrame, convertedFrame);


    inRange(convertedFrame, lows, highs, *outputFrame);
    medianBlur(*outputFrame, *outputFrame, 7);
}

int main(int argc, char** argv)
{
    VideoCapture cap;

    cap.set(CAP_PROP_FRAME_WIDTH, 240);
    cap.set(CAP_PROP_FRAME_HEIGHT, 320);

    if(!cap.open(0))
        return 0;
    
    int i = 0;
    for(;;)
    {
        i++;
          Mat frame;
	  cap >> frame;
        imshow("this is you, smile! :)", frame);
        Mat greenFrame;
          greenSelector(&frame, &greenFrame);

          if( frame.empty() ) break; // end of video stream
          imshow("green :)", greenFrame);
          if( waitKey(10) == 27 ) break; // stop capturing by pressing ESC 
    }
    // the camera will be closed automatically upon exit
    // cap.close();

    std::cout << std::endl << i << std::endl;
    return 0;
}
