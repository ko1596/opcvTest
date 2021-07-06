#include <iostream>
#include <Windows.h>
#include "SerialPort.h"

using namespace std;

int main() {
	CSerialPort mySerialPort();

	if (!mySerialPort().InitPort(5))
	{
		std::cout << "initPort fail !" << std::endl;
	}
	else
	{
		std::cout << "initPort success !" << std::endl;
	}


	if (!mySerialPort().OpenListenThread())
	{
		std::cout << "OpenListenThread fail !" << std::endl;
	}
	else
	{
		std::cout << "OpenListenThread success !" << std::endl;
	}
}