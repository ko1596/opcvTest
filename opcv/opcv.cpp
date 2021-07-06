#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <Windows.h>

using namespace std;
using namespace cv;
int i = 0;

HANDLE hCom;

void DrawABlock(Mat *img,int heat) {
	Rect r(250, 250, 250, 250);
	rectangle(*img, r, Scalar(0, 0, heat), -1);

	imshow("画板", *img);
	waitKey(10);
}

int main()
{
	Mat img = Mat::zeros(Size(800, 600), CV_8UC3);
	hCom = CreateFile(TEXT("com5"),//set COM5
		GENERIC_READ, //allow read
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (hCom == INVALID_HANDLE_VALUE)
	{
		printf("open COM unsucessus!\n");
		return FALSE;
	}
	else
	{
		printf("open COM sucessused!\n");
	}

	SetupComm(hCom, 1024, 1024); //input and outputbuffer

	/*********************************setting time out**************************************/
	COMMTIMEOUTS TimeOuts;

	TimeOuts.ReadIntervalTimeout = MAXDWORD;
	TimeOuts.ReadTotalTimeoutMultiplier = 1;
	TimeOuts.ReadTotalTimeoutConstant = 1;

	TimeOuts.WriteTotalTimeoutMultiplier = 1;
	TimeOuts.WriteTotalTimeoutConstant = 1;
	SetCommTimeouts(hCom, &TimeOuts);

	/*****************************************setting Serial Port***************************/
	DCB dcb;
	GetCommState(hCom, &dcb);
	dcb.BaudRate = 115200; //set bit rate to 115200
	dcb.ByteSize = 8; //set byte size
	dcb.Parity = NOPARITY; //set parity
	dcb.StopBits = ONESTOPBIT; //set stop bit
	SetCommState(hCom, &dcb);

	DWORD wCount;//the real byte size
	boolean bReadStat;

	char str[1];
	String distance="";
	int buffer = 0, picClor = 0;
	img.setTo(255);              // 设置屏幕为白色
	while (true) {
		
		bReadStat = ReadFile(hCom, str, sizeof(str), &wCount, NULL);

		if (!bReadStat)
		{
			printf("read COM fail!");
		}
		else
		{
			//printf("%c", str[0]);
			if (isdigit(str[0]))
			{
				distance += str[0];
			}
			else
			{
				if (distance != "")
				{
					buffer = stoi(distance);
					cout << buffer << endl;
					picClor = 255 * buffer / 2000;
					DrawABlock(&img, picClor);
				}
				distance = "";
			}
			//DrawABlock(&img);
		}
	}

	CloseHandle(hCom);

	return 0;
}
