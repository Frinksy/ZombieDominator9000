#ifndef DEF_GREENDETECTION
#define DEF_GREENDETECTION
#include "opencv2/opencv.hpp"
#include <opencv2/videoio.hpp>
#include <opencv2/videoio.hpp>


void greenSelector(cv::Mat *inputFrame, cv::Mat *outputFrame);

void greenBoxer(cv::Mat *inputFrame, cv::Mat *outputFrame);





#endif