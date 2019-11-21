#pragma once

enum CarsorPos {
	PosNone,
	PosGame,
	PosOption,
	PosDate,
	PosDemo,
	PosExsit
};

void TitleInit();
void TitleUpdate();
void TitleDraw();
void TitleUnInit();