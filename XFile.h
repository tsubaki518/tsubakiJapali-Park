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
	LPD3DXMESH			lpMesh;			//���b�V��
	D3DMATERIAL9*		Mat;			//�}�e���A���̔z��
	LPDIRECT3DTEXTURE9*	Tex;			//�e�N�X�`���̔z��
	DWORD				NumMaterial;	//�}�e���A���̐�
	BOOL				used;			//�f�[�^�������Ă��邩�����t���O
};


class XFile {
private:
	xFILE model;		//���f���f�[�^��ǂݍ��ނ��߂ɕK�v�ȕϐ����܂Ƃ߂��\����

public:

	//���f���f�[�^��ǂݍ���   
	BOOL Init(const char* fileName, const char* textureName = "none");
	void Draw();
	void UnInit();

};