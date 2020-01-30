


#include <d3dx9.h>
#include "debug_Printf.h"
#include "mydirect3d.h"
#include "texture.h"
#include "common.h"


/*------------------------------------------------------------------------------
   �\���̐錾
------------------------------------------------------------------------------*/
#define TEXTURE_FILENAME_MAX (64) // �e�N�X�`���t�@�C�����ő啶�����i�p�X�ANULL�����܂ށj

// �e�N�X�`���t�@�C���Ǘ��\����
typedef struct TextureFile_tag
{
	char filename[TEXTURE_FILENAME_MAX]; // �e�N�X�`���t�@�C����
	int width;  // �e�N�X�`���𑜓x����
	int height; // �e�N�X�`���𑜓x�c��
} TextureFile;


/*------------------------------------------------------------------------------
   �萔��`
------------------------------------------------------------------------------*/
// �ǂݍ��݃e�N�X�`�����
static const TextureFile g_TextureFiles[] = {
{ "asset/texture/images.jpg", 225, 225 },
{ "asset/texture/�`�F�b�N��.png", 225, 225 },
{ "asset/texture/�ԏ�.png", 225, 225 },
{"asset/texture/title.png",SCREEN_WIDTH,SCREEN_HEIGHT},
{"asset/texture/title1.png",SCREEN_WIDTH,SCREEN_HEIGHT},
{"asset/texture/number03.png",1582,140},
{"asset/texture/�I���o�[.png",SCREEN_WIDTH / 5.5,SCREEN_HEIGHT / 25 * 2},
{"asset/texture/��f�ރZ�J���h.png",SCREEN_HEIGHT,SCREEN_HEIGHT},
{"asset/texture/�I����01.png",SCREEN_WIDTH/1.7,SCREEN_HEIGHT/15},
{"asset/texture/�J�E���g�_�E���P.png",500,100},
{"asset/texture/�J�E���g�_�E���Q.png",500,100},
{"asset/texture/�J�E���g�_�E���R.png",500,100},
{"asset/texture/�S�[���I.png",500,200},
{"asset/texture/�X�^�[�g�I.png",500,200},
{"asset/texture/���[�^�[.png",316,66},
{"asset/texture/GameUI.png",SCREEN_WIDTH,SCREEN_HEIGHT},

{"asset/texture/�\�N�e�C�J�������E!.png",717,65},
{"asset/texture/�\�N�e�C�`���E.png",717,65},
{"asset/texture/�{�[�h�̏�ɏ��.png",594,107},
{"asset/texture/�ǂ��炩���W�����v����Ɓ`.png",594,107},
{"asset/texture/�v���C���[�G���g���[.png",717,65},
{"asset/texture/�v���C���[��T���Ă��܂�.png",369,135},
{"asset/texture/���ʔw�i.png",1920,1080},
{"asset/texture/�Q���v���C���[��F��.png",353,108},
{"asset/texture/���A�C�R��.png",158,162},
{"asset/texture/�����G���̂P.png",366,475},

{"asset/texture/�Q�[���ɎQ������v���C���[�́`.png",624,108},
{"asset/texture/OK!.png",258,122},
{"asset/texture/�W�����v�I.png",177,175},
{"asset/texture/�����O.png",163,162},

{"asset/texture/2D�C�k02.png",150,150},
{"asset/texture/2D�E�T�M.png",150,150},
{"asset/texture/2D�N�}.png",150,150},
{"asset/texture/2D�n���X�^�[02.png",150,150},

{"asset/texture/�W����.png",SCREEN_WIDTH*3,SCREEN_HEIGHT},
{ "asset/texture/��OVER.png",190,40},

{"asset/texture/���U���g���N.png",SCREEN_WIDTH,SCREEN_HEIGHT},
{"asset/texture/���U���g�p�J�b�g�C����.png",SCREEN_WIDTH,SCREEN_HEIGHT},
{"asset/texture/���U���g�p�J�b�g�C����.png",SCREEN_WIDTH,SCREEN_HEIGHT},
{"asset/texture/�̍����N.png",SCREEN_WIDTH,SCREEN_HEIGHT},
{"asset/texture/�����N�C���ڕW.png",SCREEN_WIDTH/5,SCREEN_HEIGHT/5},

{"asset/texture/DL00002.jpg",100,100},

{"asset/texture/1st.png",269,171},
{"asset/texture/2nd.png",269,171},

{"asset/texture/���_���X�g�w�i2.png",SCREEN_WIDTH,SCREEN_HEIGHT},
{"asset/texture/���_���X�g���o��.png",SCREEN_WIDTH,SCREEN_HEIGHT},
{"asset/texture/�V�����N03.png",SCREEN_WIDTH,SCREEN_HEIGHT * 3 / 20},
{"asset/texture/�S�[���h.png",SCREEN_HEIGHT * 3 / 20,SCREEN_HEIGHT * 3 / 20},
{"asset/texture/�V���o�[.png",SCREEN_HEIGHT * 3 / 20,SCREEN_HEIGHT * 3 / 20},
{"asset/texture/�u�����Y.png",SCREEN_HEIGHT * 3 / 20,SCREEN_HEIGHT * 3 / 20},
{"asset/texture/�A�j���[�V�����f��.png",SCREEN_WIDTH,SCREEN_HEIGHT / 1.5},

{"asset/texture/�X�^�b�t�N���W�b�g.png",SCREEN_WIDTH,SCREEN_HEIGHT},

};
// �ǂݍ��݃e�N�X�`����
static const int TEXTURE_FILE_COUNT = sizeof(g_TextureFiles) / sizeof(g_TextureFiles[0]);
// static const int TEXTURE_FILE_COUNT = ARRAYSIZE(g_TextureFiles); // required Windows.h

