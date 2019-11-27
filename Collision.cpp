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


Hit BoxCollider2::Collider(Collider3D point, Collider3D plane) {
	Hit hit;						//hit判定と押し出す座標
	bool isOn = false;				//面の上にいるか
	bool isInside = false;			//面の内側にいるか

	const int VERTEX_NUM = 4;		//面の頂点数
	D3DXVECTOR3 v[VERTEX_NUM];		//面の頂点
	D3DXVECTOR3 planeCenter;        //面の中心
	D3DXVECTOR3 vD[VERTEX_NUM];		//面の辺のベクトル
	D3DXVECTOR3 sD[VERTEX_NUM];		//面の頂点と点(プレイヤー)のベクトル
	D3DXVECTOR3 t[VERTEX_NUM];		//面の中心と面の頂点のベクトル

	D3DXVECTOR3 cross[VERTEX_NUM];  //vDとsDとの外積
	float dot[VERTEX_NUM];			//crossとｔの内積

	D3DXVECTOR3 nor = { 0,1,0 };   //面の法線ベクトル

	//頂点座標を取得するための行列
	D3DXMATRIX vertexMatrixWorld;
	D3DXMATRIX mtxRot;
	D3DXMATRIX mtxTrs;

	//頂点座標を指すベクトルを計算する
	{
		//行列を初期化
		D3DXMatrixIdentity(&vertexMatrixWorld);

		//頂点へのベクトル
		{
			v[0].x = -plane.size.x / 2;
			v[0].y = plane.size.y / 2 + point.size.y / 2;
			v[0].z = plane.size.z / 2;

			v[1].x = plane.size.x / 2;
			v[1].y = plane.size.y / 2 + point.size.y / 2;
			v[1].z = plane.size.z / 2;

			v[2].x = plane.size.x / 2;
			v[2].y = plane.size.y / 2 + point.size.y / 2;
			v[2].z = -plane.size.z / 2;

			v[3].x = -plane.size.x / 2;
			v[3].y = plane.size.y / 2 + point.size.y / 2;
			v[3].z = -plane.size.z / 2;

			planeCenter = D3DXVECTOR3(0, plane.size.y / 2 + point.size.y / 2, 0);
		}

		//回転行列を作成
		D3DXMatrixRotationYawPitchRoll(&mtxRot, plane.rotation.y, plane.rotation.x, plane.rotation.z);
		D3DXMatrixMultiply(&vertexMatrixWorld, &vertexMatrixWorld, &mtxRot);

		//平行行列
		D3DXMatrixTranslation(&mtxTrs, plane.position.x, plane.position.y, plane.position.z);
		D3DXMatrixMultiply(&vertexMatrixWorld, &vertexMatrixWorld, &mtxTrs);

		for (int i = 0; i < VERTEX_NUM; i++) {
			D3DXVec3TransformCoord(&v[i], &v[i], &vertexMatrixWorld);
		}
		D3DXVec3TransformCoord(&planeCenter, &planeCenter, &vertexMatrixWorld);
	}

	//当たり判定に必要な情報を計算する
	{

		//面の辺のベクトルを求める
		vD[0] = Vec3Normalize(v[1] - v[0]);
		vD[1] = Vec3Normalize(v[2] - v[1]);
		vD[2] = Vec3Normalize(v[3] - v[2]);
		vD[3] = Vec3Normalize(v[0] - v[3]);

		//面の頂点と点(プレイヤー)のベクトルを求める
		sD[0] = Vec3Normalize(point.position - v[0]);
		sD[1] = Vec3Normalize(point.position - v[1]);
		sD[2] = Vec3Normalize(point.position - v[2]);
		sD[3] = Vec3Normalize(point.position - v[3]);

		//面の中心と面の頂点のベクトルを求める
		for (int i = 0; i < VERTEX_NUM; i++) {
			//頂点座標-面の中心
			t[i] = v[i] - planeCenter;
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


	//----------------------当たり判定----------------------------//
	{
		for (int i = 0; i < VERTEX_NUM; i++) {
			//外積の結果が0以上だったら面の内側にいる
			if (cross[i].y >= 0) {
				isInside = true;
			} else {
				isInside = false;
				break;
			}
		}
		if (isInside == true) {
			for (int i = 0; i < VERTEX_NUM; i++) {
				//内積の結果が1つでも0以下だったら面の下にいる
				if (dot[i] <= 0.05f) {
					isOn = true;
					break;
				} else {
					isOn = false;
				}
			}
		}
		//内積と外積の2つの結果がtrueだったら当たっている
		if (isInside == true && isOn == true) {
			hit.isHit = true;
		} else {
			hit.isHit = false;
		}
	}


	//埋まっていた場合に押し戻す
	{
		//法線ベクトルを求める
		if (hit.isHit == true) {
			//行列を初期化
			D3DXMatrixIdentity(&vertexMatrixWorld);

			//回転行列を作成
			D3DXMatrixRotationYawPitchRoll(&mtxRot, plane.rotation.y, plane.rotation.x, plane.rotation.z);
			D3DXMatrixMultiply(&vertexMatrixWorld, &vertexMatrixWorld, &mtxRot);

			nor = D3DXVECTOR3(vertexMatrixWorld._21, vertexMatrixWorld._22, vertexMatrixWorld._23);
		}

		//内積の結果が1つでも0.04以下があれば上に押し出す
		for (int i = 0; i < VERTEX_NUM; i++) {
			if (dot[i] <= 0.04f) {
				hit.addPosition = nor * 0.05f;
			} else {
				hit.addPosition = nor - nor;;
			}
		}
	}

	return hit;
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
