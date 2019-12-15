#pragma once
#include"Collision.h"
#include"texture.h"

class Cube {
private:
	//�T���v���|���S���̕\�����̂Ɋւ���p�����[�^
	D3DXVECTOR3 g_pos;		                      //�n�ʂ̈ʒu
	D3DXVECTOR3 g_rot;	                         //�n�ʂ̌���
	D3DXVECTOR3 g_scl;                          //�n�ʂ̑傫��
	D3DXMATRIX g_mtxWorld;                     //���[���h�}�g���N�X

public:
	D3DXVECTOR3 position{0,0,0};
	D3DXVECTOR3 rotation{0,0,0};
	D3DXVECTOR3 scale{1,1,1};
	Collider3D collider;

	Cube(){}
	Cube(D3DXVECTOR3 pos) {
		position = pos;
	}
	void Draw(TextureIndex textureIndex, D3DXCOLOR color={1,1,1,1});

	D3DXVECTOR3 GetForward(); //���ʂ��擾
	D3DXVECTOR3 GetRight();  //�E���擾
	D3DXVECTOR3 GetUp();    //��擾
};

