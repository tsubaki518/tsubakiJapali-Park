#include <Windows.h>
#include "common.h"
#include "mydirect3d.h"
#include "texture.h"
#include "sprite.h"
#include <d3dx9.h>
#include"Camera.h"




void Camera::Init(Sori sori) {
	//�X�^�[�g���̃J�����̏����ʒu
	rad.y = sori.rotation.y + 3.14f;
	rad.x = sori.rotation.x - 1.9f;

	//���������Ƃ�eye���v���X����l��������
	addPos = D3DXVECTOR3(0, 0, 0);
	isStop = false;
	stopCount = 0;

	isStartOnece = true;
}
void Camera::SetCamera(Sori sori) {
	//�X�^�[�g�A�j���[�V�����p�̈ړ�
	if (isStartOnece == true) {
		if (rad.x < sori.rotation.x - 0.02f) {
			rad.x += 0.006f;
		} else if (rad.x > sori.rotation.x + 0.02f) {
			rad.x -= 0.006f;
		}

		if (rad.z < sori.rotation.z - 0.02f) {
			rad.z += 0.01f;
		} else if (rad.z > sori.rotation.z + 0.02f) {
			rad.z -= 0.01f;
		}

		if (rad.y < sori.rotation.y - 0.02f) {
			rad.y += 0.01f;
		} else if (rad.y > sori.rotation.y + 0.02f) {
			rad.y -= 0.01f;
		}

		
		if (rad.x > sori.rotation.x) {
			isStartOnece = false;
		}

	}

	//�ʏ�̈ړ�
	if (isStartOnece == false) {
		if (rad.x < sori.rotation.x - 0.02f) {
			rad.x += 0.007f;
		} else if (rad.x > sori.rotation.x + 0.02f) {
			rad.x -= 0.007f;
		}

		if (rad.z < sori.rotation.z - 0.02f) {
			rad.z += 0.01f;
		} else if (rad.z > sori.rotation.z + 0.02f) {
			rad.z -= 0.01f;
		}

		if (rad.y < sori.rotation.y - 0.02f) {
			rad.y += 0.05f;
		} else if (rad.y > sori.rotation.y + 0.02f) {
			rad.y -= 0.05f;
		}
	}

	//�\���������������ɏ������ɉ�����
	if (sori.isHitSpeedAccelBoard == true && sori.isSpin==false) {
		isStop = true;
		stopCount = 0;

	}
	if (isStop == true) {
		//�\���̌������ɏ�����������
		addPos -= sori.GetForward()*sori.speed*0.2f;
		addPos.y += 0.015f;
		stopCount++;
		
		//15�t���[���o�߂ŏI��
		if (stopCount == 15) {
			isStop = false;
		}
	} else if (isStop == false) {
		//���ɉ��������J���������ɖ߂�
		addPos *= 0.99f;
	}


	eye.x = sinf(rad.y)*-10 + sori.position.x;
	eye.y = -sinf(rad.x)*-5 + sori.position.y + 5;
	eye.z = cosf(rad.y)*-10 + sori.position.z;
	eye += addPos;
	at = sori.position;
	
	//�r���[�s��̍쐬
	D3DXVECTOR3 up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	D3DXMatrixLookAtLH(&g_mtxView,
		&eye,
		&at,
		&up);

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