#include <Windows.h>
#include "common.h"
#include "mydirect3d.h"
#include "texture.h"
#include "sprite.h"
#include <d3dx9.h>

#include"Camera.h"





void Camera::SetCamera() {
	//==============================================
	//ここを追加　テスト用カメラ情報を準備
	g_posCameraEye = eye;
	g_posCameraAt = at;
	g_vecCameraUp = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	//g_vecCameraUp = up;
	//ビュー行列の作成
	D3DXMatrixLookAtLH(&g_mtxView,
		&g_posCameraEye,
		&g_posCameraAt,
		&g_vecCameraUp);

	MyDirect3D_GetDevice()->SetTransform(D3DTS_VIEW, &g_mtxView);

	//==============================================
// ここを追加　テスト用プロジェクション行列の作成
	D3DXMatrixPerspectiveFovLH(&g_mtxProjectioin,
		VIEW_ANGLE,         //ビュー平面の視野角
		VIEW_ASPECT,		//ビュー平面のアスペクト比
		VIEW_NEAR_Z,		//ビュー平面のNearZ
		VIEW_FAR_Z         //ビュー平面のFarZ
	);

	MyDirect3D_GetDevice()->SetTransform(D3DTS_PROJECTION, &g_mtxProjectioin);
}