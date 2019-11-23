#pragma once
#include <Windows.h>
#include <mmsystem.h>
#include <d3dx9.h>
//#include <strsafe.h>

//--------------------------------------------------------------
#pragma warning( disable : 4996 ) // disable deprecated warning 
#pragma warning( default : 4996 ) 
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")



//--------------------------------------------------------------
struct xFILE {
	LPD3DXMESH			lpMesh;			//メッシュ
	D3DMATERIAL9*		Mat;			//マテリアルの配列
	LPDIRECT3DTEXTURE9*	Tex;			//テクスチャの配列
	DWORD				NumMaterial;	//マテリアルの数
	BOOL				used;			//データが入っているか示すフラグ
};


class XFile {
private:
	xFILE model;		//モデルデータを読み込むために必要な変数をまとめた構造体

public:
	D3DXVECTOR3 position;
	D3DXVECTOR3 scale = { 50,50,50 };
	D3DXVECTOR3 rotation;

	BOOL Init(const char* fileName, const char* textureName = "none");
	void Draw();
	void UnInit();

	D3DXVECTOR3 GetForward(); //正面を取得
	D3DXVECTOR3 GetRight();  //右側取得
	D3DXVECTOR3 GetUp();    //上取得
};