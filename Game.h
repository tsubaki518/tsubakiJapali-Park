#pragma once
#include<d3dx9.h>
#include"Sori.h"

void GameInit();
void GameUpdate();
void GameDraw();
void GameUnInit();
void GameCollision();
D3DXVECTOR3 GetPlayerPos();
Sori* GetPlayer();
NPC* GetNPC();