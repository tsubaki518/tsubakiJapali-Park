//---------------------------------------------------------
//
//	File  : BalanceBoardInput.h
//	Detail: �o�����X�{�[�h�f�o�C�X�擾�A���͎擾
//	Author: Hiroaki Nishiyama
//	Data  : 2020/01/26
//
//---------------------------------------------------------
//	2020/01/26 : �쐬�ALED����͖�����
//
//---------------------------------------------------------
#ifndef _BALANCEBOARDINPUT_H_
#define _BALANCEBOARDINPUT_H_

#include <windows.h>
#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <string.h>
#include <SetupApi.h>
#include "hidsdi.h"


#pragma comment(lib, "BluetoothAPIs.lib")
#pragma comment(lib, "SetupApi.lib")
#pragma comment(lib, "hid.lib")
//����4�̊֐���DLL�ɏ����o���܂�

#define MAXREPORTSIZE (256)

#define BALANCEBOARD_1P (0)
#define BALANCEBOARD_2P (1)

#define BALANCEBOARD_RF (0)
#define BALANCEBOARD_RB (1)
#define BALANCEBOARD_LF (2)
#define BALANCEBOARD_LB (3)

typedef struct {
	HANDLE hRsDevHandle = NULL;
	int		InputLength, OutputLength;
	unsigned char	InputReport[MAXREPORTSIZE];
	unsigned char	OutputReport[MAXREPORTSIZE];

	unsigned char	button1, button2;
	//�P�ʂ�10g
	int				Brf, Brb, Blf, Blb;
	int				Mrf_old, Mrb_old, Mlf_old, Mlb_old;
	int				Mrf, Mrb, Mlf, Mlb, Msum;
	int				Brf_offset, Brb_offset, Blf_offset, Blb_offset;
}BALANCEBOARD;


void BalanceBoard_Initialize(void);
void BalanceBoard_Finalize(void);
void BalanceBoard_Update(void);
void BalanceBoard_Reset(void);

bool BalanceBoard_isPress(int num, int key);
bool BalanceBoard_isTrigger(int num, int key);
bool BalanceBoard_isRelease(int num, int key);

int BalanceBoard_GetValue(int num, int key);

HANDLE OpenHidHandle(unsigned short vendor_id, unsigned short product_id);
void ReadReport(HANDLE handle, unsigned char *InputReport, int *len);
void WriteReport(HANDLE handle, unsigned char *OutputReport, int *len);
void CloseHidHandle(HANDLE handle);



NTSTATUS GetDeviceCapabilities(HANDLE hRsDevHandle);

//OpenHidHandle:�w�肵��vendor_id,product_id�̃n���h�����擾���܂�
HANDLE OpenHidHandle(unsigned short vendor_id, unsigned short product_id);

//�c���Read/Write/Close�֐��͂�����჌�x��API�����̂܂܎g���Ă�A������nNumberOfBytesToRead/Write���f�o�C�XCaps��ByteLength�ɂ��Ă���悤���B

void ReadReport(HANDLE handle, unsigned char *InputReport, int *len);

void WriteReport(HANDLE handle, unsigned char *OutputReport, int *len);

void CloseHidHandle(HANDLE handle);

#define I_BLACK RGB(0,0,0)
#define I_WHITE RGB(255,255,255)



void Wii_Remote_Input(void);

void Report_0x12(unsigned char data1, unsigned char data2);

void Wii_Remote_mode_0x31(void);

void Wii_Remote_mode_0x34(void);

void Wii_Board_init(void);

void Wii_Remote_Input(void);
#endif