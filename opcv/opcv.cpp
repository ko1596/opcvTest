#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	// 设置窗口
		Mat img = Mat::zeros(Size(800, 600), CV_8UC3);

	img.setTo(255);              // 设置屏幕为白色
	
	// 画矩形
	Rect r(250, 250, 250, 250);
	//rectangle(img, r, Scalar(0, 255, 255), 3);
	rectangle(img, r, Scalar(0, 0, 255), -1);
	imshow("画板", img);
	waitKey();
	return 0;
}
