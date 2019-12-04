#include"ImageNumber.h"

void ImageNumberDraw(D3DXVECTOR2 position, D3DXVECTOR2 size, int num) {
	const int TEXTURE_SIZR_X = 1536 / 10;
	const int TEXTURE_SIZR_Y = 140;

	int remainder;	//1�̈ʂ̒l���i�[
	int i = 0;//2���ڂ���\�����W�����炷���߂Ɏg�p

	//num�̒l������؂�Ȃ��Ȃ�܂Ń��[�v
	do{
		remainder = num % 10;
		num = num / 10;
		Sprite_Draw(TEXTURE_INDEX_NUMBER, position.x-i* TEXTURE_SIZR_X, position.y, (int)(remainder*TEXTURE_SIZR_X), 0, (int)(TEXTURE_SIZR_X * 0.90), TEXTURE_SIZR_Y, size.x, size.y);
		i++;
	} while (num != 0);
	
}