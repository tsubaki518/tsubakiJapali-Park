#pragma once
#include"main.h"
#include"XFile.h"
#include"character.h"

struct SettingPlayer {
	Character *character[2];
	XFile soriModel;
	int weight[2];
};


void SettingInit();
void SettingUpdate();
void SettingDraw();
void SettingUnInit();
SettingPlayer GetSettingPlayer();
