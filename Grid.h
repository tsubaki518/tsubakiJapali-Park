#pragma once
#include <Windows.h>
#include "common.h"
#include "mydirect3d.h"
#include "texture.h"
#include "sprite.h"
#include <d3dx9.h>

class Grid {
private:
	//�T���v���|���S���̕\�����̂Ɋւ���p�����[�^
	D3DXVECTOR3 g_pos;		                      //�n�ʂ̈ʒu
	D3DXVECTOR3 g_rot;	                         //�n�ʂ̌���
	D3DXVECTOR3 g_scl;                          //�n�ʂ̑傫��
	D3DXMATRIX g_mtxWorld;                     //���[���h�}�g���N�X
	LPDIRECT3DVERTEXBUFFER9 g_pD3DVtxBuff;    //���_�o�b�t�@
public:
	D3DXVECTOR3 position{ 0,0,0 };
	D3DXVECTOR3 rotation{ 0,0,0 };
	D3DXVECTOR3 scale{ 1,1,1 };

	void Draw();
};