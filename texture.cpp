


#include <d3dx9.h>
#include "debug_Printf.h"
#include "mydirect3d.h"
#include "texture.h"
#include "common.h"


/*------------------------------------------------------------------------------
   構造体宣言
------------------------------------------------------------------------------*/
#define TEXTURE_FILENAME_MAX (64) // テクスチャファイル名最大文字数（パス、NULL文字含む）

// テクスチャファイル管理構造体
typedef struct TextureFile_tag
{
	char filename[TEXTURE_FILENAME_MAX]; // テクスチャファイル名
	int width;  // テクスチャ解像度横幅
	int height; // テクスチャ解像度縦幅
} TextureFile;


/*------------------------------------------------------------------------------
   定数定義
------------------------------------------------------------------------------*/
// 読み込みテクスチャ情報
static const TextureFile g_TextureFiles[] = {
{ "asset/texture/images.jpg", 225, 225 },
{ "asset/texture/チェック床.png", 225, 225 },
{ "asset/texture/赤床.png", 225, 225 },
{"asset/texture/title.png",SCREEN_WIDTH,SCREEN_HEIGHT},
{"asset/texture/title1.png",SCREEN_WIDTH,SCREEN_HEIGHT},
{"asset/texture/number03.png",1582,140},
{"asset/texture/選択バー.png",SCREEN_WIDTH / 5.5,SCREEN_HEIGHT / 25 * 2},
{"asset/texture/顔素材セカンド.png",SCREEN_HEIGHT,SCREEN_HEIGHT},
{"asset/texture/選択肢01.png",SCREEN_WIDTH/1.7,SCREEN_HEIGHT/15},
{"asset/texture/カウントダウン１.png",500,100},
{"asset/texture/カウントダウン２.png",500,100},
{"asset/texture/カウントダウン３.png",500,100},
{"asset/texture/ゴール！.png",500,200},
{"asset/texture/スタート！.png",500,200},
{"asset/texture/メーター.png",316,66},
{"asset/texture/GameUI.png",SCREEN_WIDTH,SCREEN_HEIGHT},

{"asset/texture/ソクテイカンリョウ!.png",717,65},
{"asset/texture/ソクテイチュウ.png",717,65},
{"asset/texture/ボードの上に乗り.png",594,107},
{"asset/texture/どちらかがジャンプすると～.png",594,107},
{"asset/texture/プレイヤーエントリー.png",717,65},
{"asset/texture/プレイヤーを探しています.png",369,135},
{"asset/texture/共通背景.png",1920,1080},
{"asset/texture/参加プレイヤーを認識.png",353,108},
{"asset/texture/情報アイコン.png",158,162},
{"asset/texture/立ち絵その１.png",366,475},

{"asset/texture/ゲームに参加するプレイヤーは～.png",624,108},
{"asset/texture/OK!.png",258,122},
{"asset/texture/ジャンプ！.png",177,175},
{"asset/texture/リング.png",163,162},

{"asset/texture/2Dイヌ02.png",150,150},
{"asset/texture/2Dウサギ.png",150,150},
{"asset/texture/2Dクマ.png",150,150},
{"asset/texture/2Dハムスター02.png",150,150},

{"asset/texture/集中線.png",SCREEN_WIDTH*3,SCREEN_HEIGHT},
{ "asset/texture/％OVER.png",190,40},

{"asset/texture/リザルトワク.png",SCREEN_WIDTH,SCREEN_HEIGHT},
{"asset/texture/リザルト用カットイン下.png",SCREEN_WIDTH,SCREEN_HEIGHT},
{"asset/texture/リザルト用カットイン上.png",SCREEN_WIDTH,SCREEN_HEIGHT},
{"asset/texture/称号ワク.png",SCREEN_WIDTH,SCREEN_HEIGHT},
{"asset/texture/ランクイン目標.png",SCREEN_WIDTH/5,SCREEN_HEIGHT/5},

{"asset/texture/DL00002.jpg",100,100},

{"asset/texture/1st.png",269,171},
{"asset/texture/2nd.png",269,171},

{"asset/texture/メダリスト背景2.png",SCREEN_WIDTH,SCREEN_HEIGHT},
{"asset/texture/メダリスト見出し.png",SCREEN_WIDTH,SCREEN_HEIGHT},
{"asset/texture/シロワク03.png",SCREEN_WIDTH,SCREEN_HEIGHT * 3 / 20},
{"asset/texture/ゴールド.png",SCREEN_HEIGHT * 3 / 20,SCREEN_HEIGHT * 3 / 20},
{"asset/texture/シルバー.png",SCREEN_HEIGHT * 3 / 20,SCREEN_HEIGHT * 3 / 20},
{"asset/texture/ブロンズ.png",SCREEN_HEIGHT * 3 / 20,SCREEN_HEIGHT * 3 / 20},
{"asset/texture/アニメーション素材.png",SCREEN_WIDTH,SCREEN_HEIGHT / 1.5},

{"asset/texture/スタッフクレジット.png",SCREEN_WIDTH,SCREEN_HEIGHT},

};
// 読み込みテクスチャ数
static const int TEXTURE_FILE_COUNT = sizeof(g_TextureFiles) / sizeof(g_TextureFiles[0]);
// static const int TEXTURE_FILE_COUNT = ARRAYSIZE(g_TextureFiles); // required Windows.h

