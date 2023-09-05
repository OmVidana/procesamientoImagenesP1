#pragma once

#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

cv::Mat addTwoImages(cv::Mat firstImage, cv::Mat secondImage);
cv::Mat addTwoImages(cv::Mat firstImage, cv::Mat secondImage, double w1, double w2);
cv::Mat addConstant(cv::Mat inputImage, int addition);
cv::Mat addFunction(cv::Mat inputImage);
cv::Mat verticalAddition(cv::Mat firstImage, cv::Mat secondImage, float w1, float w2);
cv::Mat horizontalAddition(cv::Mat firstImage, cv::Mat secondImage, float w1, float w2);
cv::Mat substractTwoImages(cv::Mat firstImage, cv::Mat secondImage);
cv::Mat inverse(cv::Mat inputImage);