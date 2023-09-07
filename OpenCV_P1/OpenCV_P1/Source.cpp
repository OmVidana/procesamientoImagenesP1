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

	cv::Mat image1 = cv::imread("pexels-supreet-7749314.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat image2 = cv::imread("pexels-supreet-8134647.jpg", cv::IMREAD_GRAYSCALE);

	std::filesystem::path binImg1 = "bin1.jpg";
	std::filesystem::path binImg2 = "bin2.jpg";
	std::filesystem::path binInvImg1 = "binInv1.jpg";
	std::filesystem::path binInvImg2 = "binInv2.jpg";
	std::filesystem::path trunImg1 = "trun1.jpg";
	std::filesystem::path trunImg2 = "trun2.jpg";
	std::filesystem::path toZImg1 = "toZ1.jpg";
	std::filesystem::path toZImg2 = "toZ2.jpg";
	std::filesystem::path toZI_Img1 = "toZI1.jpg";
	std::filesystem::path toZI_Img2 = "toZI2.jpg";

	cv::imwrite(binImg1.string(), binaryThreshold(image1, 127));
	cv::imwrite(binImg2.string(), binaryThreshold(image2, 127));
	cv::imwrite(binInvImg1.string(), binaryInverseThreshold(image1, 127));
	cv::imwrite(binInvImg2.string(), binaryInverseThreshold(image2, 127));
	cv::imwrite(trunImg1.string(), truncatedThreshold(image1, 127));
	cv::imwrite(trunImg2.string(), truncatedThreshold(image2, 127));
	cv::imwrite(toZImg1.string(), toZeroThreshold(image1, 127));
	cv::imwrite(toZImg2.string(), toZeroThreshold(image2, 127));
	cv::imwrite(toZI_Img1.string(), toZeroInverseThreshold(image1, 127));
	cv::imwrite(toZI_Img2.string(), toZeroInverseThreshold(image2, 127));

	return 0;
}