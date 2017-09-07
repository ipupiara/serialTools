#include "stdafx.h"
#include "CSerial.h"


CSerial::CSerial(){
};


CSerial::~CSerial(){
};



BOOL CSerial::Open_port(System::String ^  commPort)
{
	try {
		Configure_port(commPort);
		_serialPort->Open();
	} catch ( Exception^ ex1) {
	}

	return true;
}
//*****************************************************

BOOL CSerial::Configure_port(System::String ^  commPort)
{

	 _serialPort = gcnew SerialPort();

	// Allow the user to set the appropriate properties.
	_serialPort->PortName = "COM1";
	_serialPort-> BaudRate = 9600;
	_serialPort->Parity =  Parity::None;
	_serialPort->DataBits =  8;
	_serialPort->StopBits =  StopBits::None  ;
	_serialPort->Handshake =  Handshake::None;

	// Set the read/write timeouts
	_serialPort->ReadTimeout = 500;
	_serialPort->WriteTimeout = 500;





	//COMMTIMEOUTS touts;

 //   if (! GetCommTimeouts(hComm, &touts) )	{
	//	MessageBox(NULL,"GetCommTimeout Error","Error",MB_OK+MB_ICONERROR);
	//	CloseHandle(hComm);
	//	return false;
	//}

	//touts.ReadTotalTimeoutConstant = GBSerialReadTotalTimeoutConstant;
	//touts.ReadIntervalTimeout = GBReadIntervalTimeout;
 //   if (! SetCommTimeouts(hComm, &touts) )	{
	//	MessageBox(NULL,"SetCommTimeout Error","Error",MB_OK+MB_ICONERROR);
	//	CloseHandle(hComm);
	//	return false;
	//}

 return true;
}
//**************************************************
/*
BOOL CSerial::Write_port(void)
{
 iBytesWritten=0;
 if(WriteFile(hComm,&Byte2Write,1,&iBytesWritten,NULL)==0)
 return false;
 else return true;
}*/

//***************************************************

//BOOL CSerial::Read_port( void* lpBuffer, DWORD len, DWORD* dwBytesTransferred)
//{
////	return ReadFile (hComm, lpBuffer, len, dwBytesTransferred, 0);
// // return value will not actually be used and does not make much sense anyhow  ????
//	return 0;
//}

//**************************************************

//BOOL CSerial::Close_port(void)
//{
//// CloseHandle(hComm);
// return true;
//}
//*************************************************
// main function 