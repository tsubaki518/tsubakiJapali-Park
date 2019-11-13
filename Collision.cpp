#include <Windows.h>
#include "common.h"
#include "mydirect3d.h"
#include "texture.h"
#include "sprite.h"
#include <d3dx9.h>
#include"debug_font.h"
#include"Collision.h"

bool BoxCollider::Collider(Collider3D c1, Collider3D c2) {
	if (c1.position.x + c1.size.x / 2 >= c2.position.x - c2.size.x / 2 && c1.position.x - c1.size.x / 2 <= c2.position.x + c2.size.x / 2 &&
		c1.position.y + c1.size.y / 2 >= c2.position.y - c2.size.y / 2 && c1.position.y - c1.size.y / 2 <= c2.position.y + c2.size.y / 2 &&
		c1.position.z + c1.size.z / 2 >= c2.position.z - c2.size.z / 2 && c1.position.z - c1.size.z / 2 <= c2.position.z + c2.size.z / 2
		) {
		return true;
	}

	return false;
}


bool BoxCollider2::Collider(Collider3D c1, Collider3D c2) {
	bool isOn = false;
	bool isInside = false;

	const int VERTEX_NUM = 4;		//面の頂点数
	D3DXVECTOR3 v[VERTEX_NUM];		//面の頂点
	D3DXVECTOR3 vD[VERTEX_NUM];		//面の辺のベクトル
	D3DXVECTOR3 sD[VERTEX_NUM];		//面の頂点と点(プレイヤー)のベクトル
	D3DXVECTOR3 t[VERTEX_NUM];		//面の中心と面の頂点のベクトル

	D3DXVECTOR3 cross[VERTEX_NUM];  //vDとsDとの外積
	float dot[VERTEX_NUM];			//crossとｔの内積


	D3DXMATRIX vertexMatrixWorld;    //頂点の行列
	D3DXMATRIX mtxRot;
	D3DXMATRIX mtxTrs;

	{
		//行列を初期化
		D3DXMatrixIdentity(&vertexMatrixWorld);

		//頂点へのベクトル
		{
			v[0].x = -c2.size.x / 2;
			v[0].y = c2.size.y / 2+c1.size.y/2;
			v[0].z = c2.size.z / 2;

			v[1].x = c2.size.x / 2;
			v[1].y = c2.size.y / 2 + c1.size.y / 2;
			v[1].z = c2.size.z / 2;

			v[2].x = c2.size.x / 2;
			v[2].y = c2.size.y / 2 + c1.size.y / 2;
			v[2].z = -c2.size.z / 2;

			v[3].x = -c2.size.x / 2;
			v[3].y = c2.size.y / 2 + c1.size.y / 2;
			v[3].z = -c2.size.z / 2;
		}

		//回転行列を作成
		D3DXMatrixRotationYawPitchRoll(&mtxRot, c2.rotation.y, c2.rotation.x, c2.rotation.z);
		D3DXMatrixMultiply(&vertexMatrixWorld, &vertexMatrixWorld, &mtxRot);

		//平行行列
		D3DXMatrixTranslation(&mtxTrs, c2.position.x, c2.position.y, c2.position.z);
		D3DXMatrixMultiply(&vertexMatrixWorld, &vertexMatrixWorld, &mtxTrs);

		for (int i = 0; i < VERTEX_NUM; i++) {
			D3DXVec3TransformCoord(&v[i], &v[i], &vertexMatrixWorld);
		}
	}

	//当たり判定に必要な情報を計算する
	{

		//面の辺のベクトルを求める
		vD[0] = Vec3Normalize(v[1] - v[0]);
		vD[1] = Vec3Normalize(v[2] - v[1]);
		vD[2] = Vec3Normalize(v[3] - v[2]);
		vD[3] = Vec3Normalize(v[0] - v[3]);

		//面の頂点と点(プレイヤー)のベクトルを求める
		sD[0] = Vec3Normalize(c1.position - v[0]);
		sD[1] = Vec3Normalize(c1.position - v[1]);
		sD[2] = Vec3Normalize(c1.position - v[2]);
		sD[3] = Vec3Normalize(c1.position - v[3]);

		//面の中心と面の頂点のベクトルを求める
		for (int i = 0; i < VERTEX_NUM; i++) {
			t[i] =  v[i] - (c2.position+D3DXVECTOR3(0,c2.size.y/2+ c1.size.y / 2, 0));
		}


		//内積と外積を計算する
		for (int i = 0; i < VERTEX_NUM; i++) {
			//辺のベクトルと頂点と点(プレイヤー)の距離のベクトルの外積を求める
			cross[i] = { vD[i].y * sD[i].z - vD[i].z * sD[i].y, //X
						 vD[i].z * sD[i].x - vD[i].x * sD[i].z, //Y
						 vD[i].x * sD[i].y - vD[i].y * sD[i].x  //Z
			};
			//外積で求めた法線ベクトル と 面の中心と頂点のベクトルの内積を求める
			dot[i] = D3DXVec3Dot(&cross[i], &t[i]);
		}
	}


	//当たり判定
	for (int i = 0; i < VERTEX_NUM; i++) {
		//外積と内積が両方0以上だったら面の上に乗っている
		if (cross[i].y  >=0) {
			isInside = true;
		} else {
			isInside = false;
			break;
		}
	}
	for (int i = 0; i < VERTEX_NUM; i++) {
		if (dot[i] <= 0) {
			isOn = true;
			break;
		} else {
			isOn = false;
		}
	}
	

	if (isOn == true && isInside == true) {
		return true;
	}
	
	return false;
}

D3DXVECTOR3 Vec3Normalize(D3DXVECTOR3 pV)
{
	D3DXVECTOR3 pOut;
	double len;
	double x, y, z;

	x = (double)(pV.x);
	y = (double)(pV.y);
	z = (double)(pV.z);
	len = sqrt(x * x + y * y + z * z);


	len = 1.0 / len;
	x *= len;
	y *= len;
	z *= len;

	pOut.x = (float)x;
	pOut.y = (float)y;
	pOut.z = (float)z;

	return pOut;
}
