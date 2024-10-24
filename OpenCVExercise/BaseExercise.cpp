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

int BaseExercise::testCanny(Mat image)
{
	if (image.empty())	// ���� if(!image.data) �ж�ͼƬ�Ƿ���سɹ�
	{
		std::cout << "image not exist";
		return -1;
	}
	imshow("ԭʼͼƬ", image);	// ��ʾͼ��

	Mat dst, edge, gray;
	// ������ԭͼƬͬ���ͺʹ�С�ľ��� dst )
	dst.create(image.size(), image.type());

	// ��ԭͼ��ת��Ϊ�Ҷ�ͼ�� OpenCV2 �汾
	// cvtColor(src, gray, CV_BGR2GRAY)
	// OpenCV3 ���� OpenCV4 �汾
	cvtColor(image, gray, COLOR_BGR2GRAY);
	// ��ʹ��5 x 5 �ں�������
	blur(gray, edge, Size(5, 5));
	// ����Canny ����
	Canny(edge, edge, 1, 3, 3);
	imshow("Canny ��Ե���", edge);
	imwrite("canny.jpg", edge);
	waitKey(0);	// �ȴ����ⰴ�����£��˳�ͼƬ��ʾ
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
	// moveWindow�����������ƶ���������κ�����
	moveWindow("Lena", 10, 10);
	moveWindow("Photo", 520, 10);

	// show images
	imshow("Lena", lena);
	imshow("Photo", photo);

	// Resize window, only non autosize
	// resizeWindow������Lena���ڵĴ�С����Ϊ512���أ��ú�����������
	// ����window name��width��height��
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
	VideoCapture capture("./mt03.mp4");	// ������Ƶ
	//VideoCapture capture(0);	// ������ͷ������Ƶ
	if (!capture.isOpened())	// �ж��ļ��Ƿ���ȷ��
	{
		std::cout << "video not exist";
		return -1;
	}

	while (1) // ѭ����ʾÿһ֡
	{
		Mat frame;	// ����һ��Mat ������ ���ڴ洢ÿһ֡��ͼ��
		capture >> frame;	// ��ȡ��ǰ֡�� Mat ������ 
		imshow("��ȡ��Ƶ", frame);	// ��ʾ��ǰ֡ 
		waitKey(1000);	// ��ʱ 1000 ms
	}
	capture.release();	//�ͷ���Դ
	return 0;
}

int BaseExercise::testVideoAndCanny()
{
	VideoCapture capture("./mt03.mp4");	// ������Ƶ
	//VideoCapture capture(0);	// ������ͷ������Ƶ
	if (!capture.isOpened())	// �ж��ļ��Ƿ���ȷ��
	{
		std::cout << "video not exist";
		return -1;
	}

	Mat edges;
	while (1) // ѭ����ʾÿһ֡
	{
		Mat frame;	// ����һ��Mat ������ ���ڴ洢ÿһ֡��ͼ��
		capture >> frame;	// ��ȡ��ǰ֡�� Mat ������ 
		cvtColor(frame, edges, COLOR_BGR2GRAY); // ת�� BGR ͼΪ�Ҷ�ͼ
		// ʹ�� 3x3 �ں˽��� 2x3+1=7
		blur(edges, edges, Size(7, 7)); // ����ģ��
		// ���� canny ��Ե��Ⲣ��ʾ
		Canny(edges, edges, 0, 30, 3);
		imshow("��Ե��Ⲣģ�������Ƶ", edges);	// ��ʾ��ǰ֡ 
		waitKey(1000);	// ��ʱ 1000 ms
	}
	capture.release();	//�ͷ���Դ
	return 0;
}
