//---------------------------------------------------------
//
//	File  : BalanceBoardInput.h
//	Detail: バランスボードデバイス取得、入力取得
//	Author: Hiroaki Nishiyama
//	Data  : 2020/01/26
//
//---------------------------------------------------------
//	2020/01/26 : 作成、LED制御は未実装
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
//この4つの関数をDLLに書き出します

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
	//単位は10g
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

//OpenHidHandle:指定したvendor_id,product_idのハンドルを取得します
HANDLE OpenHidHandle(unsigned short vendor_id, unsigned short product_id);

//残りのRead/Write/Close関数はいわゆる低レベルAPIをそのまま使ってる、ただしnNumberOfBytesToRead/WriteをデバイスCapsのByteLengthにしているようだ。

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