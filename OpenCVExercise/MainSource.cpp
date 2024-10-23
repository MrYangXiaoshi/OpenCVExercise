#include <opencv2/opencv.hpp>
#include <iostream>
#include "BaseExercise.h"

using namespace std;
using namespace cv;
int main() {
	Mat image = imread("./test.jpg");
	Mat image2 = imread("./test.jpg");
	BaseExercise* baseExercise = new BaseExercise();

	//baseExercise->showImage(image);
	//baseExercise->testErode(image);
	//baseExercise->testBlur(image);
	//baseExercise->testCanny(image);
	baseExercise->testWindow(image, image2);

	return 0;
}