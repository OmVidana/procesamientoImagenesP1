#pragma once

#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <filesystem>

cv::Mat binaryThreshold(cv::Mat inputImage, int thresholdValue);
cv::Mat binaryInverseThreshold(cv::Mat inputImage, int thresholdValue);
cv::Mat truncatedThreshold(cv::Mat inputImage, int thresholdValue);
cv::Mat toZeroThreshold(cv::Mat inputImage, int thresholdValue);
cv::Mat toZeroInverseThreshold(cv::Mat inputImage, int thresholdValue);
