#pragma once

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <filesystem>

cv::Mat createImage(int width, int height, int type);
std::pair<cv::Mat, std::string> readImage(std::string path);
int openImage(cv::Mat inputImage, std::string fileName, double scale, int waitTime);