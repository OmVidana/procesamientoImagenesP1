#include "HistogramImage.h"

HistogramDisplayer::HistogramDisplayer(std::string pathFile)
{
    setHistogram(256, 0);
    setWindowName("HistogramDisplayer");
    setInputImage(pathFile);
    fillHistogram();
    createHistogramImage();
}

void HistogramDisplayer::setWindowName(std::string name) {
    windowName = name;
}

void HistogramDisplayer::setInputImage(std::string path) {
    inputImage = cv::imread(path, cv::IMREAD_GRAYSCALE);

    if (inputImage.empty()) {
        std::cerr << "Could not open or find the image. Creating a black image..." << "\n";
        inputImage.create(500, 500, CV_8U);
        inputImage.setTo(cv::Scalar(0));
    }
}

void HistogramDisplayer::fillHistogram() {
    for (int x = 0; x < inputImage.cols; x++)
    {
        for (int y = 0; y < inputImage.rows; y++)
        {
            uchar* rowPtr = inputImage.ptr<uchar>(y);
            uchar& pixel = rowPtr[x];

            histogram[pixel]++;
        }
    }
}

void HistogramDisplayer::createHistogramImage() {
    histogramImage.create(512, histogram.size(), CV_8U);
    histogramImage.setTo(cv::Scalar(0));
    
    int maxHeight = *std::max_element(histogram.begin(), histogram.end());
    double scale = static_cast<double>(histogramImage.rows) / maxHeight;

    for (int i = 0; i < histogram.size(); i++) {
        int heightLine = static_cast<int>(histogram[i] * scale);
        cv::line(histogramImage, cv::Point(i, histogramImage.rows), cv::Point(i, histogramImage.rows - heightLine), cv::Scalar(255));
    }
}

cv::Mat HistogramDisplayer::getHistogramImage() {
    return histogramImage;
}

void HistogramDisplayer::displayInputImage() {
    cv::namedWindow(windowName, cv::WINDOW_NORMAL);

    cv::imshow(windowName, inputImage);
    cv::waitKey(0);
}

void HistogramDisplayer::displayHistogramImage() {
    setWindowName("Histogram");

    cv::namedWindow(windowName, cv::WINDOW_NORMAL);

    cv::imshow(windowName, getHistogramImage());
    cv::waitKey(0);
}

void HistogramDisplayer::closeHistogramDisplayer() {
    inputImage.deallocate();
    getHistogramImage().deallocate();
    cv::destroyAllWindows();
}

void HistogramDisplayer::setHistogram(int size, int fill) {
    histogram = std::vector<int>(256, 0);
}
