#include "ImageManipulation.h"

cv::Mat addTwoImages(cv::Mat firstImage, cv::Mat secondImage)
{
    cv::Mat outputImage(std::min(firstImage.rows, secondImage.rows), std::min(firstImage.cols, secondImage.cols), CV_8U);

    for (int x = 0; x < outputImage.cols; x++)
    {
        for (int y = 0; y < outputImage.rows; y++)
        {
            uchar addition = (firstImage.at<uchar>(y, x) + secondImage.at<uchar>(y, x)) / 2;
            outputImage.at<uchar>(y, x) = addition;
        }
    }
    return outputImage;
}

cv::Mat addTwoImages(cv::Mat firstImage, cv::Mat secondImage, double w1, double w2)
{   
    cv::Mat outputImage(std::min(firstImage.rows, secondImage.rows), std::min(firstImage.cols, secondImage.cols), CV_8U);

    for (int x = 0; x < outputImage.cols; x++)
    {
        for (int y = 0; y < outputImage.rows; y++)
        {
            int pImg1 = static_cast<int>(firstImage.at<uchar>(y, x));
            int pImg2 = static_cast<int>(secondImage.at<uchar>(y, x));
            outputImage.at<uchar>(y, x) = static_cast<uchar>(w1 * pImg1 + w2 * pImg2);
        }
    }
    return outputImage;
}

cv::Mat addConstant(cv::Mat inputImage, int addition)
{
    cv::Mat outputImage(inputImage.rows, inputImage.cols, CV_8U);

    for (int x = 0; x < outputImage.cols; x++)
    {
        for (int y = 0; y < outputImage.rows; y++)
        {
            uchar constAddition = std::max(0, std::min(255, static_cast<int>(inputImage.at<uchar>(y, x)) + addition));
            outputImage.at<uchar>(y, x) = constAddition;
        }
    }
    return outputImage;
}

cv::Mat addFunction(cv::Mat inputImage)
{
    cv::Mat outputImage(inputImage.rows, inputImage.cols, CV_8U);

    for (int x = 0; x < outputImage.cols; x++)
    {
        float intensity = (float)((x + 1) * 255) / outputImage.cols;
        float inverseIntensity = 255 - intensity;

        for (int y = 0; y < outputImage.rows; y++)
        {
            uchar functionAdded = std::max(0, std::min(255, static_cast<int>(inputImage.at<uchar>(y, x) - intensity)));
            outputImage.at<uchar>(y, x) = functionAdded;
        }
    }
    return outputImage;
}

cv::Mat verticalAddition(cv::Mat firstImage, cv::Mat secondImage, float w1, float w2)
{
    cv::Mat outputImage(std::min(firstImage.rows, secondImage.rows), std::min(firstImage.cols, secondImage.cols), CV_8U);
    for (int y = 0; y < outputImage.rows; y++)
    {
        float intensity = (float)(y + 1) / outputImage.cols;
        float inverseIntensity = 1 - intensity;
        float newW1 = w1 * intensity;
        float newW2 = w2 * inverseIntensity;

        for (int x = 0; x < outputImage.cols; x++)
        {
            int pImg1 = static_cast<int>(firstImage.at<uchar>(y, x));
            int pImg2 = static_cast<int>(secondImage.at<uchar>(y, x));

            //std::cout << pImg1 << " | " << pImg2 << " | " << w1 * pImg1 + w2 * pImg2 << "\n";

            uchar merged = static_cast<uchar>(newW1 * pImg1 + newW2 * pImg2);
            outputImage.at<uchar>(y, x) = merged;
        }
    }
    return outputImage;
}

cv::Mat horizontalAddition(cv::Mat firstImage, cv::Mat secondImage, float w1, float w2)
{
    cv::Mat outputImage(std::min(firstImage.rows, secondImage.rows), std::min(firstImage.cols, secondImage.cols), CV_8U);
    for (int x = 0; x < outputImage.cols; x++)
    {
        float intensity = (float)(x + 1) / outputImage.cols;
        float inverseIntensity = 1 - intensity;
        float newW1 = w1 * intensity;
        float newW2 = w2 * inverseIntensity;

        for (int y = 0; y < outputImage.rows; y++)
        {
            int pImg1 = static_cast<int>(firstImage.at<uchar>(y, x));
            int pImg2 = static_cast<int>(secondImage.at<uchar>(y, x));

            //std::cout << pImg1 << " | " << pImg2 << " | " << w1 * pImg1 + w2 * pImg2 << "\n";

            uchar merged = static_cast<uchar>(newW1 * pImg1 + newW2 * pImg2);
            outputImage.at<uchar>(y, x) = merged;
        }
    }
    return outputImage;
}

cv::Mat substractTwoImages(cv::Mat firstImage, cv::Mat secondImage)
{
    cv::Mat outputImage(std::min(firstImage.rows, secondImage.rows), std::min(firstImage.cols, secondImage.cols), CV_8U);

    for (int x = 0; x < outputImage.cols; x++)
    {
        for (int y = 0; y < outputImage.rows; y++)
        {
            int pImg1 = static_cast<int>(firstImage.at<uchar>(y, x));
            int pImg2 = static_cast<int>(secondImage.at<uchar>(y, x));
            uchar substractionPixel = std::max(0, pImg1 - pImg2);
            outputImage.at<uchar>(y, x) = substractionPixel;
        }
    }
    return outputImage;
}

cv::Mat inverse(cv::Mat inputImage)
{
    cv::Mat outputImage(inputImage.rows, inputImage.cols, CV_8U);

    for (int x = 0; x < outputImage.cols; x++)
    {
        for (int y = 0; y < outputImage.rows; y++)
        {
            uchar inverse = 256 - inputImage.at<uchar>(y, x);
            outputImage.at<uchar>(y, x) = inverse;
        }
    }
    return outputImage;
}
