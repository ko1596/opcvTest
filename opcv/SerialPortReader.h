#pragma once
#ifndef SERIALPORTREADER_H
#define SERIALPORTREADER_H
#include <Windows.h>
#include <string>
#include <iostream>
using namespace std;
class SerialPortReader
{
public:
	SerialPortReader(int bitRate);
	char GetChar();
	void CloseCom();
private:
	HANDLE _hCom;
	COMMTIMEOUTS TimeOuts;
	DCB dcb;
	DWORD wCount;
	char c[1];

	void SetTimeOuts();
	void SetSerialPort(int);
	bool BReadStat();
};

#endif // !SERIALPORTREADER_H
