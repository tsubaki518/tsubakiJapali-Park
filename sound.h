//=============================================================================
//
// サウンド処理 [sound.h]
//
//=============================================================================
#ifndef _SOUND_H_
#define _SOUND_H_

#include <Windows.h>

//*****************************************************************************
// サウンドファイル
//*****************************************************************************
typedef enum
{
	SOUND_LABEL_SE_MOVE,			//Playerの移動
	SOUND_LABEL_SE_SELECT,			//カーソルの移動音
	SOUND_LABEL_SE_SPEED_ACCEL,		//加速音
	SOUND_LABEL_SE_START_COUNT_DOWN,//スタートのカウントダウン
	SOUND_LABEL_BUZZER,				//ゴール音
	SOUND_LABEL_BGM_GAME,			//ゲーム画面のBGM
	SOUND_LABEL_BGM_GOALandRESULT,	//ゲームシーンのゴールからリザルトのBGM
	SOUND_LABEL_MAX,
} SOUND_LABEL;

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitSound(HWND hWnd);
void UninitSound(void);
HRESULT PlaySound(SOUND_LABEL label);
void StopSound(SOUND_LABEL label);
void StopSound(void);

#endif
