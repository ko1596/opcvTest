#include "SerialPortReader.h"


SerialPortReader::SerialPortReader(int bitRate)
{
	this->_hCom =	CreateFile(TEXT("com5"),//set COM5
					GENERIC_READ, //allow read
					0,
					NULL,
					OPEN_EXISTING,
					FILE_ATTRIBUTE_NORMAL,
					NULL);

	if (_hCom == INVALID_HANDLE_VALUE) throw invalid_argument("INVALID_HANDLE_VALUE");
	else cout << "open COM sucessused!" << endl;

	SetupComm(_hCom, 1024, 1024); //input and outputbuffer
	SetTimeOuts();
	SetSerialPort(bitRate);
}

char SerialPortReader::GetChar()
{
	if(!BReadStat()) throw invalid_argument("read COM fail!");
	else return c[0];
}

void SerialPortReader::CloseCom()
{
	CloseHandle(_hCom);
}

void SerialPortReader::SetTimeOuts()
{
	TimeOuts.ReadIntervalTimeout = MAXDWORD;
	TimeOuts.ReadTotalTimeoutMultiplier = 1;
	TimeOuts.ReadTotalTimeoutConstant = 50;

	TimeOuts.WriteTotalTimeoutMultiplier = 1;
	TimeOuts.WriteTotalTimeoutConstant = 1;
	SetCommTimeouts(_hCom, &TimeOuts);
}
void SerialPortReader::SetSerialPort(int bitRate)
{
	GetCommState(_hCom, &dcb);
	dcb.BaudRate = bitRate; //set bit rate to 115200
	dcb.ByteSize = 8; //set byte size
	dcb.Parity = NOPARITY; //set parity
	dcb.StopBits = ONESTOPBIT; //set stop bit
	SetCommState(_hCom, &dcb);
}
bool SerialPortReader::BReadStat()
{
	return ReadFile(_hCom, c, sizeof(c), &wCount, NULL);
}

