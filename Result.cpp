#include"Result.h"
#include"debug_font.h"
#include"common.h"
#include"Rating.h"
#include"Timer.h"

void ResultInit() {

}
void ResultUpdate() {

}

void ResultDraw() {
	DebugFont_Draw(SCREEN_WIDTH/2-2, SCREEN_HEIGHT/2-2, "�肴���");
	RatingDraw();
	TimerDraw(SCREEN_WIDTH / 2 - 2, SCREEN_HEIGHT / 2 +25);
}

void ResultUnInit() {

}