#include <Windows.h>
#include "common.h"
#include "mydirect3d.h"
#include "texture.h"
#include "sprite.h"
#include <d3dx9.h>

#include"Camera.h"





void Camera::SetCamera() {
	//==============================================
	//������ǉ��@�e�X�g�p�J������������
	g_posCameraEye = eye;
	g_posCameraAt = at;
	g_vecCameraUp = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	//g_vecCameraUp = up;
	//�r���[�s��̍쐬
	D3DXMatrixLookAtLH(&g_mtxView,
		&g_posCameraEye,
		&g_posCameraAt,
		&g_vecCameraUp);

	MyDirect3D_GetDevice()->SetTransform(D3DTS_VIEW, &g_mtxView);

	//==============================================
// ������ǉ��@�e�X�g�p�v���W�F�N�V�����s��̍쐬
	D3DXMatrixPerspectiveFovLH(&g_mtxProjectioin,
		VIEW_ANGLE,         //�r���[���ʂ̎���p
		VIEW_ASPECT,		//�r���[���ʂ̃A�X�y�N�g��
		VIEW_NEAR_Z,		//�r���[���ʂ�NearZ
		VIEW_FAR_Z         //�r���[���ʂ�FarZ
	);

	MyDirect3D_GetDevice()->SetTransform(D3DTS_PROJECTION, &g_mtxProjectioin);
}