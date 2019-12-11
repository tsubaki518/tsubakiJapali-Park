#pragma once
#include"main.h"
#include"XFile.h"
#include"character.h"

struct SettingPlayer {
	XFile characterModel[2];
	XFile soriModel;
	int weight[2];
};


void SettingInit();
void SettingUpdate();
void SettingDraw();
void SettingUnInit();
SettingPlayer GetSettingPlayer();
