#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <ctime> 
#include <Windows.h>

using namespace std;
using namespace cv;
int i = 0;

void DrawABlock(Mat *img) {
	Rect r(250, 250, 250, 250);
	rectangle(*img, r, Scalar(0, 0, i), -1);
	if (i > 254) i = 0;
	else i++;
	imshow("画板", *img);
	waitKey(10);
}

int main()
{
	Mat img = Mat::zeros(Size(800, 600), CV_8UC3);
	img.setTo(255);              // 设置屏幕为白色
	
	while (true) DrawABlock(&img);
	
	return 0;
}
