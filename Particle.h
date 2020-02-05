#pragma once
#include <d3dx9.h>
#include<vector>
#include"Figure.h"

//†á
class Confetti {
private:
	std::vector<Cube> cube;
	std::vector<D3DXVECTOR3> movement;
	std::vector<D3DXVECTOR3> rot;
	std::vector<D3DXCOLOR> color;
	std::vector<int> lifeCount;
	float distance;
	D3DXVECTOR3 position;
	int amount;
	int intervalCount;
	int generationRange;
	float scale;

public:
	//ˆø”
	//pos:			¶¬‚·‚éÀ•W
	//range:		¶¬‚·‚é”ÍˆÍx,z
	//Amount:		¶¬‚·‚é—Ê
	//dropDistance: —‰º‚·‚é‹——£
	void Init(D3DXVECTOR3 pos,int range=10, int Amount =2, float drapDistance=10, float size=1);
	void Update();
	void Draw();
	void UnInit();
};

class ShaveIce {
private:
	std::vector<Plane> plane;
	std::vector<float> speed;
	std::vector<float> upSpeed;
	std::vector<int> lifeCount;
	std::vector<Plane> plane2;
	std::vector<float> speed2;
	std::vector<float> upSpeed2;
	std::vector<int> lifeCount2;
	 float GRAVITY = 0.05f;
	D3DXVECTOR3 position;
	D3DXVECTOR3 rotation;

public:
	void Init();
	void Update(D3DXVECTOR3 pos,D3DXVECTOR3 rot, D3DXVECTOR3 direction, int amout, float Speed=1);
	void Draw();
	void UnInit();
};