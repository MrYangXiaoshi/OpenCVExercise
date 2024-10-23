#include <opencv2/opencv.hpp>
#include <iostream>
#include "BaseExercise.h"

using namespace std;
using namespace cv;
int main() {
	Mat image = imread("./test.jpg");
	BaseExercise* baseExercise = new BaseExercise();

	//baseExercise->showImage(image);
	//baseExercise->testErode(image);
	//baseExercise->testBlur(image);
	baseExercise->testCanny(image);

	return 0;
}