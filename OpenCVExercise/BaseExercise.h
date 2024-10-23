#pragma once
#include "opencv2/opencv.hpp"

using namespace cv;

class BaseExercise
{
public:
	int showImage(Mat image);
	int testErode(Mat image);
	int testBlur(Mat image);
	int testCanny(Mat image);
};

