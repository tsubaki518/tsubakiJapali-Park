#include <Windows.h>
#include "common.h"
#include "mydirect3d.h"
#include "texture.h"
#include "sprite.h"
#include <d3dx9.h>
#include"Figure.h"


//===============================================
//������ǉ��@3D�p�ǉ��R�[�h
typedef struct {
	D3DXVECTOR3 vtx;  //���_���W
	D3DXVECTOR3 nor;  //�@���x�N�g��
	D3DCOLOR diffuse;  //���ˌ�
	D3DXVECTOR2 tex;  //�e�N�X�`�������W
}VERTEX_3D;

//3D�|���S���t�H�[�}�b�g
#define FVF_VERTEX_3D (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1)
static LPDIRECT3DVERTEXBUFFER9 g_pD3DVtxBuff;    //���_�o�b�t�@	
static LPDIRECT3DVERTEXBUFFER9 g_pD3DVtxBuffPlane;    //���_�o�b�t�@	
static LPDIRECT3DVERTEXBUFFER9 g_pD3DVtxBuffWall;    //���_�o�b�t�@	

static bool isOnece = false;
static bool isOnecePlane = false;
static bool isOneceWall = false;

void Cube::Draw(TextureIndex textureIndex, D3DXCOLOR color) {
	isDraw = true;
	const float sizeX = 0.5f;
	const float sizeY = 0.5f;
	const float sizeZ = 0.5f;
	collider.position = position;
	collider.size = scale;
	collider.rotation = rotation;
	//3D�|���S���p���_�̏���
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D_GetDevice();
	if (isOnece == false) {
		//�I�u�W�F�N�g�̒��_�o�b�t�@�𐶐�
		pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 36,
			D3DUSAGE_WRITEONLY,
			FVF_VERTEX_3D,
			D3DPOOL_MANAGED,
			&g_pD3DVtxBuff,
			NULL);
		isOnece = true;

		//���_�o�b�t�@�̒��g�𖄂߂�
		VERTEX_3D *pVtx;

		//���_�o�b�t�@�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
		g_pD3DVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

		//3D�|���S���p���_�̏���
		{
			//���_���W�̐ݒ�
			{
				pVtx[0].vtx = D3DXVECTOR3(-sizeX, sizeY, -sizeZ);  //1
				pVtx[1].vtx = D3DXVECTOR3(sizeX, sizeY, -sizeZ);   //2
				pVtx[2].vtx = D3DXVECTOR3(-sizeX, -sizeY, -sizeZ);  //3

				pVtx[3].vtx = D3DXVECTOR3(sizeX, sizeY, -sizeZ);
				pVtx[4].vtx = D3DXVECTOR3(sizeX, -sizeY, -sizeZ);
				pVtx[5].vtx = D3DXVECTOR3(-sizeX, -sizeY, -sizeZ);
				/////////////////////////////////////
				pVtx[6].vtx = D3DXVECTOR3(sizeX, sizeY, sizeZ);
				pVtx[7].vtx = D3DXVECTOR3(sizeX, -sizeY, -sizeZ);
				pVtx[8].vtx = D3DXVECTOR3(sizeX, sizeY, -sizeZ);

				pVtx[9].vtx = D3DXVECTOR3(sizeX, sizeY, sizeZ);
				pVtx[10].vtx = D3DXVECTOR3(sizeX, -sizeY, sizeZ);
				pVtx[11].vtx = D3DXVECTOR3(sizeX, -sizeY, -sizeZ);
				///////////////////////////////////////////
				pVtx[12].vtx = D3DXVECTOR3(-sizeX, sizeY, sizeZ);
				pVtx[14].vtx = D3DXVECTOR3(-sizeX, -sizeY, -sizeZ);
				pVtx[13].vtx = D3DXVECTOR3(-sizeX, sizeY, -sizeZ);

				pVtx[15].vtx = D3DXVECTOR3(-sizeX, sizeY, sizeZ);
				pVtx[17].vtx = D3DXVECTOR3(-sizeX, -sizeY, sizeZ);
				pVtx[16].vtx = D3DXVECTOR3(-sizeX, -sizeY, -sizeZ);
				///////////////////////////////////////

				pVtx[18].vtx = D3DXVECTOR3(-sizeX, sizeY, sizeZ);  //1
				pVtx[19].vtx = D3DXVECTOR3(-sizeX, -sizeY, sizeZ);  //3
				pVtx[20].vtx = D3DXVECTOR3(sizeX, sizeY, sizeZ);   //2

				pVtx[21].vtx = D3DXVECTOR3(sizeX, sizeY, sizeZ);
				pVtx[22].vtx = D3DXVECTOR3(-sizeX, -sizeY, sizeZ);
				pVtx[23].vtx = D3DXVECTOR3(sizeX, -sizeY, sizeZ);
				/////////////////////////////////////

				pVtx[24].vtx = D3DXVECTOR3(-sizeX, sizeY, -sizeZ);  //1
				pVtx[25].vtx = D3DXVECTOR3(-sizeX, sizeY, sizeZ);  //3
				pVtx[26].vtx = D3DXVECTOR3(sizeX, sizeY, -sizeZ);   //2

				pVtx[27].vtx = D3DXVECTOR3(-sizeX, sizeY, sizeZ);
				pVtx[28].vtx = D3DXVECTOR3(sizeX, sizeY, sizeZ);
				pVtx[29].vtx = D3DXVECTOR3(sizeX, sizeY, -sizeZ);
				/////////////////////////////////////
				pVtx[30].vtx = D3DXVECTOR3(-sizeX, -sizeY, -sizeZ);  //1
				pVtx[32].vtx = D3DXVECTOR3(-sizeX, -sizeY, sizeZ);  //3
				pVtx[31].vtx = D3DXVECTOR3(sizeX, -sizeY, -sizeZ);   //2

				pVtx[33].vtx = D3DXVECTOR3(-sizeX, -sizeY, sizeZ);
				pVtx[35].vtx = D3DXVECTOR3(sizeX, -sizeY, sizeZ);
				pVtx[34].vtx = D3DXVECTOR3(sizeX, -sizeY, -sizeZ);
				/////////////////////////////////////
			}
			//�@���x�N�g���̐ݒ�
			{
				for (int i = 0; i < 6; i++) {
					pVtx[i].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
				}

				for (int i = 0; i < 6; i++) {
					pVtx[i + 6].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
				}

				for (int i = 0; i < 6; i++) {
					pVtx[i + 12].nor = D3DXVECTOR3(0.0f, -1.0f, 0.0f);
				}

				for (int i = 0; i < 6; i++) {
					pVtx[i + 18].nor = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
				}

				for (int i = 0; i < 6; i++) {
					pVtx[i + 24].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
				}

				for (int i = 0; i < 6; i++) {
					pVtx[i + 30].nor = D3DXVECTOR3(0.0f, -1.0f, 0.0f);
				}
			}
	
			////�e�N�X�`���̐ݒ�
			{
				pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
				pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
				pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);

				pVtx[3].tex = D3DXVECTOR2(1.0f, 0.0f);
				pVtx[4].tex = D3DXVECTOR2(1.0f, 1.0f);
				pVtx[5].tex = D3DXVECTOR2(0.0f, 1.0f);
				/////////////////////////////////////////////////////

				pVtx[6].tex = D3DXVECTOR2(1.0f, 0.0f);
				pVtx[7].tex = D3DXVECTOR2(0.0f, 1.0f);
				pVtx[8].tex = D3DXVECTOR2(0.0f, 0.0f);

				pVtx[9].tex = D3DXVECTOR2(1.0f, 0.0f);
				pVtx[10].tex = D3DXVECTOR2(1.0f, 1.0f);
				pVtx[11].tex = D3DXVECTOR2(0.0f, 1.0f);
				//////////////////////////////////////////////////////////

				pVtx[12].tex = D3DXVECTOR2(0.0f, 0.0f);
				pVtx[13].tex = D3DXVECTOR2(0.0f, 1.0f);
				pVtx[14].tex = D3DXVECTOR2(1.0f, 1.0f);

				pVtx[15].tex = D3DXVECTOR2(0.0f, 0.0f);
				pVtx[16].tex = D3DXVECTOR2(1.0f, 1.0f);
				pVtx[17].tex = D3DXVECTOR2(1.0f, 0.0f);
				////////////////////////////////////////////////////////

				pVtx[18].tex = D3DXVECTOR2(0.0f, 0.0f);
				pVtx[19].tex = D3DXVECTOR2(1.0f, 0.0f);
				pVtx[20].tex = D3DXVECTOR2(0.0f, 1.0f);

				pVtx[21].tex = D3DXVECTOR2(0.0f, 1.0f);
				pVtx[22].tex = D3DXVECTOR2(1.0f, 0.0f);
				pVtx[23].tex = D3DXVECTOR2(1.0f, 1.0f);
				////////////////////////////////////////////////

				pVtx[24].tex = D3DXVECTOR2(1.0f, 1.0f);
				pVtx[25].tex = D3DXVECTOR2(0.0f, 1.0f);
				pVtx[26].tex = D3DXVECTOR2(1.0f, 0.0f);

				pVtx[27].tex = D3DXVECTOR2(0.0f, 1.0f);
				pVtx[28].tex = D3DXVECTOR2(0.0f, 0.0f);

				pVtx[29].tex = D3DXVECTOR2(1.0f, 0.0f);
				////////////////////////////////////////////////////////

				pVtx[30].tex = D3DXVECTOR2(1.0f, 1.0f);
				pVtx[31].tex = D3DXVECTOR2(1.0f, 0.0f);
				pVtx[32].tex = D3DXVECTOR2(0.0f, 1.0f);

				pVtx[33].tex = D3DXVECTOR2(0.0f, 1.0f);
				pVtx[34].tex = D3DXVECTOR2(1.0f, 0.0f);
				pVtx[35].tex = D3DXVECTOR2(0.0f, 0.0f);
			}
		}

		g_pD3DVtxBuff->Unlock();
	}
	//���_�o�b�t�@�̒��g�𖄂߂�
	VERTEX_3D *pVtx;

	//���_�o�b�t�@�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
	g_pD3DVtxBuff->Lock(0, 0, (void**)&pVtx, 0);
	//���ˌ��̐ݒ�
	
	for (int i = 0; i < 36; i++) {
		pVtx[i].diffuse = color;
	}

	g_pD3DVtxBuff->Unlock();

	//�|���S���̃��[���h�s��̍쐬
	D3DXMATRIX mtxScl;
	D3DXMATRIX mtxRot;
	D3DXMATRIX mtxTrs;

	g_pos = position;
	g_rot = rotation;
	g_scl = scale;

	//���[���h�s���P�ʍs��֏�����
	D3DXMatrixIdentity(&g_mtxWorld);

	//�X�P�[���s����쐬�����[���h�s��֍���
	D3DXMatrixScaling(&mtxScl, g_scl.x, g_scl.y, g_scl.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxScl);

	//��]�s����쐬�����[���h�s��֍���
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_rot.y, g_rot.x, g_rot.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);

	//���s�s��
	D3DXMatrixTranslation(&mtxTrs, g_pos.x, g_pos.y, g_pos.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);

	//���[���h�}�g���N�X��ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorld);

	//�`�悵�����|���S�����_�o�b�t�@���f�[�^�X�g���[���ɃZ�b�g
	pDevice->SetStreamSource(0, g_pD3DVtxBuff, 0, sizeof(VERTEX_3D));

	//�|���S���̕`��
	pDevice->SetFVF(FVF_VERTEX_3D);

	//�|���S���̕`��
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	pDevice->SetTexture(0, Texture_GetTexture(textureIndex));
	pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 12);

}
D3DXVECTOR3 Cube::GetForward() {
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
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y,rotation.x, rotation.z);
		D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &mtxRot);

		//�s�񂩂��]�������x�N�g�������o��
		direction = D3DXVECTOR3(matrixWorld._31, matrixWorld._32, matrixWorld._33);
	}
	return direction;
}
D3DXVECTOR3 Cube::GetRight() {
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
	return direction;
}
D3DXVECTOR3 Cube::GetUp() {
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
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
		D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &mtxRot);

		//�s�񂩂��]�������x�N�g�������o��
		direction = D3DXVECTOR3(matrixWorld._21, matrixWorld._22, matrixWorld._23);
	}
	return direction;
}


