#include <Windows.h>
#include "common.h"
#include "mydirect3d.h"
#include "texture.h"
#include "sprite.h"
#include <d3dx9.h>

#include"Camera.h"





void Camera::SetCamera(Sori sori) {
	//==============================================
	//ここを追加　テスト用カメラ情報を準備
	eye.x = sinf(sori.cube.rotation.y)*-10 + sori.cube.position.x;
	eye.y = -sinf(sori.cube.rotation.x)*-5 + sori.cube.position.y + 8;
	eye.z = cosf(sori.cube.rotation.y)*-10 + sori.cube.position.z;

	at = sori.cube.position;
	
	//ビュー行列の作成
	D3DXVECTOR3 up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	D3DXMatrixLookAtLH(&g_mtxView,
		&eye,
		&at,
		&up);

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