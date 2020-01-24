
#ifndef TEXTURE_H_
#define TEXTURE_H_


#include <d3d9.h>

/*------------------------------------------------------------------------------
   テクスチャ列挙型
------------------------------------------------------------------------------*/
// テクスチャ管理番号
enum TextureIndex
{
	TEXTURE_INDEX_ICE,
	TEXTURE_INDEX_CHECK_FLOOR,
	TEXTURE_INDEX_RED_FLOOR,
	TEXTURE_INDEX_TITLE,
	TEXTURE_INDEX_TITLE1,
	TEXTURE_INDEX_NUMBER,
	TEXTURE_INDEX_BAR,
	TEXTURE_INDEX_FACE,
	TEXTURE_INDEX_SELECT,
	TEXTURE_INDEX_COUNT_DOWN1,
	TEXTURE_INDEX_COUNT_DOWN2,
	TEXTURE_INDEX_COUNT_DOWN3,
	TEXTURE_INDEX_GOAL,
	TEXTURE_INDEX_START,
	TEXTURE_INDEX_METER,
	TEXTURE_INDEX_UI,

	TEXTURE_INDEX_SOKUTEIKANNRYOU,
	TEXTURE_INDEX_SOKUTEITYU,
	TEXTURE_INDEX_SONOMAMABODO,
	TEXTURE_INDEX_DOTIRAKAZYANPU,
	TEXTURE_INDEX_PUREIYAENTORI,
	TEXTURE_INDEX_PUREIYAWOSAGASITERU,
	TEXTURE_INDEX_KYOUTUUHAIKEI,
	TEXTURE_INDEX_SANKAPUREIYAWONINSIKI,
	TEXTURE_INDEX_ZYOUHOUAIKONN,
	TEXTURE_INDEX_TATIE,

	TEXTURE_INDEX_GAMENISANKASURUPUREIYA,
	TEXTURE_INDEX_OK,
	TEXTURE_INDEX_JUMP,
	TEXTURE_INDEX_RING,

	TEXTURE_INDEX_ICON_DOG,
	TEXTURE_INDEX_ICON_RABBIT,
	TEXTURE_INDEX_ICON_BEAR,
	TEXTURE_INDEX_ICON_HAMSTER,

	TEXTURE_INDEX_TEZUKA_LINE,//集中線

	TEXTURE_INDEX_RESULTSCORE,
	TEXTURE_INDEX_RESULT_CUTIN_DOWN,
	TEXTURE_INDEX_RESULT_CUTIN_UP,
	TEXTURE_INDEX_RESULT_EPITHET,

	TEXTURE_INDEX_SKY,

	TEXTURE_INDEX_1ST,
	TEXTURE_INDEX_2ND,

    TEXTURE_INDEX_MAX
};


/*------------------------------------------------------------------------------
   関数のプロトタイプ宣言
------------------------------------------------------------------------------*/
// テクスチャの読み込み
//
// 戻り値:読み込めなかった数
//
int Texture_Load(void);

// テクスチャの解放
void Texture_Release(void);

// テクスチャインターフェースの取得
//
// 戻り値:テクスチャインターフェース
//        ただし存在しないindexを指定した場合、NULL
LPDIRECT3DTEXTURE9 Texture_GetTexture(TextureIndex index);

// テクスチャ解像度幅の取得
//
// 引数 ... index テクスチャ管理番号
//
int Texture_GetWidth(TextureIndex index);

// テクスチャ解像度高さの取得
//
// 引数 ... index テクスチャ管理番号
//
int Texture_GetHeight(TextureIndex index);


#endif // TEXTURE_H_
