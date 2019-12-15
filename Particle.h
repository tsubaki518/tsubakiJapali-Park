#pragma once
#include <d3dx9.h>
#include<vector>
#include"Figure.h"

//������
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

public:
	//����
	//pos:			����������W
	//range:		��������͈�x,z
	//Amount:		���������
	//dropDistance: �������鋗��
	void Init(D3DXVECTOR3 pos,int range=10, int Amount =2, float drapDistance=10);
	void Update();
	void Draw();
};
