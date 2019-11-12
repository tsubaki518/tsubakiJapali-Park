#include"Light.h"
#include "mydirect3d.h"


void Light::Init(_D3DLIGHTTYPE type, D3DXVECTOR3 direction, D3DXCOLOR lightColor) {
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D_GetDevice();

	////ライトの初期化
	ZeroMemory(&light, sizeof(D3DLIGHT9));

	//ライトの設定
	light.Type = type;	//種類を設定
	light.Diffuse = lightColor;//光の色を設定
	light.Ambient = lightColor;//環境光の色を設定

	//光の向きを設定
	D3DXVECTOR3 vecDir = direction;
	D3DXVec3Normalize(&vecDir, &vecDir); //ベクトルを正規化
	light.Direction = vecDir;  //正規化したベクトルをセットする

	pDevice->SetLight(0, &light);//0番ライトへデータをセットする
	
}

void Light::Use(bool isUse) {
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D_GetDevice();
	pDevice->LightEnable(0, isUse);//0番ライトを有効化
}