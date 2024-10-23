#include "BaseExercise.h"
#include "opencv2/opencv.hpp"

using namespace cv;

int BaseExercise::showImge()
{
	Mat image;
	image = imread("./test.jpg");	// ����ͼ��
	if (image.empty())	// ���� if(!image.data) �ж�ͼƬ�Ƿ���سɹ�
	{
		std::cout << "image not exist";
		return -1;
	}
	namedWindow("demo ͼƬ");
	imshow("demo ͼƬ", image);	// ��ʾͼ��
	imwrite("save.jpg", image);
	waitKey(0);	// �ȴ����ⰴ�����£��˳�ͼƬ��ʾ

	return 0;
}
