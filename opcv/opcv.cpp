#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;
using namespace cv;

#include "SerialPortReader.h"

#define BLOCK_SIZE 100



void DrawABlock(Mat *img, int heat, int no) {
	
	int X = (no%4)*110;
	int Y = (no/4)*110;
	//cout << "NO  " << no << "   " << X << "   " << Y << "    " << heat << endl;
	Rect r(X, Y, BLOCK_SIZE, BLOCK_SIZE);
	if (heat < 255 && heat>0)
	{
		rectangle(*img, r, Scalar(0, heat, 255 - heat), -1);
		imshow("Rainging", *img);
		waitKey(1);
	}
	else
	{
		rectangle(*img, r, Scalar(0, 255, 0), -1);
		imshow("Rainging", *img);
		waitKey(1);
	}
	
	
}


void SetMultiRangingData(string data, Mat *img)
{
	string::size_type begin = 0;
	string::size_type end = string::npos;
	string comma = ",";
	vector<string> vdata;

	end = data.find(comma);

	while (end != string::npos)			//�P�_���O�̫�@�Ӧ줸
	{
		vdata.push_back(data.substr(begin, end - begin));		//����
		begin = end + comma.size();		 //���ܶ}�l�M�䪺��m
		end = data.find(comma, begin);		//��"�A"
	}
	vdata.push_back(data.substr(begin));
	
	
	//cout << stoi(vdata[0]) << endl;
	DrawABlock(img, 255 * stoi(vdata[2]) / 2000, stoi(vdata[0]));
}

void stringToData(char c, string *data, Mat *img)
{
	*data += c;
	if (c == 10)
	{
		SetMultiRangingData(*data, img);
		*data = "";
		
	}
}

int main()
{
	Mat img = Mat::zeros(Size(430, 430), CV_8UC3);
	string readerDataStr = "";
	SerialPortReader spr(115200);

	img.setTo(255);              // 设置屏幕为白色
	

	while (true) {
		stringToData(spr.GetChar(), &readerDataStr, &img);
	}

	return 0;
}
