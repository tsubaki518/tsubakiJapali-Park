#include"Rating.h"
#include"debug_font.h"
#include <time.h>

float rating;

//�b�ԏ���
clock_t start,timer, end;

bool sorispin = false;//�X�s������
bool hitcrimp = false;//��Q��������

//�������̏�����
void RatingInit() {
	rating = 5.0f;
	start = NULL;
	sorispin = false;
}

//�������̌v��
void RatingUpdate(Sori sori) {
	//�b�ԃX�^�[�g
	if (start == NULL) {
		start = clock();
		timer = 1 * CLOCKS_PER_SEC + clock();
	}
	
	//�X�s������}��
	if (sori.isSpin == true) {
		sorispin = true;
	}
	//��Q��������}��
	if ((sori.isHitLeftWall == true) || (sori.isHitRightWall == true)) {
		hitcrimp = true;
	}

	
	
	//1�b�Ԕ���(�z�[���h)
	end = clock();
	if (end - start >= timer) {
		start += timer;

		//���@�����X�s�[�h���ێ���������B80%�ȏ�̎�
		if (sori.speed >= sori.maxSpeed*0.8) {
			rating += 0.5f;
		}
		/*
		//���_��������Ԃ�2�b�ȏ�p���B
		if () {
		rating -= 0.1f;
		}

		//�����̏��ʂ�3�ʈȏ�̊ԁB
		if () {

		}
		*/
		//���@���X�s�������Ă���B
		if (sorispin == true) {
			rating += 0.6f;
			sorispin = false;
		}
		
	}
	
	//���̏ꔻ��(�g���K�[)
	//���@����Q���ɂԂ���B
	if (hitcrimp == true) {
		rating += 0.05f;
		hitcrimp = false;
	}

	/*
	//���@�����@�̂ɂԂ���B
	if () {
	rating += 0.1f;
	}


	//���̃v���C���[���E������B
	if () {
	rating += 5.0f;
	}

	//�����̏��ʂ��J��オ��B
	if () {
	rating += 3.0f;
	}


	*/
	//�ő�ŏ�
	if (rating >= 200) {
		rating = 200;
	}
	if (rating < 5) {
		rating = 5.0f;
	}
}

//�����Ŏw�肵�����W�Ɏ�������\������
void RatingDraw() {
	DebugFont_Draw(1, 250, "������%0.2lf%%", rating);
}