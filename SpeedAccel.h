#pragma once
#include"XFile.h"
#include<d3dx9.h>
#include"Collision.h"

class SpeedAccel {
public:
	D3DXVECTOR3 position;
	D3DXVECTOR3 rotation;
	D3DXVECTOR3 scale;
	XFile model;
	Collider3D collider;
	bool isHit = false;

	SpeedAccel(){}
	
	void Init();
	void Draw();
	void UnInit();
};