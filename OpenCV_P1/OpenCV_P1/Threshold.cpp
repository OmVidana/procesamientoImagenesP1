#include "Threshold.h"

cv::Mat binaryThreshold(cv::Mat inputImage, int thresholdValue)
{
	cv::Mat outputImage;
	cv::cvtColor(inputImage, outputImage, cv::COLOR_BGR2GRAY);

	for (int x = 0; x < inputImage.cols; x++)
	{
		for (int y = 0; y < inputImage.rows; y++)
		{
			if (inputImage.at<uchar>(y, x) > thresholdValue)
				outputImage.at<uchar>(y, x) = static_cast<uchar>(255);
			else
				outputImage.at<uchar>(y, x) = static_cast<uchar>(0);
		}
	}
    return outputImage;
}

cv::Mat binaryInverseThreshold(cv::Mat inputImage, int thresholdValue)
{
	cv::Mat outputImage;
	cv::cvtColor(inputImage, outputImage, cv::COLOR_BGR2GRAY);

	for (int x = 0; x < inputImage.cols; x++)
	{
		for (int y = 0; y < inputImage.rows; y++)
		{
			if (inputImage.at<uchar>(y, x) > thresholdValue)
				outputImage.at<uchar>(y, x) = static_cast<uchar>(0);
			else
				outputImage.at<uchar>(y, x) = static_cast<uchar>(255);
		}
	}
    return outputImage;
}

cv::Mat truncatedThreshold(cv::Mat inputImage, int thresholdValue)
{
	cv::Mat outputImage;
	cv::cvtColor(inputImage, outputImage, cv::COLOR_BGR2GRAY);

	for (int x = 0; x < inputImage.cols; x++)
	{
		for (int y = 0; y < inputImage.rows; y++)
		{
			if (inputImage.at<uchar>(y, x) > thresholdValue)
				outputImage.at<uchar>(y, x) = static_cast<uchar>(thresholdValue);
			else
				outputImage.at<uchar>(y, x) = inputImage.at<uchar>(y, x);
		}
	}

    return outputImage;
}

cv::Mat toZeroThreshold(cv::Mat inputImage, int thresholdValue)
{
	cv::Mat outputImage;
	cv::cvtColor(inputImage, outputImage, cv::COLOR_BGR2GRAY);

	for (int x = 0; x < inputImage.cols; x++)
	{
		for (int y = 0; y < inputImage.rows; y++)
		{
			if (inputImage.at<uchar>(y, x) > thresholdValue)
				outputImage.at<uchar>(y, x) = inputImage.at<uchar>(y, x);
			else
				outputImage.at<uchar>(y, x) = static_cast<uchar>(0);
		}
	}

    return outputImage;
}

cv::Mat toZeroInverseThreshold(cv::Mat inputImage, int thresholdValue)
{
	cv::Mat outputImage;
	cv::cvtColor(inputImage, outputImage, cv::COLOR_BGR2GRAY);

	for (int x = 0; x < inputImage.cols; x++)
	{
		for (int y = 0; y < inputImage.rows; y++)
		{
			if (inputImage.at<uchar>(y, x) > thresholdValue)
				outputImage.at<uchar>(y, x) = static_cast<uchar>(0);
			else
				outputImage.at<uchar>(y, x) = inputImage.at<uchar>(y, x);
		}
	}

    return outputImage;
}
