#include"Grid.h"

typedef struct {
	D3DXVECTOR3 vtx;  //���_���W
	D3DXVECTOR3 nor;  //�@���x�N�g��
	D3DCOLOR diffuse;  //���ˌ�
	D3DXVECTOR2 tex;  //�e�N�X�`�������W
}VERTEX_3D;

//3D�|���S���t�H�[�}�b�g
#define FVF_VERTEX_3D (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1)



void Grid::Draw() {
	const float sizeX = 0.5f;
	const float sizeY = 0.5f;
	const float sizeZ = 0.5f;

	//3D�|���S���p���_�̏���
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D_GetDevice();

	//�I�u�W�F�N�g�̒��_�o�b�t�@�𐶐�
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 72,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pD3DVtxBuff,
		NULL);

	//���_�o�b�t�@�̒��g�𖄂߂�
	VERTEX_3D *pVtx;

	//���_�o�b�t�@�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
	g_pD3DVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//�O���b�h�p���_�̏���
	{
		//���_���W�̐ݒ�
		{
			for (int i = 0; i < 36; i += 2) {
				pVtx[i].vtx = D3DXVECTOR3(0-4, 0, (float)i/2-8);
				pVtx[i+1].vtx = D3DXVECTOR3((float)10-4, 0, (float)i/2-8);
			}
			for (int i = 36; i < 57; i += 2) {
				pVtx[i].vtx = D3DXVECTOR3((float)(i-36)/2-4, 0, (float)36/2-1-8);
				pVtx[i+1].vtx = D3DXVECTOR3((float)(i-36)/2-4, 0, 0-8);
			}
	
		}
		//�@���x�N�g���̐ݒ�
		{
			for (int i = 0; i < 72; i++) {
				pVtx[i].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
			}
		}
		//���ˌ��̐ݒ�
		{
			for (int i = 0; i < 72; i++) {
				pVtx[i].diffuse = D3DXCOLOR(1,1,1,1);
			}
		}
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
	pDevice->DrawPrimitive(D3DPT_LINELIST, 0, 50);
}
