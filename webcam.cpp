#include <vector>
#include <iostream>
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/core/ocl.hpp>
#include <opencv2/videoio.hpp>

#include "greenDetection.hpp"
using namespace cv;
using namespace std;


int main(int argc, char** argv)
{
    VideoCapture cap;

    //cap.set(CAP_PROP_FRAME_WIDTH, 240);
    //cap.set(CAP_PROP_FRAME_HEIGHT, 320);
    if (argc == 1) 
    {
        if(!cap.open(0))
        {
            cout << "No camera found on channel 0\n";
        }
    }
    else 
    {
        int deviceID = stoi(argv[1]);
        int apiID = CAP_ANY;
        cout << deviceID << endl;
        cap.open(deviceID + apiID);
        if (!cap.isOpened())
        {
            cout << "No camera found on " << argv[1] << " channel\n";
            return 0;
        }
    }

    //int i = 0;
    for(;;)
    {
        Mat frame;
	    //cap >> frame;
        cap.read(frame);
        if( frame.empty() )
        {
            cout << "Frame empty\n";
            break;
        }
        if( waitKey(10) == 27 ) break; // stop capturing by pressing ESC 
        
        Mat greenFrame, cleanFrame;
        //cleanFrame = frame.clone();

        greenSelector(&frame, &greenFrame);
        greenBoxer(&greenFrame, &frame);
        
        char greenWindow[] = "Green";
        char turretWindow[] = "Turret Vision";
        namedWindow(greenWindow);
        namedWindow(turretWindow);

        moveWindow(greenWindow, 0, 0);
        moveWindow(turretWindow, frame.cols+3, 36);

        //imshow("CleanFrame", cleanFrame);
        imshow(greenWindow, greenFrame);
        imshow(turretWindow, frame);
    }
    return 0;
}
