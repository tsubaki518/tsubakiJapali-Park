#include <Windows.h>
#include "common.h"
#include "mydirect3d.h"
#include "texture.h"
#include "sprite.h"
#include <d3dx9.h>
#include"Camera.h"




void Camera::Init(Sori sori) {
	rad.y = sori.rotation.y + 3.14f;
	rad.x = sori.rotation.x - 3.14f;
}
void Camera::SetCamera(Sori sori) {

	//カメラを少しずつ回転させる
	if (sori.isSpin == false) {
		if (rad.x < sori.rotation.x) {
			rad.x += 0.01f;
		} else if (rad.x > sori.rotation.x) {
			rad.x -= 0.01f;
		}

		if (rad.z < sori.rotation.z) {
			rad.z += 0.01f;
		} else if (rad.z > sori.rotation.z) {
			rad.z -= 0.01f;
		}

		if (rad.y < sori.rotation.y) {
			rad.y += 0.01f;
		} else if (rad.y > sori.rotation.y) {
			rad.y -= 0.01f;
		}
	}

	//==============================================
	/*eye.x = sinf(sori.cube.rotation.y)*-10 + sori.cube.position.x;
	eye.y = -sinf(sori.cube.rotation.x)*-5 + sori.cube.position.y + 8;
	eye.z = cosf(sori.cube.rotation.y)*-10 + sori.cube.position.z;

	at = sori.cube.position;*/
	eye.x = sinf(rad.y)*-10 + sori.position.x;
	eye.y = -sinf(rad.x)*-5 + sori.position.y + 8;
	eye.z = cosf(rad.y)*-10 + sori.position.z;

	at = sori.position;
	
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