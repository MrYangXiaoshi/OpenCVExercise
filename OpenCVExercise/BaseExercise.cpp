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

int BaseExercise::testWindow(Mat image1, Mat image2)
{
	// Read images
	Mat lena = image1;
	Mat photo = image2;

	// Create windows
	namedWindow("Lena", WINDOW_NORMAL);
	// Checking if Lena image has been loaded
	if (!lena.data) {
		cout << "Lena image missing!" << endl;
		return -1;
	}
	namedWindow("Photo", WINDOW_AUTOSIZE);
	if (!photo.data) {
		cout << "Lena image missing!" << endl;
		return -1;
	}
	// Move window
	// moveWindow函数将窗口移动到桌面的任何区域
	moveWindow("Lena", 10, 10);
	moveWindow("Photo", 520, 10);

	// show images
	imshow("Lena", lena);
	imshow("Photo", photo);

	// Resize window, only non autosize
	// resizeWindow函数将Lena窗口的大小调整为512像素，该函数有三个参
	// 数：window name、width和height。
	resizeWindow("Lena", 512, 512);

	// wait for any key press
	waitKey(0);

	// Destroy the windows
	destroyWindow("Lena");
	destroyWindow("Photo");

	// Create 10 windows
	for (int i = 0; i < 10; i++)
	{
		ostringstream ss;
		ss << "Photo " << i;
		namedWindow(ss.str());
		moveWindow(ss.str(), 20 * i, 20 * i);
		imshow(ss.str(), photo);
	}

	waitKey(0);
	// Destroy all windows
	destroyAllWindows();
	return 0;
}

int BaseExercise::testVideoCapture()
{
	VideoCapture capture("./mt03.mp4");	// 读入视频
	//VideoCapture capture(0);	// 从摄像头读入视频
	if (!capture.isOpened())	// 判断文件是否正确打开
	{
		std::cout << "video not exist";
		return -1;
	}

	while (1) // 循环显示每一帧
	{
		Mat frame;	// 定义一个Mat 变量， 用于存储每一帧的图像
		capture >> frame;	// 读取当前帧到 Mat 变量中 
		imshow("读取视频", frame);	// 显示当前帧 
		waitKey(1000);	// 延时 1000 ms
	}
	capture.release();	//释放资源
	return 0;
}

int BaseExercise::testVideoAndCanny()
{
	VideoCapture capture("./mt03.mp4");	// 读入视频
	//VideoCapture capture(0);	// 从摄像头读入视频
	if (!capture.isOpened())	// 判断文件是否正确打开
	{
		std::cout << "video not exist";
		return -1;
	}

	Mat edges;
	while (1) // 循环显示每一帧
	{
		Mat frame;	// 定义一个Mat 变量， 用于存储每一帧的图像
		capture >> frame;	// 读取当前帧到 Mat 变量中 
		cvtColor(frame, edges, COLOR_BGR2GRAY); // 转换 BGR 图为灰度图
		// 使用 3x3 内核降噪 2x3+1=7
		blur(edges, edges, Size(7, 7)); // 进行模糊
		// 进行 canny 边缘检测并显示
		Canny(edges, edges, 0, 30, 3);
		imshow("边缘检测并模糊后的视频", edges);	// 显示当前帧 
		waitKey(1000);	// 延时 1000 ms
	}
	capture.release();	//释放资源
	return 0;
}
