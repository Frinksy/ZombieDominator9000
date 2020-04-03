#include "greenDetection.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/photo/cuda.hpp>
#include <opencv2/core/ocl.hpp>
#include <iostream>
using namespace cv;


void greenSelector (Mat *inputFrame, Mat *outputFrame)
{

    std::vector<int> lows = {70, 90, 50};
    std::vector<int> highs = {130, 255, 255};
    Mat equalizedFrame;
    Mat convertedFrame;

    // Convert to HSV format to get only green hues
    cvtColor(*inputFrame, convertedFrame, COLOR_BGR2HSV_FULL);

    // Threshold for green
    inRange(convertedFrame, lows, highs, *outputFrame);
    
    // Eroding test
    erode(*outputFrame, *outputFrame, getStructuringElement(MORPH_ELLIPSE, Size(11,11)));

    // Finishing touches
    //medianBlur(*outputFrame, *outputFrame, 7);

}

Rect rectBoxer (std::vector<Rect> rects)
{

    int minX  = 276447231 , minY = 276447231, maxX = 0, maxY = 0;


    for (int i = 0; i < rects.size(); i++)
    {   
        if (rects[i].width * rects[i].height > 50) // TODO : tune this check to better suit noise elimination
        {
            if (rects[i].x < minX){
                minX = rects[i].x;
            }
            if (rects[i].y < minY){
                minY = rects[i].y;
            }
            if (rects[i].width + rects[i].x > maxX){
                maxX = rects[i].width + rects[i].x;
            }
            if (rects[i].height + rects[i].y > maxY){
                maxY = rects[i].height + rects[i].y;
            }
        }
    }
    //std::cout << Rect(minX, minY, maxX-minX, maxY-minY) << std::endl;
    return Rect(minX, minY, maxX-minX, maxY-minY);
}

void greenBoxer(Mat *inputFrame, Mat *outputFrame)
{

    std::vector< std::vector <Point> > contours;

    
    findContours(*inputFrame, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    if (contours.size())
    {
        std::vector <Rect> rects;
        for (int i = 0; i < contours.size(); i++)
        {
            rects.push_back( boundingRect(contours[i]) );
            //rectangle(*outputFrame, boundingRect(contours[i]), {0,0,255}, 10);
            
        }
        Rect outerRect  = rectBoxer(rects);
        //std::cout << outerRect << std::endl;
        rectangle(*outputFrame, outerRect, {255,0,0}, 2);
    }  
}
