#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main() {
	Mat src = imread("D:\AAA_project\2023_04_19_15_37_05_641.bmp");
	if (src.empty()) {
		cout << "no image here£¡£¡£¡";
	}


	return 0;
}