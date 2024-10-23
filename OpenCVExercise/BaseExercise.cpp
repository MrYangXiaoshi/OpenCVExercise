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

int BaseExercise::testCanny(Mat image)
{
	if (image.empty())	// 或者 if(!image.data) 判断图片是否加载成功
	{
		std::cout << "image not exist";
		return -1;
	}
	imshow("原始图片", image);	// 显示图像

	Mat dst, edge, gray;
	// 创建与原图片同类型和大小的矩阵（ dst )
	dst.create(image.size(), image.type());

	// 将原图像转换为灰度图像 OpenCV2 版本
	// cvtColor(src, gray, CV_BGR2GRAY)
	// OpenCV3 或者 OpenCV4 版本
	cvtColor(image, gray, COLOR_BGR2GRAY);
	// 先使用5 x 5 内核来降噪
	blur(gray, edge, Size(5, 5));
	// 运行Canny 算子
	Canny(edge, edge, 1, 3, 3);
	imshow("Canny 边缘检测", edge);
	imwrite("canny.jpg", edge);
	waitKey(0);	// 等待任意按键按下，退出图片显示
}
