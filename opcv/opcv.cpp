#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	namedWindow("a", 1);
	moveWindow("a", 0, 0);
	Mat pic = imread("pic.jpg", 1);
	imshow("a", pic);
	waitKey(0);
	destroyAllWindows();
	system("pause");
	return 0;
}
