#include "BaseExercise.h"


using namespace cv;

int BaseExercise::showImage(Mat image)
{
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

int BaseExercise::testErode(Mat image)
{
	if (image.empty())	// 或者 if(!image.data) 判断图片是否加载成功
	{
		std::cout << "image not exist";
		return -1;
	}
	imshow("原始图片", image);	// 显示图像

	// 进行腐蚀操作
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dst;
	erode(image, dst, element);
	imshow("腐蚀图片", dst);

	imwrite("./erode.jpg", dst);
	// waitKey(30)等待30毫秒，以此检查用户是否使用任何键停止应用程序的执行。
	waitKey(0);	// 等待任意按键按下，退出图片显示，
	return 0;
}

int BaseExercise::testBlur(Mat image)
{
	if (image.empty())	// 或者 if(!image.data) 判断图片是否加载成功
	{
		std::cout << "image not exist";
		return -1;
	}
	imshow("原始图片", image);	// 显示图像

	// 进行均值滤波模糊操作
	Mat dst;
	blur(image, dst, Size(15, 15));
	imshow("模糊图片", dst);

	imwrite("blur.jpg", dst);
	waitKey(0);	// 等待任意按键按下，退出图片显示
	return 0;
}
