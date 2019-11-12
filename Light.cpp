#include"Light.h"
#include "mydirect3d.h"


void Light::Init(_D3DLIGHTTYPE type, D3DXVECTOR3 direction, D3DXCOLOR lightColor) {
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D_GetDevice();

	////���C�g�̏�����
	ZeroMemory(&light, sizeof(D3DLIGHT9));

	//���C�g�̐ݒ�
	light.Type = type;	//��ނ�ݒ�
	light.Diffuse = lightColor;//���̐F��ݒ�
	light.Ambient = lightColor;//�����̐F��ݒ�

	//���̌�����ݒ�
	D3DXVECTOR3 vecDir = direction;
	D3DXVec3Normalize(&vecDir, &vecDir); //�x�N�g���𐳋K��
	light.Direction = vecDir;  //���K�������x�N�g�����Z�b�g����

	pDevice->SetLight(0, &light);//0�ԃ��C�g�փf�[�^���Z�b�g����
	
}

void Light::Use(bool isUse) {
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D_GetDevice();
	pDevice->LightEnable(0, isUse);//0�ԃ��C�g��L����
}