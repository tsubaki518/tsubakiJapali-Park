#include"Rating.h"
#include"debug_font.h"

int rating;

//�������̏�����
void RatingInit() {
	rating = 0;
}

//�������̌v��
void RatingUpdate() {
	
	if (rating >= 100) {
		rating = 100;
	}
	else {
		rating += 1;
	}
}

//�����Ŏw�肵�����W�Ɏ�������\������
void RatingDraw() {
	DebugFont_Draw(1, 250, "������%d", rating);
}