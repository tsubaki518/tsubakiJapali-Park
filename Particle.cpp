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
	//紙の色はこの中からランダムで決定する
	c[0] = D3DXCOLOR(255, 0, 0, 255);
	c[1] = D3DXCOLOR(0, 255, 0, 255);
	c[2] = D3DXCOLOR(0, 0, 255, 255);
	c[3] = D3DXCOLOR(255, 255, 0, 255);
	c[4] = D3DXCOLOR(0, 255, 255, 255);
	c[5] = D3DXCOLOR(255, 0, 255, 255);
	c[6] = D3DXCOLOR(255, 255, 255, 255);

	//紙の生成
	for (int i = 0; i < amount; i++) {
		cube.push_back(Cube(D3DXVECTOR3(rand() % generationRange / 2+(float)(rand()%100/100)+0.3f, 0, ((float)(rand() % generationRange) / 2) + (float)(rand() % 100 / 100)) + position));
		movement.push_back(D3DXVECTOR3(0, ((float)(rand() % 100) / 5000), 0));
		rot.push_back(D3DXVECTOR3(((float)(rand() % 100) / 200), ((float)(rand() % 100) / 200),((float)(rand() % 100) / 200)));
		color.push_back(D3DXCOLOR(c[rand() % 7]));
		lifeCount.push_back(0);
	}
	for (int i = 0; i < amount; i++) {
		cube.push_back(Cube(D3DXVECTOR3(-(rand() % generationRange / 2) - (float)(rand() % 100 / 100)-0.3f, 0, +((float)(rand() % generationRange) / 2) + (float)(rand() % 100 / 100)) + position));
		movement.push_back(D3DXVECTOR3(0, ((float)(rand() % 100) / 5000), 0));
		rot.push_back(D3DXVECTOR3(((float)(rand() % 100) / 200), ((float)(rand() % 100) / 200), ((float)(rand() % 100) / 200)));
		color.push_back(D3DXCOLOR(c[rand()%7]));
	}

	//紙を動かす
	for (int i = 0; i < (int)cube.size(); i++) {
		cube[i].position -= D3DXVECTOR3(0,0.1f,0)-movement[i]; //紙ごとに移動量を変える
		cube[i].scale = D3DXVECTOR3(PARPER_SIZE, PARPER_SIZE, 0);
		cube[i].rotation += rot[i];

		//削除
		if (cube[i].position.y < position.y-distance) {
			cube.erase(cube.begin() + i);
			movement.erase(movement.begin() + i);
			rot.erase(rot.begin() + i);
			color.erase(color.begin() + i);
		}
	}
}
void Confetti::Draw() {
	//紙の描画
	for (int i = 0; i < (int)cube.size(); i++) {
		cube[i].Draw(TEXTURE_INDEX_MAX, color[i]);
	}
}
void Confetti::UnInit() {
	//すべての要素を削除する
	for (int i = 0; i < (int)cube.size(); i++) {
		cube.pop_back();
		movement.pop_back();
		rot.pop_back();
		color.pop_back();
	}
}


void ShaveIce::Init() {
}
void ShaveIce::Update(D3DXVECTOR3 pos, D3DXVECTOR3 rot,D3DXVECTOR3 direction, int amout,float Speed) {
	for (int i = 0; i < amout; i++) {
		plane.push_back(Plane(direction*(float)(rand()%2000/1000)+pos, D3DXVECTOR3(0.025f, 0.025f, 0.025f)));
		speed.push_back((float)(rand() % 1000) / 5000+0.05f);
		upSpeed.push_back((float)(rand() & 1000) / 3500);
		lifeCount.push_back(0);

		plane2.push_back(Plane(direction*(float)(rand() % 2000 / 1000) + pos, D3DXVECTOR3(0.025f, 0.025f, 0.025f)));
		speed2.push_back((float)(rand() % 1000) / 5000 + 0.05f);
		upSpeed2.push_back((float)(rand() & 1000) / 3500);
		lifeCount2.push_back(0);
	}

	for (int i = 0; i < (int)plane.size(); i++) {
		plane[i].rotation = rot;
		plane[i].rotation.x -= 1.5f;
		plane[i].position += plane[i].GetRight()*speed[i]* Speed;
		plane[i].position.y += upSpeed[i];
		upSpeed[i] -= GRAVITY;
		lifeCount[i]++;

		//粒子の削除
		if (plane[i].position.y<pos.y) {
			plane.erase(plane.begin() + i);
			speed.erase(speed.begin() + i);
			upSpeed.erase(upSpeed.begin() + i);
			lifeCount.erase(lifeCount.begin() + i);
		}
	}

	for (int i = 0; i < (int)plane2.size(); i++) {
		plane2[i].rotation = rot;
		plane2[i].rotation.x -= 1.5f;
		plane2[i].position += (plane2[i].GetRight()*speed2[i] * -Speed)/2;
		plane2[i].position.y += upSpeed2[i];
		upSpeed2[i] -= GRAVITY;
		lifeCount2[i]++;

		//粒子の削除
		if (plane2[i].position.y < pos.y) {
			plane2.erase(plane2.begin() + i);
			speed2.erase(speed2.begin() + i);
			upSpeed2.erase(upSpeed2.begin() + i);
			lifeCount2.erase(lifeCount2.begin() + i);
		}
	}
}
void ShaveIce::Draw() {
	for (int i = 0; i < (int)plane.size(); i++) {
		plane[i].Draw(TEXTURE_INDEX_MAX);
	}
	for (int i = 0; i < (int)plane2.size(); i++) {
		plane2[i].Draw(TEXTURE_INDEX_MAX);
	}
}
void ShaveIce::UnInit() {
	for (int i = 0; i < (int)plane.size(); i++) {
		plane.pop_back();
		speed.pop_back();
		upSpeed.pop_back();

	}

	for (int i = 0; i < (int)plane2.size(); i++) {
		plane2.pop_back();
		speed2.pop_back();
		upSpeed2.pop_back();

	}

}