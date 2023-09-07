#include "OpenImage.h"

cv::Mat createImage(int width, int height, int type)
{
	return cv::Mat(height, width, type);
}

std::pair<cv::Mat, std::string> readImage(std::string path)
{
	std::string fileName = std::filesystem::path(path).filename().string();
	cv::Mat image;

	if (std::filesystem::exists(path))
	{
		image = cv::imread(path);

		if (image.empty())
		{
			std::cerr << "Error: Couldn't load the Image. Returning an empty Mat." << std::endl;
			return std::make_pair(cv::Mat(), "No Image");
		}

		return std::make_pair(image, fileName);
	}

	std::cerr << "Error: File not found." << std::endl;

	return std::make_pair(cv::Mat(), "No Image");
}

int openImage(cv::Mat inputImage, std::string fileName, double scale, int waitTime) {
	cv::namedWindow(fileName, cv::WINDOW_NORMAL);

	if (inputImage.empty())
	{
		std::cerr << "There is no Image to load." << std::endl;
		return -1;
	}
	cv::resizeWindow(fileName, static_cast<int>(inputImage.cols * scale), static_cast<int>(inputImage.rows * scale));
	cv::imshow(fileName, inputImage);
	cv::waitKey(waitTime);

	//inputImage.deallocate();
	//cv::destroyWindow(fileName);

	return 0;
}
