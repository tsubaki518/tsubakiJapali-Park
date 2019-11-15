#pragma once
#include"Sori.h"
//�v���W�F�N�V�����p�p�����[�^
#define VIEW_ANGLE (D3DXToRadian(45.0f))                             //�r���[���ʂ̎���p
#define VIEW_ASPECT ((float)SCREEN_WIDTH/ (float)SCREEN_HEIGHT)      //�r���[���ʂ̃A�X�y�N�g�l
#define VIEW_NEAR_Z (1.0f)                                          //�r���[���ʂ�NearZ
#define VIEW_FAR_Z (1000.0f)                                       //�r���[���ʂ�FarZ



class Camera {
private:
	//�J�����p�p�����[�^
	D3DXVECTOR3 eye;
	D3DXVECTOR3 at;
	//�v���W�F�N�V�������J�����s��
	D3DXMATRIX g_mtxProjectioin;     //�v���W�F�N�V�����}�g���N�X
	D3DXMATRIX g_mtxView;             //�r���[�}�g���N�X
public:
	D3DXVECTOR3 rad;
	void SetCamera(Sori sori);
};

