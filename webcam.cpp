#include "opencv2/opencv.hpp"
#include <opencv2/videoio.hpp>
#include <vector>
#include "greenDetection.hpp"
#include <opencv2/core/ocl.hpp>
#include <iostream>
using namespace cv;


int main(int argc, char** argv)
{
    VideoCapture cap;
    
    //cap.set(CAP_PROP_FRAME_WIDTH, 240);
    //cap.set(CAP_PROP_FRAME_HEIGHT, 320);
    if (argc == 1) 
    {
        if(!cap.open(0))
        {
            std::cout << "No camera found on channel 0\n";
            return 0;
        }
    }
    else 
    {
        if (!cap.open(argv[1]))
        {
            std::cout << "No camera found on " << argv[1] << " channel\n";
            return 0;
        }
    }

    //int i = 0;
    for(;;)
    {
        Mat frame;
	    //cap >> frame;
        cap.retrieve(frame);
        if( frame.empty() )
        {
            std::cout << "Camera frame empty\n";
            break;
        }
        if( waitKey(10) == 27 ) break; // stop capturing by pressing ESC 
        Mat greenFrame;
        greenSelector(&frame, &greenFrame);
        greenBoxer(&greenFrame, &frame);
        

        imshow("GREEN", greenFrame);

        imshow("Turret VISION", frame);
    }
    return 0;
}
