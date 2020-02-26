#include<d3dx9.h>
#include"main.h"
#include"Thank.h"
#include"sprite.h"
#include"common.h"
#include"input.h"
#include"Fade.h"

static bool wasChangeScene = false;

void ThankInit() {
	FadeInInit();
	FadeOutInit();
	wasChangeScene = false;
}
void ThankUpdate() {
	if (Keyboard_IsTrigger(DIK_RETURN)) {
		wasChangeScene = true;
	}
}
void ThankDraw() {
	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	Sprite_Draw(TEXTURE_INDEX_THANK, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	FadeOut();
	if (wasChangeScene == true) {
		if (FadeIn()) {
			SetScene(TITLE);
		}
	}
}
void ThankUnInit() {

}