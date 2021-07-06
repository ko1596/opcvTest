#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <ctime> 

using namespace std;
using namespace cv;

void   Delay(int   time)//time*1000為秒數 
{
	clock_t   now = clock();

	while (clock() - now < time);
}

int main()
{
	// 设置窗口
		Mat img = Mat::zeros(Size(800, 600), CV_8UC3);

	img.setTo(255);              // 设置屏幕为白色
	
	// 画矩形
	Rect r(250, 250, 250, 250);
	//rectangle(img, r, Scalar(0, 255, 255), 3);
	int i = 0;

	while (true)
	{
		rectangle(img, r, Scalar(0, 0, i), -1);
		if (i > 254) i = 0;
		else i++;
		imshow("画板", img);
		waitKey(10);
	}
	waitKey();
	return 0;
}
