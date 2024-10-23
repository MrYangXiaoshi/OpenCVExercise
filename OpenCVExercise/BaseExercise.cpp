#include "BaseExercise.h"


using namespace cv;

int BaseExercise::showImage(Mat image)
{
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

int BaseExercise::testErode(Mat image)
{
	if (image.empty())	// ���� if(!image.data) �ж�ͼƬ�Ƿ���سɹ�
	{
		std::cout << "image not exist";
		return -1;
	}
	imshow("ԭʼͼƬ", image);	// ��ʾͼ��

	// ���и�ʴ����
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dst;
	erode(image, dst, element);
	imshow("��ʴͼƬ", dst);

	imwrite("./erode.jpg", dst);
	// waitKey(30)�ȴ�30���룬�Դ˼���û��Ƿ�ʹ���κμ�ֹͣӦ�ó����ִ�С�
	waitKey(0);	// �ȴ����ⰴ�����£��˳�ͼƬ��ʾ��
	return 0;
}

int BaseExercise::testBlur(Mat image)
{
	if (image.empty())	// ���� if(!image.data) �ж�ͼƬ�Ƿ���سɹ�
	{
		std::cout << "image not exist";
		return -1;
	}
	imshow("ԭʼͼƬ", image);	// ��ʾͼ��

	// ���о�ֵ�˲�ģ������
	Mat dst;
	blur(image, dst, Size(15, 15));
	imshow("ģ��ͼƬ", dst);

	imwrite("blur.jpg", dst);
	waitKey(0);	// �ȴ����ⰴ�����£��˳�ͼƬ��ʾ
	return 0;
}
