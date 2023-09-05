#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <filesystem>
#include "HistogramImage.h"
#include "ImageManipulation.h"
#include "OpenImage.h"
#include "Threshold.h"

int main() {
	std::cout << "Hello Héctor" << std::endl;

	std::pair image1 = readImage("Pompis.jpg");
	std::pair image2 = readImage("Phasmophobia.jpg");
	if (!image1.first.empty())
		openImage(image1.first, image1.second);
	if (!image2.first.empty())
		openImage(image2.first, image2.second);

	return 0;
}