#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main() {
	Mat src = imread("C:\\Users\\wangh\\Pictures\\103.bmp");//利用imread读取图片路径
	if (src.empty()) {
		cout << "no image here！！！";
	}
	namedWindow("first openCV exercise", WINDOW_AUTOSIZE);//创建一个窗口，自动大小不可人为改变
	imshow("test opencv setup", src);//窗口显示图片
	namedWindow("output windows", WINDOW_AUTOSIZE);//第一参数窗口名称
	Mat output_image;
	cvtColor(src, output_image, COLOR_BGR2GRAY);//转换通道，显示灰度值图片
	imshow("output windows", output_image);
	imwrite("C:\\Users\\wangh\\Pictures\\103_2.bmp", output_image);
	waitKey(0);//不限时等待

	return 0;
}