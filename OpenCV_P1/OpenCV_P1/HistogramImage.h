#pragma once
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

class HistogramDisplayer
{
public:

	HistogramDisplayer(std::string pathFile);
	void setWindowName(std::string name);
	void setInputImage(std::string path);
	void fillHistogram();
	void createHistogramImage();
	cv::Mat getHistogramImage();
	void displayInputImage();
	void displayHistogramImage();
	void closeHistogramDisplayer();

private:
	std::vector<int> histogram;
	std::string windowName;
	cv::Mat inputImage;
	cv::Mat histogramImage;

	void setHistogram(int size, int fill);
};