void Plane::Draw(TextureIndex textureIndex, D3DXCOLOR color) {
	isDraw = true;
	const float sizeX = 0.5f;
	const float sizeY = 0.5f;
	const float sizeZ = 0.5f;
	collider.position = position;
	collider.size = scale;
	collider.rotation = rotation;
	//3D�|���S���p���_�̏���
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D_GetDevice();
	if (isOnecePlane == false) {


		//�I�u�W�F�N�g�̒��_�o�b�t�@�𐶐�
		pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 6,
			D3DUSAGE_WRITEONLY,
			FVF_VERTEX_3D,
			D3DPOOL_MANAGED,
			&g_pD3DVtxBuffPlane,
			NULL);

		//���_�o�b�t�@�̒��g�𖄂߂�
		VERTEX_3D *pVtx;

		//���_�o�b�t�@�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
		g_pD3DVtxBuffPlane->Lock(0, 0, (void**)&pVtx, 0);

		//3D�|���S���p���_�̏���
		{
			//���_���W�̐ݒ�
			{
				pVtx[0].vtx = D3DXVECTOR3(-sizeX, 0, sizeY);  //1
				pVtx[1].vtx = D3DXVECTOR3(sizeX, 0, sizeY);   //2
				pVtx[2].vtx = D3DXVECTOR3(-sizeX, 0, -sizeY);  //3

				pVtx[3].vtx = D3DXVECTOR3(sizeX, 0, sizeY);
				pVtx[4].vtx = D3DXVECTOR3(sizeX, 0, -sizeY);
				pVtx[5].vtx = D3DXVECTOR3(-sizeX, 0, -sizeY);

			}
			//�@���x�N�g���̐ݒ�
			{
				for (int i = 0; i < 6; i++) {
					pVtx[i].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
				}
			}
			//���ˌ��̐ݒ�
			{
				for (int i = 0; i < 6; i++) {
					pVtx[i].diffuse = color;
				}
			}
			////�e�N�X�`���̐ݒ�
			{
				pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
				pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
				pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);

				pVtx[3].tex = D3DXVECTOR2(1.0f, 0.0f);
				pVtx[4].tex = D3DXVECTOR2(1.0f, 1.0f);
				pVtx[5].tex = D3DXVECTOR2(0.0f, 1.0f);

			}
		}

		g_pD3DVtxBuffPlane->Unlock();
		isOnecePlane = true;
	}

	//�|���S���̃��[���h�s��̍쐬
	D3DXMATRIX mtxScl;
	D3DXMATRIX mtxRot;
	D3DXMATRIX mtxTrs;

	g_pos = position;
	g_rot = rotation;
	g_scl = scale;

	//���[���h�s���P�ʍs��֏�����
	D3DXMatrixIdentity(&g_mtxWorld);

	//�X�P�[���s����쐬�����[���h�s��֍���
	D3DXMatrixScaling(&mtxScl, g_scl.x, g_scl.y, g_scl.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxScl);

	//��]�s����쐬�����[���h�s��֍���
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_rot.y, g_rot.x, g_rot.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);

	//���s�s��
	D3DXMatrixTranslation(&mtxTrs, g_pos.x, g_pos.y, g_pos.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);

	//���[���h�}�g���N�X��ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorld);

	//�`�悵�����|���S�����_�o�b�t�@���f�[�^�X�g���[���ɃZ�b�g
	pDevice->SetStreamSource(0, g_pD3DVtxBuffPlane, 0, sizeof(VERTEX_3D));
	//�|���S���̕`��
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	pDevice->SetTexture(0, Texture_GetTexture(textureIndex));
	//�|���S���̕`��
	pDevice->SetFVF(FVF_VERTEX_3D);

	pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 12);

}
D3DXVECTOR3 Plane::GetForward() {
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
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
		D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &mtxRot);

		//�s�񂩂��]�������x�N�g�������o��
		direction = D3DXVECTOR3(matrixWorld._31, matrixWorld._32, matrixWorld._33);
	}
	return direction;
}
D3DXVECTOR3 Plane::GetRight() {
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
	return direction;
}
D3DXVECTOR3 Plane::GetUp() {
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
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
		D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &mtxRot);

		//�s�񂩂��]�������x�N�g�������o��
		direction = D3DXVECTOR3(matrixWorld._21, matrixWorld._22, matrixWorld._23);
	}
	return direction;
}

