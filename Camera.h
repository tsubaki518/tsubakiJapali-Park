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
	D3DXVECTOR3 rad;
	D3DXVECTOR3 addPos;
	//プロジェクション＆カメラ行列
	D3DXMATRIX g_mtxProjectioin;     //プロジェクションマトリクス
	D3DXMATRIX g_mtxView;             //ビューマトリクス

	//加速演出用
	bool isStop;
	int stopCount;

	//スタート時のアニメーション用
	bool isStartOnece;
public:
	void Init(Sori sori);
	void SetCamera(Sori sori);
};

class SettingCamera {
private:
	//カメラ用パラメータ
	D3DXVECTOR3 eye;
	D3DXVECTOR3 at;
	D3DXVECTOR3 rad;
	//プロジェクション＆カメラ行列
	D3DXMATRIX g_mtxProjectioin;     //プロジェクションマトリクス
	D3DXMATRIX g_mtxView;             //ビューマトリクス

public:
	void SetCamera();
};
