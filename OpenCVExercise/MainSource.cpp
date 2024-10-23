#include <opencv2/opencv.hpp>
#include <iostream>
#include "BaseExercise.h"

using namespace std;
using namespace cv;
int main() {
	BaseExercise* baseExercise = new BaseExercise();
	baseExercise->showImge();

	return 0;
}