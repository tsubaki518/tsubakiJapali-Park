#pragma once
#include<d3dx9.h>
#include"Figure.h"

class Obstacle {
public:
	D3DXVECTOR3 position;
	D3DXVECTOR3 rotation;
	Cube cube[2];
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