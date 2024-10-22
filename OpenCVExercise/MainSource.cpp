#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main() {
	Mat src = imread("C:\\Users\\wangh\\Pictures\\103.bmp");//����imread��ȡͼƬ·��
	if (src.empty()) {
		cout << "no image here������";
	}
	namedWindow("first openCV exercise", WINDOW_AUTOSIZE);//����һ�����ڣ��Զ���С������Ϊ�ı�
	imshow("test opencv setup", src);//������ʾͼƬ
	namedWindow("output windows", WINDOW_AUTOSIZE);//��һ������������
	Mat output_image;
	cvtColor(src, output_image, COLOR_BGR2GRAY);//ת��ͨ������ʾ�Ҷ�ֵͼƬ
	imshow("output windows", output_image);
	imwrite("C:\\Users\\wangh\\Pictures\\103_2.bmp", output_image);
	waitKey(0);//����ʱ�ȴ�

	return 0;
}