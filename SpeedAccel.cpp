#include"SpeedAccel.h"

void SpeedAccel::Init() {
	model.Init("asset/model/�A�C�X�N���[���E�E�E����/iceC.x", "asset/model/�A�C�X�N���[���E�E�E����/iceC22.png");
	scale = D3DXVECTOR3(1, 1, 1)*0.7f;
	isHit = false;
}
void SpeedAccel::Draw() {
	if (isHit == false) {
		collider.position = position;
		collider.rotation = rotation;
		collider.size = D3DXVECTOR3(3, 3, 3);
		rotation.y += 0.1f;

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
		D3DXMatrixRotationYawPitchRoll(&mtxRot, 0, 0, 3.541592f);
		D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);
		//��]�s����쐬�����[���h�s��֍���
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
		D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);

		//���s�s��
		D3DXMatrixTranslation(&mtxTrs, position.x, position.y + 1.3f, position.z);
		D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);

		//���[���h�}�g���N�X��ݒ�
		g_pd3dDevice->SetTransform(D3DTS_WORLD, &g_mtxWorld);

		model.Draw();
	}
}
void SpeedAccel::UnInit() {
	model.UnInit();
}