#pragma once
#include<d3dx9.h>
#include"Figure.h"
#include"XFile.h"
#include"Collision.h"

class Obstacle {
private:
	void ModelDraw();
public:
	D3DXVECTOR3 position;
	D3DXVECTOR3 rotation;
	XFile model;
	Collider3D collider;
	int frameCount = 0;
	bool isBrokenPlayer = false;
	bool isBrokenNPC = false;

	Obstacle(){}
	void Init();
	void Update();
	void Draw();
	void UnInit();
	~Obstacle(){}
};