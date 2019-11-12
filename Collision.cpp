#include <Windows.h>
#include "common.h"
#include "mydirect3d.h"
#include "texture.h"
#include "sprite.h"
#include <d3dx9.h>
#include"debug_font.h"
#include"Collision.h"

bool BoxCollider::Collider(Collider3D c1, Collider3D c2) {
	/*if (c1.position.x + c1.size.x / 2 >= c2.position.x - c2.size.x / 2 && c1.position.x - c1.size.x / 2 <= c2.position.x + c2.size.x / 2 &&
		c1.position.y + c1.size.y / 2 >= c2.position.y - c2.size.y / 2 && c1.position.y - c1.size.y / 2 <= c2.position.y + c2.size.y / 2 &&
		c1.position.z + c1.size.z / 2 >= c2.position.z - c2.size.z / 2 && c1.position.z - c1.size.z / 2 <= c2.position.z + c2.size.z / 2
		) {
		return true;
	}*/

	//三角関数を使った斜めの当たり判定
	if (c2.rotation.x == 0 && c2.rotation.z == 0) {
		if (c1.position.x + c1.size.x / 2 >= c2.position.x - c2.size.x / 2 && c1.position.x - c1.size.x / 2 <= c2.position.x + c2.size.x / 2 &&
			c1.position.y + c1.size.y / 2 >= c2.position.y - c2.size.y / 2 && c1.position.y - c1.size.y / 2 <= c2.position.y + c2.size.y / 2 &&
			c1.position.z + c1.size.z / 2 >= c2.position.z - c2.size.z / 2 && c1.position.z - c1.size.z / 2 <= c2.position.z + c2.size.z / 2
			) {
			return true;
		}
	} else {
		if (tanf(-c2.rotation.z*1.44f)* (c2.position.x - c1.position.x) + c2.position.y > c1.position.y - c1.size.y * 2 &&
			tanf(c2.rotation.x*1.44f)*(c2.position.z - c1.position.z) + c2.position.y + 0.5f > c1.position.y - c1.size.y * 2 &&
			c1.position.x + c1.size.x / 2 >= c2.position.x - c2.size.x / 2 && c1.position.x - c1.size.x / 2 <= c2.position.x + c2.size.x / 2 &&
			c1.position.z + c1.size.z / 2 >= c2.position.z - c2.size.z / 2 && c1.position.z - c1.size.z / 2 <= c2.position.z + c2.size.z / 2
			) {

			return true;
		}
	}
	return false;
}


bool BoxCollider2::Collider(Collider3D c1, Collider3D c2) {
	bool isHit = false;

	const int VERTEX_NUM = 4;		//面の頂点数
	D3DXVECTOR3 v[VERTEX_NUM];		//面の頂点
	D3DXVECTOR3 vD[VERTEX_NUM];		//面の辺のベクトル
	D3DXVECTOR3 sD[VERTEX_NUM];		//面の頂点と点(プレイヤー)のベクトル
	D3DXVECTOR3 t[VERTEX_NUM];		//面の中心と面の頂点のベクトル

	D3DXVECTOR3 cross[VERTEX_NUM];  //vDとsDとの外積
	float dot[VERTEX_NUM];			//crossとｔの内積


	//面の正面方向取得
	D3DXVECTOR3 c2Forward;
	c2Forward.x = sinf(c2.rotation.y);
	c2Forward.z = cosf(c2.rotation.y);
	c2Forward.y = -sinf(c2.rotation.x);
	c2Forward = Vec3Normalize(c2Forward);


	//面の右側取得
	D3DXVECTOR3 c2Right; 
	c2Right.x = cosf(c2.rotation.y);
	c2Right.y = sinf(c2.rotation.z);
	c2Right.z = -sinf(c2.rotation.y);
	c2Right = Vec3Normalize(c2Right);


	//当たり判定に必要な情報を計算する
	{
		//頂点座標を求める
		v[0] = (c2Forward*(c2.size.z / 2)) + (c2Right*(-c2.size.x / 2))+ c2.position;
		v[1] = (c2Forward*(c2.size.z / 2)) + (c2Right*(c2.size.x / 2)) + c2.position;
		v[2] = (c2Forward*(-c2.size.z / 2)) + (c2Right*(c2.size.x / 2)) + c2.position;
		v[3] = (c2Forward*(-c2.size.z / 2)) + (c2Right*(-c2.size.x / 2))+ c2.position;

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
			t[i] = c2.position - v[i];
		}


		//内積と外積を計算する
		for (int i = 0; i < VERTEX_NUM; i++) {
			//辺のベクトルと頂点と点(プレイヤー)の距離のベクトルの外積を求める
			cross[i] = { vD[i].y * sD[i].z - vD[i].z * sD[i].y, //X
						 vD[i].z * sD[i].x - vD[i].x * sD[i].z, //Y
						 vD[i].x * sD[i].y - vD[i].y * sD[i].x  //Z
			};
			
			//外積で求めた法線ベクトル と 面の中心と各頂点のベクトルの内積を求める
			dot[i] = D3DXVec3Dot(&cross[i], &t[i]);
		}
	}


	//当たり判定
	for (int i = 0; i < VERTEX_NUM; i++) {
		//外積と内積が両方0以上だったら面の上に乗っている
		if (cross[i].y  >=0 && dot[i]>=0) {
			isHit = true;
		} else {
			isHit = false;
			break;
		}
	}
	for (int i = 0; i < VERTEX_NUM; i++) {
		DebugFont_Draw(1, 1 + i * 25, "cross%d:x%lf, y%lf, z%lf", i, cross[i].x, cross[i].y, cross[i].z);
		DebugFont_Draw(1, 150+i*25, "dot%lf", dot[i]);
	}
	
	return isHit;
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
