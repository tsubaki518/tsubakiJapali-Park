//=============================================================================
//
// �T�E���h���� [sound.h]
//
//=============================================================================
#ifndef _SOUND_H_
#define _SOUND_H_

#include <Windows.h>

//*****************************************************************************
// �T�E���h�t�@�C��
//*****************************************************************************
typedef enum
{
	SOUND_LABEL_SE_MOVE,			//Player�̈ړ�
	SOUND_LABEL_SE_SELECT,			//�J�[�\���̈ړ���
	SOUND_LABEL_SE_SPEED_ACCEL,		//������
	SOUND_LABEL_SE_START_COUNT_DOWN,//�X�^�[�g�̃J�E���g�_�E��
	SOUND_LABEL_BUZZER,				//�S�[����
	SOUND_LABEL_BGM_GAME,			//�Q�[����ʂ�BGM
	SOUND_LABEL_BGM_GOALandRESULT,	//�Q�[���V�[���̃S�[�����烊�U���g��BGM
	SOUND_LABEL_MAX,
} SOUND_LABEL;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitSound(HWND hWnd);
void UninitSound(void);
HRESULT PlaySound(SOUND_LABEL label);
void StopSound(SOUND_LABEL label);
void StopSound(void);

#endif
