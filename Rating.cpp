#include"Rating.h"
#include"debug_font.h"
#include"ImageNumber.h"
#include <time.h>

float rating;

//�b�ԏ���
static clock_t start, end;
static int timer;

static bool sorispin = false;//�X�s������
static bool hitcrimp = false;//��Q��������
static int cnt;//2�b�ԃJ�E���g

//�������̏�����
void RatingInit() {
	rating = 50.0f;
	start = clock();
	sorispin = false;
	cnt = 0;
	end = clock();
}

//�������̌v��
void RatingUpdate(Sori sori) {
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
	if ((end - start) / (int)CLOCKS_PER_SEC >= 1) {
		start = clock();//�X�^�[�g�̎��Ԃ�������
		cnt += 1;

		//���@�����X�s�[�h���ێ���������B80%�ȏ�̎�
		if (sori.speed >= sori.maxSpeed*0.8) {
			rating += 5.0f;
			cnt = 0;
		}
		
		//���_��������Ԃ�2�b�ȏ�p���B
		if (cnt >= 2.0f) {
			rating -= 1.0f;
			cnt = 0;
		}

		/*
		//�����̏��ʂ�3�ʈȏ�̊ԁB
		if () {

		}
		*/
		//���@���X�s�������Ă���B
		if (sorispin == true) {
			rating += 6.0f;
			sorispin = false;
			cnt = 0;
		}
		
	}
	
	//���̏ꔻ��(�g���K�[)
	//���@����Q���ɂԂ���B
	if (hitcrimp == true) {
		rating += 0.5f;
		hitcrimp = false;
		cnt = 0;
	}

	/*
	//���@�����@�̂ɂԂ���B
	if () {
	rating += 0.1f;
	cnt = 0;
	}


	//���̃v���C���[���E������B
	if () {
	rating += 5.0f;
	cnt = 0;
	}

	//�����̏��ʂ��J��オ��B
	if () {
	rating += 3.0f;
	cnt = 0;
	}
	*/

	//�ő�
	if (rating >= 9999.0f) {
		rating = 9999.0f;
	}
	//�ŏ�
	if (rating < 50.0f) {
		rating = 50.0f;
	}
}

//�����Ŏw�肵�����W�Ɏ�������\������
void RatingDraw() {
	Sprite_SetColor(D3DCOLOR_RGBA(0, 255, 0, 255));
	ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 20 / 3 / 100 * 94, SCREEN_HEIGHT * 20 / 3 / 11), D3DXVECTOR2(0.15f, 0.15f), (int)rating / 10);
	ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 10 / 100 * 96, SCREEN_HEIGHT * 10 / 10), D3DXVECTOR2(0.1f, 0.1f), (int)rating % 10);
}

float GetRating() {
	return rating;
}