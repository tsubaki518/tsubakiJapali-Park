#include"Obstacle.h"
#include"Game.h"
#include"Collision.h"
#include"debug_font.h"
#include"NPC.h"

void Obstacle::Init() {
	collider.size= D3DXVECTOR3(1.2f, 3.0f, 1.2f);
	frameCount = 0;
	isBrokenPlayer = false;
	isBrokenNPC = false;
	model.Init("asset/model/yukidaruma/��_���}.x", "asset/model/yukidaruma/yukidaruma.png");
}
void Obstacle::Update() {
	BoxCollider boxCollider;
	collider.position = position;
	

	//�Փ˔���
	bool isHitPlayer = boxCollider.Collider(collider, GetPlayer()->objCollider);
	bool isHitNPC = boxCollider.Collider(collider, GetNPC()->objCollider);

	//�Q�[���J�n���ɍŏ��̃t���[������position���o�O��̂�1�t���[���ڂ����������Ȃ�
	if (frameCount > 3) {
		//�v���C���[�ɏՓ˂����ꍇ
		if (isHitPlayer == true) {
			isBrokenPlayer = true;

			//�X�s�����͌������Ȃ�
			if (GetPlayer()->isSpin == false) {
				GetPlayer()->speed *= 0.5f;
				GetPlayer()->speedAccel *= 0.5f;
				GetPlayer()->slidCount *= 0.5f;
			}
		}

		//NPC�ɏՓ˂����ꍇ
		if (isHitNPC == true) {
			isBrokenNPC = true;

			//�X�s�����͌������Ȃ�
			if (GetNPC()->isSpin == false) {
				GetNPC()->speed *= 0.5f;
				GetNPC()->speedAccel *= 0.5f;
				GetNPC()->slidCount *= 0.5f;
			}
		}
	}

	//������я���
	//�v���C���[�����������ꍇ�̐�����я���
	if (isBrokenPlayer == true) {
		D3DXVECTOR3 moveDirection;
		moveDirection = -(GetPlayer()->position - position);
		position += moveDirection *2;

	}

	//NPC�����������ꍇ�̐�����я���
	if (isBrokenNPC == true) {
		D3DXVECTOR3 moveDirection;
		moveDirection = -(GetNPC()->position - position);
		position += moveDirection * 2;

	}

	frameCount++;
}
void Obstacle::Draw() {
	ModelDraw();

}
void Obstacle::UnInit() {
	model.UnInit();
}

void Obstacle::ModelDraw() {
	D3DXMATRIX g_mtxWorld;
	D3DXMATRIX mtxScl;
	D3DXMATRIX mtxRot;
	D3DXMATRIX mtxTrs;
	LPDIRECT3DDEVICE9	g_pd3dDevice;
	g_pd3dDevice = MyDirect3D_GetDevice();
	const float SCALE = 65;


	// ���[���h�ϊ�
	//���[���h�s���P�ʍs��֏�����
	D3DXMatrixIdentity(&g_mtxWorld);

	//�X�P�[���s����쐬�����[���h�s��֍���
	D3DXMatrixScaling(&mtxScl, SCALE, SCALE, SCALE);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxScl);

	//��]�s����쐬�����[���h�s��֍���
	D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);

	//���s�s��
	D3DXMatrixTranslation(&mtxTrs, position.x, position.y-1.3f, position.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);


	//���[���h�}�g���N�X��ݒ�
	g_pd3dDevice->SetTransform(D3DTS_WORLD, &g_mtxWorld);

	model.Draw();
}