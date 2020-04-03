#ifndef DEF_GREENDETECTION
#define DEF_GREENDETECTION
#include "opencv2/opencv.hpp"
#include <opencv2/videoio.hpp>
#include <opencv2/videoio.hpp>
#include <vector>

void greenSelector(cv::Mat *inputFrame, cv::Mat *outputFrame);

cv::Rect rectBoxer(std::vector<cv::Rect> rects);

void greenBoxer(cv::Mat *inputFrame, cv::Mat *outputFrame);





#endif