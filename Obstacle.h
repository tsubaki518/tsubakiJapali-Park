#pragma once
#include<d3dx9.h>
#include"Figure.h"

class Obstacle {
public:
	D3DXVECTOR3 position;
	D3DXVECTOR3 rotation;
	Cube cube;
	bool isBroken = false;

	Obstacle(){
		cube.position = D3DXVECTOR3(25255455, 545454545, 454545454);
	}
	void Init();
	void Update();
	void Draw();
	void UnInit();
	~Obstacle(){}
};