// �ǂݍ��݃e�N�X�`�����ƃe�N�X�`���Ǘ��ԍ��񋓐��ɍ����������ꍇ�R���p�C���G���[�Ƃ���
static_assert(TEXTURE_INDEX_MAX == TEXTURE_FILE_COUNT, "TEXTURE_INDEX_MAX != TEXTURE_FILE_COUNT");


/*------------------------------------------------------------------------------
   �O���[�o���ϐ��錾
------------------------------------------------------------------------------*/
static LPDIRECT3DTEXTURE9 g_pTextures[TEXTURE_FILE_COUNT] = {}; // �e�N�X�`���C���^�[�t�F�[�X�Ǘ��z��


/*------------------------------------------------------------------------------
   �֐���`
------------------------------------------------------------------------------*/

// �e�N�X�`���̓ǂݍ���
int Texture_Load(void)
{   
    LPDIRECT3DDEVICE9 pDevice = MyDirect3D_GetDevice();
	if( !pDevice ) {
		return TEXTURE_FILE_COUNT;
	}

	int failed_count = 0;

	for( int i = 0; i < TEXTURE_FILE_COUNT; i++ ) {
		
		if( FAILED(D3DXCreateTextureFromFile(pDevice, g_TextureFiles[i].filename, &g_pTextures[i])) ) {
            // DebugPrintf("�e�N�X�`���̓ǂݍ��݂Ɏ��s ... %s\n", g_TextureFiles[i].filename);
			failed_count++;
		}
	}

	return failed_count;
}

// �e�N�X�`���̉��
void Texture_Release(void)
{
	for( int i = 0; i < TEXTURE_FILE_COUNT; i++ ) {
		
		if( g_pTextures[i] ) {
			g_pTextures[i]->Release();
			g_pTextures[i] = NULL;
		}
	}
}

// �e�N�X�`���C���^�[�t�F�[�X�̎擾
LPDIRECT3DTEXTURE9 Texture_GetTexture(TextureIndex index)
{
    if( index < 0 || index >= TEXTURE_INDEX_MAX ) {
        return NULL;
    }

	return g_pTextures[index];
}

// �e�N�X�`���𑜓x���̎擾
int Texture_GetWidth(TextureIndex index)
{
    if( index < 0 || index >= TEXTURE_INDEX_MAX ) {
        return NULL;
    }

	return g_TextureFiles[index].width;
}

// �e�N�X�`���𑜓x�����̎擾
int Texture_GetHeight(TextureIndex index)
{
    if( index < 0 || index >= TEXTURE_INDEX_MAX ) {
        return NULL;
    }

	return g_TextureFiles[index].height;
}
