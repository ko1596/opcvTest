#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;
using namespace cv;

#include "SerialPortReader.h"

#define BLOCK_SIZE 250
HANDLE hCom;

/** @defgroup VL53L1_define_RoiStatus_group Defines Roi Status
 *  Defines the read status mode
 *  @{
 */
typedef uint8_t VL53L1_RoiStatus;

#define VL53L1_ROISTATUS_NOT_VALID                 ((VL53L1_RoiStatus)  0)
#define VL53L1_ROISTATUS_VALID_NOT_LAST            ((VL53L1_RoiStatus)  1)
#define VL53L1_ROISTATUS_VALID_LAST                ((VL53L1_RoiStatus)  2)
/** @} VL53L1_define_RoiStatus_group */

typedef struct {
	uint8_t RoiNumber;
	VL53L1_RoiStatus RoiStatus;
	int16_t RangeMilliMeter;
}VL53L1_MultiRangingData_t;

void DrawABlock(Mat *img, int heat, int X, int Y) {
	Rect r(BLOCK_SIZE, BLOCK_SIZE, X, Y);
	rectangle(*img, r, Scalar(0, 255 - heat, heat), -1);
	imshow("Rainging", *img);
	waitKey(10);
}

void stringToData(char c, VL53L1_MultiRangingData_t *md[])
{

}

int main()
{
	Mat img = Mat::zeros(Size(800, 600), CV_8UC3);
	SerialPortReader spr(115200);
	VL53L1_MultiRangingData_t MultiRangingData[16];
	VL53L1_MultiRangingData_t *pMultiRangingData = &MultiRangingData[16];
	img.setTo(255);              // 设置屏幕为白色
	while (true) {
		stringToData(spr.GetChar(), &pMultiRangingData);
	}

	return 0;
}
