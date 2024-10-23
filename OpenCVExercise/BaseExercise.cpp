#include "BaseExercise.h"
#include "opencv2/opencv.hpp"

using namespace cv;

int BaseExercise::showImge()
{
	Mat image;
	image = imread("./test.jpg");	// 载入图像
	if (image.empty())	// 或者 if(!image.data) 判断图片是否加载成功
	{
		std::cout << "image not exist";
		return -1;
	}
	namedWindow("demo 图片");
	imshow("demo 图片", image);	// 显示图像
	imwrite("save.jpg", image);
	waitKey(0);	// 等待任意按键按下，退出图片显示

	return 0;
}
