#include <Windows.h>
#include "common.h"
#include "mydirect3d.h"
#include "texture.h"
#include "sprite.h"
#include <d3dx9.h>
#include"XFile.h"
#include<string>


#define FVF_VERTEX_3D (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1)

// ���b�V���̓ǂݍ���
BOOL XFile::Init(const char* fileName, const char* textureName)
{
	LPDIRECT3DDEVICE9	pDev;
	pDev = MyDirect3D_GetDevice();
	LPD3DXBUFFER lpD3DXBuffer = NULL;	// �ꎞ�I�ȃ������G���A

	// �w�t�@�C���̓ǂݍ���
	D3DXLoadMeshFromX(
		fileName,
		D3DXMESH_MANAGED,
		pDev,
		NULL,
		&lpD3DXBuffer,
		NULL,
		&(model.NumMaterial),
		&(model.lpMesh)
	);

	// lpD3DXBuffer �� NULL �Ȃ�ǂݍ��݂̎��s
	if (lpD3DXBuffer == NULL)	return FALSE;


	// �}�e���A�������̔z����m�ۂ���
	model.Mat = new D3DMATERIAL9[model.NumMaterial];
	model.Tex = new LPDIRECT3DTEXTURE9[model.NumMaterial];

	D3DXMATERIAL* D3DXMat = (D3DXMATERIAL*)lpD3DXBuffer->GetBufferPointer();

	for (DWORD i = 0; i < model.NumMaterial; i++)
	{
		model.Mat[i] = D3DXMat[i].MatD3D;
		model.Mat[i].Ambient = model.Mat[i].Diffuse;

		// �e�N�X�`���̓ǂݍ���
		if (FAILED(D3DXCreateTextureFromFile(pDev, textureName, &(model.Tex[i]))))
		{
			model.Tex[i] = NULL;
		}
	}

	lpD3DXBuffer->Release();

	return TRUE;
}


void XFile::Draw()
{
	//�|���S���̃��[���h�s��̍쐬
	D3DXMATRIX g_mtxWorld;
	D3DXMATRIX mtxScl;
	D3DXMATRIX mtxRot;
	D3DXMATRIX mtxTrs;
	LPDIRECT3DDEVICE9	g_pd3dDevice;
	g_pd3dDevice = MyDirect3D_GetDevice();


	// ���[���h�ϊ�
	//���[���h�s���P�ʍs��֏�����
	D3DXMatrixIdentity(&g_mtxWorld);

	//�X�P�[���s����쐬�����[���h�s��֍���
	D3DXMatrixScaling(&mtxScl, scale.x, scale.y, scale.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxScl);

	//��]�s����쐬�����[���h�s��֍���
	D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y+3.1415f, rotation.x-0.1f, rotation.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);

	//���s�s��
	D3DXMatrixTranslation(&mtxTrs, position.x, position.y, position.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);


	//���[���h�}�g���N�X��ݒ�
	g_pd3dDevice->SetTransform(D3DTS_WORLD, &g_mtxWorld);



	for (DWORD i = 0; i < model.NumMaterial; i++)
	{
		g_pd3dDevice->SetMaterial(&model.Mat[i]);	// �}�e���A��
		g_pd3dDevice->SetTexture(0, model.Tex[i]);	// �e�N�X�`��
		model.lpMesh->DrawSubset(i);				// ���b�V��
	}

}
void XFile::UnInit()
{
	// �}�e���A��
	if (model.Mat != NULL)	delete[]	model.Mat;

	// �e�N�X�`��
	if (model.Tex != NULL)
	{
		for (DWORD i = 0; i < model.NumMaterial; i++)
		{
			if (model.Tex[i])	model.Tex[i]->Release();
		}
	}

}

D3DXVECTOR3 XFile::GetForward() {
	D3DXMATRIX matrixWorld;    //���[���h�s��
	D3DXMATRIX mtxRot;		   //��]�s��
	D3DXVECTOR3 direction;
	direction.x = 0;
	direction.y = 0;
	direction.z = 1;

	{
		//�s���������
		D3DXMatrixIdentity(&matrixWorld);
		D3DXMatrixIdentity(&mtxRot);

		//��]�s����쐬
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y , rotation.x, rotation.z);
		D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &mtxRot);

		//�s�񂩂��]�������x�N�g�������o��
		direction = D3DXVECTOR3(matrixWorld._31, matrixWorld._32, matrixWorld._33);
	}
	return direction;
}
D3DXVECTOR3 XFile::GetRight() {
	D3DXMATRIX matrixWorld;    //���_�̍s��
	D3DXMATRIX mtxRot;
	D3DXVECTOR3 direction;
	direction.x = 1;
	direction.y = 0;
	direction.z = 0;

	{
		//�s���������
		D3DXMatrixIdentity(&matrixWorld);
		D3DXMatrixIdentity(&mtxRot);

		//��]�s����쐬
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
		D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &mtxRot);

		//�s�񂩂��]�������x�N�g�������o��
		direction = D3DXVECTOR3(matrixWorld._11, matrixWorld._12, matrixWorld._13);
	}
	direction.y *= -1;
	return direction;
}
D3DXVECTOR3 XFile::GetUp() {
	D3DXMATRIX matrixWorld;    //���_�̍s��
	D3DXMATRIX mtxRot;		   //��]�s��
	D3DXVECTOR3 direction;
	direction.x = 0;
	direction.y = 1;
	direction.z = 0;

	{
		//�s���������
		D3DXMatrixIdentity(&matrixWorld);
		D3DXMatrixIdentity(&mtxRot);

		//��]�s����쐬
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y , rotation.x, rotation.z);
		D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &mtxRot);

		//�s�񂩂��]�������x�N�g�������o��
		direction = D3DXVECTOR3(matrixWorld._21, matrixWorld._22, matrixWorld._23);
	}
	return direction;
}