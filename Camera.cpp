#include <Windows.h>
#include "common.h"
#include "mydirect3d.h"
#include "texture.h"
#include "sprite.h"
#include <d3dx9.h>
#include"Camera.h"
#include<math.h>
#include"input.h"


void Camera::Init(Sori sori) {
	//スタート時のカメラの初期位置
	rad.y = sori.rotation.y + 3.14f;
	rad.x = sori.rotation.x - 1.9f;

	//加速したときeyeをプラスする値を初期化
	addPos = D3DXVECTOR3(0, 0, 0);
	isStop = false;
	stopCount = 0;

	isStartOnece = true;
}
void Camera::SetCamera(Sori sori) {
	//0.007f
	//float addRad = (sori.rotation.y) - (rad.y);
	float unti = 10;
	D3DXVECTOR3 addRad = sori.rotation - rad;
	//スタートアニメーション用の移動
	if (isStartOnece == true) {
		if (rad.x < sori.rotation.x - 0.02f) {
			rad.x += 0.006f;
		} else if (rad.x > sori.rotation.x + 0.02f) {
			rad.x -= 0.006f;
		}

		if (rad.z < sori.rotation.z - 0.02f) {
			rad.z += 0.01f;
		} else if (rad.z > sori.rotation.z + 0.02f) {
			rad.z -= 0.01f;
		}

		if (rad.y < sori.rotation.y - 0.02f) {
			rad.y += 0.01f;
		} else if (rad.y > sori.rotation.y + 0.02f) {
			rad.y -= 0.01f;
		}

		
		if (rad.x > sori.rotation.x) {
			isStartOnece = false;
		}

	}

	//通常の移動
	if (isStartOnece == false) {
		if (rad.x < sori.rotation.x - 0.02f) {
			rad.x += addRad.x/ unti;
		} else if (rad.x > sori.rotation.x + 0.02f) {
			rad.x += addRad.x / unti;
		}

		if (rad.z < sori.rotation.z - 0.02f) {
			rad.z += addRad.z / unti;
		} else if (rad.z > sori.rotation.z + 0.02f) {
			rad.z += addRad.z / unti;
		}

		if (rad.y < sori.rotation.y - 0.02f) {
			rad.y += addRad.y / unti;
		} else if (rad.y > sori.rotation.y + 0.02f) {
			rad.y += addRad.y / unti;
		}
	}

	//ソリが加速した時に少し後ろに下がる
	if (sori.isHitSpeedAccelBoard == true && sori.isSpin==false) {
		isStop = true;
		stopCount = 0;

	}
	if (isStop == true) {
		//ソリの後ろ方向に少しずつ下がる
		addPos -= sori.GetForward()*sori.speed*0.2f;
		addPos.y += 0.015f;
		stopCount++;

		//15フレーム経過で終了
		if (stopCount == 15) {
			isStop = false;
		}
	} else if (isStop == false) {
		//後ろに下がったカメラを元に戻す
		addPos *= 0.99f;
	}

	if (Keyboard_IsPress(DIK_G)) {
		eye = sori.GetForward() * 5+sori.position;
		eye += sori.GetUp() * 3;
		at = -sori.GetForward() * 5 + sori.position;
		at += sori.GetUp() * 3;
	} else {
		eye.x = sinf(rad.y)*-10 + sori.position.x;
		eye.y = -sinf(rad.x)*-5 + sori.position.y + 5;
		eye.z = cosf(rad.y)*-10 + sori.position.z;
		eye += addPos;
		at = sori.position;
	}
	
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


void SettingCamera::SetCamera() {
	eye.x = 0;
	eye.y = 0;
	eye.z = -5;

	at.x = 0;
	at.y = 0;
	at.z = 0;

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