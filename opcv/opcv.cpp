#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <Windows.h>

using namespace std;
using namespace cv;

#include "SerialPortReader.h"

#define BLOCK_SIZE 250
HANDLE hCom;

void DrawABlock(Mat *img, int heat, int X, int Y) {
	Rect r(BLOCK_SIZE, BLOCK_SIZE, X, Y);
	rectangle(*img, r, Scalar(0, 255 - heat, heat), -1);
	imshow("Rainging", *img);
	waitKey(10);
}

int main()
{
	Mat img = Mat::zeros(Size(800, 600), CV_8UC3);
	SerialPortReader spr(115200);
	String distance="";
	int buffer = 0, picClor = 0;
	img.setTo(255);              // 设置屏幕为白色
	while (true) {
		cout << spr.GetChar();
	}

	

	return 0;
}
