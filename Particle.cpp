#include"Particle.h"
#include<stdlib.h>
#include<time.h>
#define GENERATE_NUM 5
#define PARPER_SIZE 0.2f

void Confetti::Init(D3DXVECTOR3 pos, int range, int Amount, float dorpDistance) {
	position = pos;
	amount = Amount;
	generationRange = range;
	distance = dorpDistance;
}
void Confetti::Update() {
	D3DXCOLOR c[8];
	//†‚ÌF‚Í‚±‚Ì’†‚©‚çƒ‰ƒ“ƒ_ƒ€‚ÅŒˆ’è‚·‚é
	c[0] = D3DXCOLOR(255, 0, 0, 255);
	c[1] = D3DXCOLOR(0, 255, 0, 255);
	c[2] = D3DXCOLOR(0, 0, 255, 255);
	c[3] = D3DXCOLOR(255, 255, 0, 255);
	c[4] = D3DXCOLOR(0, 255, 255, 255);
	c[5] = D3DXCOLOR(255, 0, 255, 255);
	c[6] = D3DXCOLOR(255, 255, 255, 255);
	c[7] = D3DXCOLOR(0, 0, 0, 255);

	//†‚Ì¶¬

	for (int i = 0; i < amount; i++) {
		cube.push_back(Cube(D3DXVECTOR3(rand() % generationRange / 2+(float)(rand()%100/100)+0.3f, 0, ((float)(rand() % generationRange) / 2) + (float)(rand() % 100 / 100)) + position));
		movement.push_back(D3DXVECTOR3(0, ((float)(rand() % 100) / 5000), 0));
		rot.push_back(D3DXVECTOR3(((float)(rand() % 100) / 200), ((float)(rand() % 100) / 200),((float)(rand() % 100) / 200)));
		color.push_back(D3DXCOLOR(c[rand() % 8]));
		lifeCount.push_back(0);
	}
	for (int i = 0; i < amount; i++) {
		cube.push_back(Cube(D3DXVECTOR3(-(rand() % generationRange / 2) - (float)(rand() % 100 / 100)-0.3f, 0, +((float)(rand() % generationRange) / 2) + (float)(rand() % 100 / 100)) + position));
		movement.push_back(D3DXVECTOR3(0, ((float)(rand() % 100) / 5000), 0));
		rot.push_back(D3DXVECTOR3(((float)(rand() % 100) / 200), ((float)(rand() % 100) / 200), ((float)(rand() % 100) / 200)));
		color.push_back(D3DXCOLOR(c[rand()%8]));
		lifeCount.push_back(0);
	}

	//†‚ğ“®‚©‚·
	for (int i = 0; i < (int)cube.size(); i++) {
		cube[i].position -= D3DXVECTOR3(0,0.1f,0)-movement[i]; //†‚²‚Æ‚ÉˆÚ“®—Ê‚ğ•Ï‚¦‚é
		cube[i].scale = D3DXVECTOR3(PARPER_SIZE, PARPER_SIZE, 0);
		cube[i].rotation += rot[i];
		lifeCount[i]++;

		if (cube[i].position.y < position.y-distance) {
			cube.erase(cube.begin() + i);
			movement.erase(movement.begin() + i);
			rot.erase(rot.begin() + i);
			color.erase(color.begin() + i);
			lifeCount.erase(lifeCount.begin() + i);
		}
	}
}
void Confetti::Draw() {
	//†‚Ì•`‰æ
	for (int i = 0; i < cube.size(); i++) {
		cube[i].Draw(TEXTURE_INDEX_MAX, color[i]);
	}
}