#include "opencv2/opencv.hpp"
#include <opencv2/videoio.hpp>
#include <vector>
#include "greenDetection.hpp"
#include <opencv2/core/ocl.hpp>
using namespace cv;


int main(int argc, char** argv)
{
    VideoCapture cap;
    
    cap.set(CAP_PROP_FRAME_WIDTH, 240);
    cap.set(CAP_PROP_FRAME_HEIGHT, 320);
    if (argc == 1) {
        if(!cap.open(0))
            return 0;
    }else {
        if (!cap.open(argv[1]))
            return 0;
    }

    
    int i = 0;
    for(;;)
    {
        Mat frame;
	    cap >> frame;
        if( frame.empty() )
        {
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