// 読み込みテクスチャ数とテクスチャ管理番号列挙数に差があった場合コンパイルエラーとする
static_assert(TEXTURE_INDEX_MAX == TEXTURE_FILE_COUNT, "TEXTURE_INDEX_MAX != TEXTURE_FILE_COUNT");


/*------------------------------------------------------------------------------
   グローバル変数宣言
------------------------------------------------------------------------------*/
static LPDIRECT3DTEXTURE9 g_pTextures[TEXTURE_FILE_COUNT] = {}; // テクスチャインターフェース管理配列


/*------------------------------------------------------------------------------
   関数定義
------------------------------------------------------------------------------*/

// テクスチャの読み込み
int Texture_Load(void)
{   
    LPDIRECT3DDEVICE9 pDevice = MyDirect3D_GetDevice();
	if( !pDevice ) {
		return TEXTURE_FILE_COUNT;
	}

	int failed_count = 0;

	for( int i = 0; i < TEXTURE_FILE_COUNT; i++ ) {
		
		if( FAILED(D3DXCreateTextureFromFile(pDevice, g_TextureFiles[i].filename, &g_pTextures[i])) ) {
            // DebugPrintf("テクスチャの読み込みに失敗 ... %s\n", g_TextureFiles[i].filename);
			failed_count++;
		}
	}

	return failed_count;
}

// テクスチャの解放
void Texture_Release(void)
{
	for( int i = 0; i < TEXTURE_FILE_COUNT; i++ ) {
		
		if( g_pTextures[i] ) {
			g_pTextures[i]->Release();
			g_pTextures[i] = NULL;
		}
	}
}

// テクスチャインターフェースの取得
LPDIRECT3DTEXTURE9 Texture_GetTexture(TextureIndex index)
{
    if( index < 0 || index >= TEXTURE_INDEX_MAX ) {
        return NULL;
    }

	return g_pTextures[index];
}

// テクスチャ解像度幅の取得
int Texture_GetWidth(TextureIndex index)
{
    if( index < 0 || index >= TEXTURE_INDEX_MAX ) {
        return NULL;
    }

	return g_TextureFiles[index].width;
}

// テクスチャ解像度高さの取得
int Texture_GetHeight(TextureIndex index)
{
    if( index < 0 || index >= TEXTURE_INDEX_MAX ) {
        return NULL;
    }

	return g_TextureFiles[index].height;
}
