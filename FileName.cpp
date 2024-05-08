// **********************************************
// �� �� : �ǽ�����1
// �� ¥ : 2024�� 5��8��
// �ۼ��� : 2001237 �Ѽ���
// **********************************************
/*
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main() 
{
	Mat morphRect = getStructuringElement(MORPH_RECT, Size(3, 3));
	cout << "MORPH_RECT" << endl;
	cout << morphRect << endl;

	Mat morphCross = getStructuringElement(MORPH_CROSS, Size(3, 3));
	cout << "MORPH_CROSS" << endl;
	cout << morphCross << endl;

	Mat morphEllipse = getStructuringElement(MORPH_ELLIPSE, Size(5, 3));
	cout << "MORPH_ELLIPSE" << endl;
	cout << morphEllipse << endl;
	return 0;
}
*/

// **********************************************
// �� �� : �ǽ�����2
// �� ¥ : 2024�� 5��8��
// �ۼ��� : 2001237 �Ѽ���
// **********************************************
/*
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main(void) 
{
	Mat src = imread("letterj.png", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return-1; }
	Mat bin;
	threshold(src, bin, 0, 255, THRESH_BINARY | THRESH_OTSU);
	Mat dst1, dst2;
	erode(bin, dst1, Mat());
	dilate(dst1, dst2, Mat());
	imshow("src", src);
	imshow("bin", bin);
	imshow("erode", dst2);
	waitKey();
	return 0;
}
*/

// **********************************************
// �� �� : �ǽ�����3
// �� ¥ : 2024�� 5��8��
// �ۼ��� : 2001237 �Ѽ���
// **********************************************
/*
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main(void) 
{
	Mat src = imread("letterj2.png", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return-1; }
	Mat bin;
	threshold(src, bin, 0, 255, THRESH_BINARY | THRESH_OTSU);
	Mat dx, dy;
	Sobel(bin, dx, CV_32FC1, 1, 0);
	Sobel(bin, dy, CV_32FC1, 0, 1);
	Mat fmag, mag;
	magnitude(dx, dy, fmag);
	fmag.convertTo(mag, CV_8UC1);
	Mat edge = mag > 150;;
	imshow("src", src);
	imshow("bin", bin);
	imshow("edge", edge);
	waitKey();
	return 0;
}
*/

// **********************************************
// �� �� : �ǽ�����4
// �� ¥ : 2024�� 5��8��
// �ۼ��� : 2001237 �Ѽ���
// **********************************************
/*
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main(void) 
{
	Mat src1 = imread("car.png", IMREAD_COLOR);
	if (src1.empty()) { cerr << "Image load failed!" << endl; return-1; }
	Mat src = imread("car.png", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return-1; }
	Mat dst, dx, dx1;
	blur(src, dst, Size(5, 5));
	Sobel(dst, dx, CV_32FC1, 1, 0);
	dx.convertTo(dx1, CV_8UC1);
	Mat bin, dst1;
	threshold(dx1, bin, 105, 255, THRESH_BINARY);
	morphologyEx(bin, dst1, MORPH_CLOSE, getStructuringElement(MORPH_RECT, Size(32, 5)));
	imshow("image", src1);
	imshow("x����� �Һ�", dx1);
	imshow("����ȭ ����", bin);
	imshow("���� ����", dst1);
	waitKey();
	return 0;
}
*/