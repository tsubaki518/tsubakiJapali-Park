#include"Option.h"
#include"sprite.h"
#include"common.h"
#include"input.h"
#include"XInput.h"
#include"main.h"
#include"debug_font.h"
#include"mydirect3d.h"
#include"sound.h"

void OptionInit() {

}
void OptionUpdate() {
	if (Keyboard_IsTrigger(DIK_RETURN)) {
		SetScene(TITLE);
	}
}
void OptionDraw() {

}
void OptionUnInit() {

}