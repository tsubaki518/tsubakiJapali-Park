#include"character.h"
#include"input.h"


//�e�L�����N�^�[�̏�����
void Character::Init(){
	inputRotZ = 0;
}
void Elephant::Init() {
	inputRotZ = 0;
}
void Bear::Init() {
	model = new XFile();
	model->Init("asset/model/Bear/bear.x", "asset/model/Bear/bearuv.jpg");
	scale.x = 30;
	scale.y = 30;
	scale.z = 30;
	inputRotZ = 0;
}
void Dog::Init() {
	inputRotZ = 0;
}
void Rabbit::Init() {
	inputRotZ = 0;
}
void Hamster::Init() {
	inputRotZ = 0;
}


//�e�L�����N�^�[�̕`�揈��
void Character::Draw() {

}
void Elephant::Draw() {

}
void Bear::Draw() {

	//�|���S���̃��[���h�s��̍쐬
	D3DXMATRIX g_mtxWorld;
	D3DXMATRIX mtxScl;
	D3DXMATRIX mtxRot;
	D3DXMATRIX mtxInputRot;
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
	D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y + 3.1415f, rotation.x - 0.1f, rotation.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);



	//���s�s��
	D3DXMatrixTranslation(&mtxTrs, position.x, position.y, position.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);


	//���[���h�}�g���N�X��ݒ�
	g_pd3dDevice->SetTransform(D3DTS_WORLD, &g_mtxWorld);
	model->Draw();

}
void Dog::Draw() {

}
void Rabbit::Draw() {

}
void Hamster::Draw() {

}


//�e�L�����N�^�[�̏I������
void Character::UnInit() {
}
void Elephant::UnInit() {

}
void Bear::UnInit() {
	model->UnInit();
	delete model;
}
void Dog::UnInit() {

}
void Rabbit::UnInit() {

}
void Hamster::UnInit() {

}





//�ō����ێ��ż����i�X�R�A�j�����_
float Character::GetMaxSpeed() {
	return maxSpeed;
}

float Elephant::GetMaxSpeed() {
	return maxSpeed;
}

float Bear::GetMaxSpeed() {
	return maxSpeed;
}

float Dog::GetMaxSpeed() {
	return maxSpeed;
}

float Rabbit::GetMaxSpeed() {
	return maxSpeed;
}

float Hamster::GetMaxSpeed() {
	return maxSpeed;
}