

#include <d3dx9.h>
#include <math.h>
#include "mydirect3d.h"
#include "texture.h"


/*------------------------------------------------------------------------------
   �\���̐錾
------------------------------------------------------------------------------*/
// �QD�|���S�����_�\����
typedef struct Vertex2D_tag
{
    D3DXVECTOR4 position; // ���_���W�i���W�ϊ��ςݒ��_�j
	D3DCOLOR color;
	D3DXVECTOR2 texcoord;
} Vertex2D;
#define FVF_VERTEX2D (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1) // �QD�|���S�����_�t�H�[�}�b�g


/*------------------------------------------------------------------------------
   �O���[�o���ϐ��錾
------------------------------------------------------------------------------*/
static D3DCOLOR g_Color = 0xffffffff;
// static D3DCOLOR g_Color = D3DCOLOR_RGBA(255, 255, 255, 255);



/*------------------------------------------------------------------------------
   �֐���`
------------------------------------------------------------------------------*/

// �X�v���C�g�|���S���̒��_�J���[�ݒ�
void Sprite_SetColor(D3DCOLOR color)
{
	g_Color = color;
}


// �X�v���C�g�`��
// ���e�N�X�`���؂��蕝�A�����Ɠ����傫���̃X�v���C�g���w����W�ɕ`�悷��
void Sprite_Draw(TextureIndex texture_index, float dx, float dy, int tx, int ty,int tw, int th, float sx, float sy)
{
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D_GetDevice();
    if( !pDevice ) return;

	float w = (float)Texture_GetWidth(texture_index);
	float h = (float)Texture_GetHeight(texture_index);

    // UV���W�v�Z
    float u[2], v[2];
	u[0] = (float)tx / w;
	v[0] = (float)ty / h;
	u[1] = (float)(tx + tw) / w;
	v[1] = (float)(ty + th) / h;

    Vertex2D vertexes[] = {
        { D3DXVECTOR4((dx      - 0.5f)*sx, (dy      - 0.5f)*sy, 0.0f, 1.0f), g_Color, D3DXVECTOR2(u[0], v[0]) },
        { D3DXVECTOR4((dx + tw - 0.5f)*sx, (dy      - 0.5f)*sy, 0.0f, 1.0f), g_Color, D3DXVECTOR2(u[1], v[0]) },
		{ D3DXVECTOR4((dx      - 0.5f)*sx, (dy + th - 0.5f)*sy, 0.0f, 1.0f), g_Color, D3DXVECTOR2(u[0], v[1]) },
		{ D3DXVECTOR4((dx + tw - 0.5f)*sx, (dy + th - 0.5f)*sy, 0.0f, 1.0f), g_Color, D3DXVECTOR2(u[1], v[1]) },
    };

    pDevice->SetFVF(FVF_VERTEX2D);
	pDevice->SetTexture(0, Texture_GetTexture(texture_index));
    pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vertexes, sizeof(Vertex2D));
}

//���ŗp�X�v���C�g�`��
void Sprite_Draw2(TextureIndex texture_index, float dx, float dy, int tx, int ty, int tw, int th, int Alpha)
{
	D3DCOLOR    color;  // ���_�J���[

// ���������������邩�ǂ����𔻒f���A���_�J���[������
	if (Alpha == 255) color = D3DCOLOR_XRGB(255, 255, 255);
	else                color = D3DCOLOR_RGBA(255, 255, 255, Alpha);

	LPDIRECT3DDEVICE9 pDevice = MyDirect3D_GetDevice();
	if (!pDevice) return;

	float w = (float)Texture_GetWidth(texture_index);
	float h = (float)Texture_GetHeight(texture_index);

	// UV���W�v�Z
	float u[2], v[2];
	u[0] = (float)tx / w;
	v[0] = (float)ty / h;
	u[1] = (float)(tx + tw) / w;
	v[1] = (float)(ty + th) / h;

	Vertex2D vertexes[] = {
		{ D3DXVECTOR4(dx - 0.5f, dy - 0.5f, 0.0f, 1.0f), color, D3DXVECTOR2(u[0], v[0]) },
		{ D3DXVECTOR4(dx + tw - 0.5f, dy - 0.5f, 0.0f, 1.0f), color, D3DXVECTOR2(u[1], v[0]) },
		{ D3DXVECTOR4(dx - 0.5f, dy + th - 0.5f, 0.0f, 1.0f), color, D3DXVECTOR2(u[0], v[1]) },
		{ D3DXVECTOR4(dx + tw - 0.5f, dy + th - 0.5f, 0.0f, 1.0f), color, D3DXVECTOR2(u[1], v[1]) },
	};

	pDevice->SetFVF(FVF_VERTEX2D);
	pDevice->SetTexture(0, Texture_GetTexture(texture_index));
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vertexes, sizeof(Vertex2D));
}
