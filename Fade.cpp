#include"Fade.h"
#include"sprite.h"
#include"common.h"

int fadeOutAlpha;
int fadeInAlpha;

void FadeInInit() {
	fadeInAlpha = 0;
}
bool FadeIn() {
	Sprite_SetColor(D3DCOLOR_RGBA(0, 0, 0, fadeInAlpha));
	Sprite_Draw(TEXTURE_INDEX_MAX, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	fadeInAlpha +=3;

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

	Sprite_SetColor(D3DCOLOR_RGBA(0, 0, 0, fadeOutAlpha));
	Sprite_Draw(TEXTURE_INDEX_MAX, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	fadeOutAlpha -=3;
	
	if (fadeOutAlpha <= 0) {
		fadeOutAlpha = 0;
		
	}
	
	if (fadeOutAlpha <= 150) {
		return true;
	} else {
		return false;
	}
}