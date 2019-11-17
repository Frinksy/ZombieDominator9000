#include "greenDetection.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
using namespace cv;


void greenSelector (Mat *inputFrame, Mat *outputFrame)
{

    std::vector<int> lows = {60, 100, 80};
    std::vector<int> highs = {130, 255, 255};
    Mat equalizedFrame;
    Mat convertedFrame;

    // Convert to HSV format to get only green hues
    cvtColor(*inputFrame, convertedFrame, COLOR_BGR2HSV_FULL);

    // Threshold for green
    inRange(convertedFrame, lows, highs, *outputFrame);

    // Finishing touches
    medianBlur(*outputFrame, *outputFrame, 7);
}

void greenBoxer(Mat *inputFrame, Mat *outputFrame)
{

    std::vector< std::vector <Point> > contours;

    
    findContours(*inputFrame, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    if (contours.size())
    {

        for (int i = 0; i < contours.size(); i++)
        {
            Rect r = boundingRect(contours[i]);
            std::cout << r << std::endl;
            rectangle(*outputFrame, r, {255,0,0}, 10);
        }

    }
}