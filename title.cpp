#include"title.h"
#include"sprite.h"
#include"common.h"

void TitleInit() {
	
}
void TitleUpdate() {

}

void TitleDraw() {
	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	Sprite_Draw(TEXTURE_INDEX_TITLE, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void TitleUnInit() {

}