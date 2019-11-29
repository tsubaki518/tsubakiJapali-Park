#pragma once
#include <Windows.h>
#include "mydirect3d.h"
#include <d3dx9.h>
#include"XFile.h"

//各パラメータの基準値
#define NORMAL_MAX_SPEED 0.5f
#define NORMAL_MOVE_ACCEL 0.001f
#define NORMAL_HANDLING 0.05f
#define NORMAL_DEFENSE 1.0f
#define NORMAL_SPIN_NUM 1.0f


//クラス定義
class Character {
public:
	D3DXVECTOR3 rotation;
	D3DXVECTOR3 position;
	D3DXVECTOR3 scale;
	float inputRotZ = 0;;
	float maxSpeed = 0.0f;		//最大速度
	float moveAccel = 0.0f;		//加速性能
	float handling = 0.0f;		//ハンドリング性能
	float defense = 0.0f;		//弾き耐性
	int	spinNum = 0;			//スピン持続
	D3DXCOLOR color;			//キャラクターカラー
	XFile model;				//モデルデータ

	Character(){}
	virtual void Init();
	virtual float GetMaxSpeed();	//最高速維持_スコア加点
	virtual void Draw();
	virtual void UnInit();


};


//各キャラクタのパラメータ
class Elephant :public Character {
public:
	Elephant(){
		maxSpeed = NORMAL_MAX_SPEED * 1.04f;
		moveAccel = NORMAL_MOVE_ACCEL * 1.08f;
		handling = NORMAL_HANDLING * 0.90f;
		defense = NORMAL_DEFENSE * 1.10f;
	  //spinNum= NORMAL_SPIN_NUM;
		color = { 0.3f,0.6f,1,1 };			//水商売色
	}
	void Init();
	void Draw();
	float GetMaxSpeed();
	void UnInit();
};

class Bear :public Character {
public:
	Bear(){
		maxSpeed = NORMAL_MAX_SPEED * 1.02f;
		moveAccel = NORMAL_MOVE_ACCEL * 1.04f;
		handling = NORMAL_HANDLING * 0.92f;
		defense = NORMAL_DEFENSE * 1.06f;
	  //spinNum= NORMAL_SPIN_NUM;
		color = { 1,0.7f,0,1 };				//運古色
	}
	void Init();
	void Draw();
	float GetMaxSpeed();
	void UnInit();
};

class Dog :public Character {
public:
	Dog(){
		maxSpeed = NORMAL_MAX_SPEED * 1.00f;
		moveAccel = NORMAL_MOVE_ACCEL * 1.00f;
		handling = NORMAL_HANDLING * 0.94f;
		defense = NORMAL_DEFENSE * 1.00f;
	  //spinNum= NORMAL_SPIN_NUM;
		color = { 1,0.2f,0.3f,1 };			//驚愕の赤色
	}
	void Init();
	void Draw();
	float GetMaxSpeed();
	void UnInit();
};

class Rabbit :public Character {
public:
	Rabbit(){
		maxSpeed = NORMAL_MAX_SPEED * 0.96f;
		moveAccel = NORMAL_MOVE_ACCEL * 0.96f;
		handling = NORMAL_HANDLING * 0.96f;
		defense = NORMAL_DEFENSE * 0.90f;
	  //spinNum= NORMAL_SPIN_NUM;
		color = { 1,1,1,1 };				//純白の白色
	}
	void Init();
	void Draw();
	float GetMaxSpeed();
	void UnInit();
};

class Hamster :public Character {
public:
	Hamster(){
		maxSpeed = NORMAL_MAX_SPEED * 0.94f;
		moveAccel = NORMAL_MOVE_ACCEL * 0.88f;
		handling = NORMAL_HANDLING * 1.00f;
		defense = NORMAL_DEFENSE * 0.74f;
	  //spinNum= NORMAL_SPIN_NUM;
		color = { 0.5f,0.9f,0.9f,1 };		//あの大空な色
	}
	void Init();
	void Draw();
	float GetMaxSpeed();
	void UnInit();
};


