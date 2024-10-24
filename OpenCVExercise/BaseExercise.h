#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

class BaseExercise
{
public:
	int showImage(Mat image);
	int testErode(Mat image);
	int testBlur(Mat image);
	int testCanny(Mat image);
	int testWindow(Mat image1, Mat image2);
	int testVideoCapture();
	int testVideoAndCanny();
};

