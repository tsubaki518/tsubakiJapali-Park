#pragma once
#include"Sori.h"
//プロジェクション用パラメータ
#define VIEW_ANGLE (D3DXToRadian(45.0f))                             //ビュー平面の視野角
#define VIEW_ASPECT ((float)SCREEN_WIDTH/ (float)SCREEN_HEIGHT)      //ビュー平面のアスペクト値
#define VIEW_NEAR_Z (1.0f)                                          //ビュー平面のNearZ
#define VIEW_FAR_Z (1000.0f)                                       //ビュー平面のFarZ



class Camera {
private:
	//カメラ用パラメータ
	D3DXVECTOR3 eye;
	D3DXVECTOR3 at;
	//プロジェクション＆カメラ行列
	D3DXMATRIX g_mtxProjectioin;     //プロジェクションマトリクス
	D3DXMATRIX g_mtxView;             //ビューマトリクス
public:
	D3DXVECTOR3 rad;
	void SetCamera(Sori sori);
};

