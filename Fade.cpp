#include"Fade.h"
#include"sprite.h"
#include"common.h"

int fadeOutAlpha;
int fadeInAlpha;
const int FADE_ADD = 9;

void FadeInInit() {
	fadeInAlpha = 0;
}
bool FadeIn() {

	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, fadeInAlpha+ FADE_ADD));
	Sprite_Draw(TEXTURE_INDEX_MAX, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	fadeInAlpha += FADE_ADD;

	if (fadeInAlpha >= 255) {
		fadeInAlpha = 255;
		return true;
	} else {
		return false;
	}

}
void FadeOutInit() {
	fadeOutAlpha = 255;
}
bool FadeOut() {

	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, fadeOutAlpha));
	Sprite_Draw(TEXTURE_INDEX_MAX, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	fadeOutAlpha -= FADE_ADD;
	
	if (fadeOutAlpha <= 0) {
		fadeOutAlpha = 0;
		
	}
	
	if (fadeOutAlpha <= 100) {
		return true;
	} else {
		return false;
	}
}