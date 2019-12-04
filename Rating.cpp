#include"Rating.h"
#include"debug_font.h"
#include"ImageNumber.h"
#include <time.h>

static float rating;

//�b�ԏ���
static clock_t start, end;
static int timer;

static bool sorispin = false;//�X�s������
static bool hitcrimp = false;//��Q��������
static int cnt;//2�b�ԃJ�E���g

//�������̏�����
void RatingInit() {
	rating = 5.0f;
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
			rating += 0.5f;
			
		}
		
		//���_��������Ԃ�2�b�ȏ�p���B
		if (cnt >= 2) {
			rating -= 0.1f;
			cnt = 0;
		}

		/*
		//�����̏��ʂ�3�ʈȏ�̊ԁB
		if () {

		}
		*/
		//���@���X�s�������Ă���B
		if (sorispin == true) {
			rating += 0.6f;
			sorispin = false;
			cnt = 0;
		}
		
	}
	
	//���̏ꔻ��(�g���K�[)
	//���@����Q���ɂԂ���B
	if (hitcrimp == true) {
		rating += 0.05f;
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
	if (rating >= 200) {
		rating = 200;
	}
	//�ŏ�
	if (rating < 5) {
		rating = 5.0f;
	}
}

//�����Ŏw�肵�����W�Ɏ�������\������
void RatingDraw() {
	ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH*5/12*11,SCREEN_HEIGHT * 5/ 10), D3DXVECTOR2(0.2f,0.2f), rating * 100);
}