void Wall::Draw(TextureIndex textureIndex, D3DXCOLOR color) {
	isDraw = true;
	const float sizeX = 0.5f;
	const float sizeY = 0.5f;
	const float sizeZ = 0.5f;
	collider.position = position;
	collider.size = scale;
	collider.rotation = rotation;
	//3D�|���S���p���_�̏���
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D_GetDevice();
	if (isOneceWall == false) {
		//�I�u�W�F�N�g�̒��_�o�b�t�@�𐶐�
		pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 36,
			D3DUSAGE_WRITEONLY,
			FVF_VERTEX_3D,
			D3DPOOL_MANAGED,
			&g_pD3DVtxBuffWall,
			NULL);
		isOneceWall = true;

		//���_�o�b�t�@�̒��g�𖄂߂�
		VERTEX_3D *pVtx;

		//���_�o�b�t�@�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
		g_pD3DVtxBuffWall->Lock(0, 0, (void**)&pVtx, 0);

		//3D�|���S���p���_�̏���
		{
			//���_���W�̐ݒ�
			{

				pVtx[0].vtx = D3DXVECTOR3(-sizeX, sizeY, -sizeZ);  //1
				pVtx[1].vtx = D3DXVECTOR3(-sizeX, sizeY, sizeZ);  //3
				pVtx[2].vtx = D3DXVECTOR3(sizeX, sizeY, -sizeZ);   //2

				pVtx[3].vtx = D3DXVECTOR3(-sizeX, sizeY, sizeZ);
				pVtx[4].vtx = D3DXVECTOR3(sizeX, sizeY, sizeZ);
				pVtx[5].vtx = D3DXVECTOR3(sizeX, sizeY, -sizeZ);
				/////////////////////////////////////
				pVtx[6].vtx = D3DXVECTOR3(-sizeX, -sizeY, -sizeZ);  //1
				pVtx[7].vtx = D3DXVECTOR3(-sizeX, -sizeY, sizeZ);  //3
				pVtx[8].vtx = D3DXVECTOR3(sizeX, -sizeY, -sizeZ);   //2

				pVtx[9].vtx = D3DXVECTOR3(-sizeX, -sizeY, sizeZ);
				pVtx[10].vtx = D3DXVECTOR3(sizeX, -sizeY, sizeZ);
				pVtx[11].vtx = D3DXVECTOR3(sizeX, -sizeY, -sizeZ);
				/////////////////////////////////////
			}
			//�@���x�N�g���̐ݒ�
			{
				for (int i = 0; i < 12; i++) {
					pVtx[i ].nor = D3DXVECTOR3(0.0f, -1.0f, 0.0f);
				}
			}


			for (int i = 0; i < 12; i++) {
				pVtx[i].diffuse = color;
			}
			////�e�N�X�`���̐ݒ�
			{
			

				pVtx[0].tex = D3DXVECTOR2(1.0f, 1.0f);
				pVtx[1].tex = D3DXVECTOR2(0.0f, 1.0f);
				pVtx[2].tex = D3DXVECTOR2(1.0f, 0.0f);

				pVtx[3].tex = D3DXVECTOR2(0.0f, 1.0f);
				pVtx[4].tex = D3DXVECTOR2(0.0f, 0.0f);

				pVtx[5].tex = D3DXVECTOR2(1.0f, 0.0f);
				////////////////////////////////////////////////////////

				pVtx[6].tex = D3DXVECTOR2(1.0f, 1.0f);
				pVtx[7].tex = D3DXVECTOR2(1.0f, 0.0f);
				pVtx[8].tex = D3DXVECTOR2(0.0f, 1.0f);

				pVtx[9].tex = D3DXVECTOR2(0.0f, 1.0f);
				pVtx[10].tex = D3DXVECTOR2(1.0f, 0.0f);
				pVtx[11].tex = D3DXVECTOR2(0.0f, 0.0f);
			}
		}

		g_pD3DVtxBuffWall->Unlock();
	}


	//�|���S���̃��[���h�s��̍쐬
	D3DXMATRIX mtxScl;
	D3DXMATRIX mtxRot;
	D3DXMATRIX mtxTrs;

	g_pos = position;
	g_rot = rotation;
	g_scl = scale;

	//���[���h�s���P�ʍs��֏�����
	D3DXMatrixIdentity(&g_mtxWorld);

	//�X�P�[���s����쐬�����[���h�s��֍���
	D3DXMatrixScaling(&mtxScl, g_scl.x, g_scl.y, g_scl.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxScl);

	//��]�s����쐬�����[���h�s��֍���
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_rot.y, g_rot.x, g_rot.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);

	//���s�s��
	D3DXMatrixTranslation(&mtxTrs, g_pos.x, g_pos.y, g_pos.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);

	//���[���h�}�g���N�X��ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorld);

	//�`�悵�����|���S�����_�o�b�t�@���f�[�^�X�g���[���ɃZ�b�g
	pDevice->SetStreamSource(0, g_pD3DVtxBuffWall, 0, sizeof(VERTEX_3D));

	//�|���S���̕`��
	pDevice->SetFVF(FVF_VERTEX_3D);

	//�|���S���̕`��
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	pDevice->SetTexture(0, Texture_GetTexture(textureIndex));
	pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 36);

}
D3DXVECTOR3 Wall::GetForward() {
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
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
		D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &mtxRot);

		//�s�񂩂��]�������x�N�g�������o��
		direction = D3DXVECTOR3(matrixWorld._31, matrixWorld._32, matrixWorld._33);
	}
	return direction;
}
D3DXVECTOR3 Wall::GetRight() {
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
	return direction;
}
D3DXVECTOR3 Wall::GetUp() {
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
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
		D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &mtxRot);

		//�s�񂩂��]�������x�N�g�������o��
		direction = D3DXVECTOR3(matrixWorld._21, matrixWorld._22, matrixWorld._23);
	}
	return direction;
}