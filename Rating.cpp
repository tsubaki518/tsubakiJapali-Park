#include"Rating.h"
#include"debug_font.h"
#include"ImageNumber.h"
#include <time.h>
#include"Game.h"
#include"common.h"
float rating;

//�b�ԏ���
static clock_t start, end;
static int timer;

static bool sorispin = false;	//�X�s������
static bool hitcrimp = false;	//��Q��������

static int cnt;					//2�b�ԃJ�E���g

//���b�Z�[�W�\���̃t���O
static bool M10 = true;			//10��OVER�I
static bool M50 = true;			//50��OVER�I
static bool M100 = true;		//100��OVER�I
static bool M150 = true;		//150��OVER�I
static bool M200 = true;		//200��OVER�I
static bool M250 = true;		//250��OVER�I

static float mx = 1563;			//���b�Z�[�W�J�ڂ�X���W(%OVER)
static float nx = 5900;			//���b�Z�[�W�J�ڂ�X���W(����)

static int count = 0;			//���b�Z�[�W�̕\������

static int madd = -20.0f;		//���b�Z�[�W�̕\�����x�i%OVER�j
static int nadd = -50.0f;		//���b�Z�[�W�̕\�����x�i�����j

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
			rating += 15.0f;
			cnt = 0;
		}
		
		//���_��������Ԃ�2�b�ȏ�p���B
		if (cnt >= 2.0f) {
			rating -= 3.0f;
			cnt = 0;
		}

		//���@���X�s�������Ă���B
		if (sorispin == true) {
			rating += 18.0f;
			sorispin = false;
			cnt = 0;
		}
		
	}
	
	//���̏ꔻ��(�g���K�[)
	//���@����Q���ɂԂ���B
	if (hitcrimp == true) {
		rating += 1.5f;
		hitcrimp = false;
		cnt = 0;
	}

	
	//���@�����@�̂ɂԂ���B
	if (sori.isNPCcollision==true) {
	rating += 0.3f;
	cnt = 0;
	}

	//�����̏��ʂ��J��オ��B
	if (GetPlayer()->isChangeRank==true) {
	rating += 0.3f;
	cnt = 0;
	}
	

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

//�X�R�A���b�Z�[�W
	////10%OVER!
	if (M10)
	{
		if (rating >= 100.0f) {
			OVER_MESSAGE(10);
		}
	}

	//50%OVER!
	if (M50) {
		if (rating >= 500.0f) {
			OVER_MESSAGE(50);
		}
	}

	//100%OVER!
	if (M100) {
		if (rating >= 1000.0f) {
			OVER_MESSAGE(100);
		}
	}

	//150%OVER!
	if (M150) {
		if (rating >= 1500.0f) {
			OVER_MESSAGE(150);
		}
	}

	//200%OVER!
	if (M200) {
		if (rating >= 2000.0f) {
			OVER_MESSAGE(200);
		}
	}

	//250%OVER!
	if (M250) {
		if (rating >= 2500.0f) {
			OVER_MESSAGE(250);
		}
	}
}

float GetRating() {
	return rating;
}

void OVER_MESSAGE(int num) {
	if (mx < 1750) {
		Sprite_Draw(TEXTURE_INDEX_SCOR_MESSAGE, mx, 140, 0, 0, 95, 20);
		ImageNumberDraw(D3DXVECTOR2(nx, 500), D3DXVECTOR2(0.25f, 0.25f), num);
	}
	mx += madd;
	nx += nadd;

	if (mx < 1385) {
		mx = 1385;
		count++;
	}
	if (nx < 5400) {
		nx = 5400;
	}
	if (count > 180) {
		count = 0;
		madd *= -1.0f;
		nadd *= -1.0f;
	}
	if (mx > 1880 ) {
		mx = 1880;
		madd *= -1.0f;
		nadd *= -1.0f;

		switch (num)		//�\���̐���
		{
		case 10:
			M10 = false;
			break;

		case 50:
			M50 = false;
			break;

		case 100:
			M100 = false;
			break;

		case 150:
			M150 = false;
			break;

		case 200:
			M200 = false;
			break;

		case 250:
			M250 = false;
			break;
		}

	}
	if (nx > 6500) {
		nx = 5900;
	}

}