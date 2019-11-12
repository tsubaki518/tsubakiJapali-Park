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

	const int VERTEX_NUM = 4;
	D3DXVECTOR3 v[VERTEX_NUM];
	D3DXVECTOR3 vD[VERTEX_NUM];
	D3DXVECTOR3 sD[VERTEX_NUM];
	D3DXVECTOR3 cross[VERTEX_NUM];
	float dot[VERTEX_NUM];

	D3DXVECTOR3 t[VERTEX_NUM];

	D3DXVECTOR3 c2Forward;//正面
	c2Forward.x = sinf(c2.rotation.y);
	c2Forward.z = cosf(c2.rotation.y);
	c2Forward.y = -sinf(c2.rotation.x);
	c2Forward = Vec3Normalize(c2Forward);


	D3DXVECTOR3 c2Right; 
	c2Right.x = cosf(c2.rotation.y);
	c2Right.y = sinf(c2.rotation.z);
	c2Right.z = -sinf(c2.rotation.y);
	c2Right = Vec3Normalize(c2Right);


	D3DXVECTOR3 c2Up;
	c2Up.x = -sinf(c2.rotation.z);
	c2Up.y = cosf(c2.rotation.x);
	c2Up.z = sinf(c2.rotation.x);
	c2Up = Vec3Normalize(c2Up);

	//内積計算
	{
		//頂点座標を求める
		v[0] = (c2Forward*(-c2.size.z / 2)) + (c2Right*(-c2.size.x / 2)) + (c2Up*(c2.size.y / 2)) + c2.position;
		v[1] = (c2Forward*(-c2.size.z / 2)) + (c2Right*(c2.size.x / 2)) + (c2Up*(c2.size.y / 2)) + c2.position;
		v[2] = (c2Forward*(-c2.size.z / 2)) + (c2Right*(c2.size.x / 2)) + (c2Up*(-c2.size.y / 2)) + c2.position;
		v[3] = (c2Forward*(-c2.size.z / 2)) + (c2Right*(-c2.size.x / 2)) + (c2Up*(-c2.size.y / 2)) + c2.position;

		//四角ポリゴンの辺のベクトルを求める
		vD[0] = Vec3Normalize(v[1] - v[0]);
		vD[1] = Vec3Normalize(v[2] - v[1]);
		vD[2] = Vec3Normalize(v[3] - v[2]);
		vD[3] = Vec3Normalize(v[0] - v[3]);

		//四角ポリゴンとソリのベクトルを求める
		sD[0] = Vec3Normalize(c1.position - v[0]);
		sD[1] = Vec3Normalize(c1.position - v[1]);
		sD[2] = Vec3Normalize(c1.position - v[2]);
		sD[3] = Vec3Normalize(c1.position - v[3]);

		for (int i = 0; i < VERTEX_NUM; i++) {
			dot[i] = vD[i].x*sD[i].x + vD[i].y*sD[i].y + vD[i].z*sD[i].z;
		}
		
	}

	//外積計算
	{
		//頂点座標を求める
		v[0] = (c2Forward*(c2.size.z / 2)) + (c2Right*(-c2.size.x / 2))+ c2.position;
		v[1] = (c2Forward*(c2.size.z / 2)) + (c2Right*(c2.size.x / 2)) + c2.position;
		v[2] = (c2Forward*(-c2.size.z / 2)) + (c2Right*(c2.size.x / 2)) + c2.position;
		v[3] = (c2Forward*(-c2.size.z / 2)) + (c2Right*(-c2.size.x / 2))+ c2.position;

		//四角ポリゴンの辺のベクトルを求める
		vD[0] = Vec3Normalize(v[1] - v[0]);
		vD[1] = Vec3Normalize(v[2] - v[1]);
		vD[2] = Vec3Normalize(v[3] - v[2]);
		vD[3] = Vec3Normalize(v[0] - v[3]);

		//四角ポリゴンとソリのベクトルを求める
		sD[0] = Vec3Normalize(c1.position - v[0]);
		sD[1] = Vec3Normalize(c1.position - v[1]);
		sD[2] = Vec3Normalize(c1.position - v[2]);
		sD[3] = Vec3Normalize(c1.position - v[3]);

		//内積用計算
		for (int i = 0; i < VERTEX_NUM; i++) {
			t[i] = c2.position - v[i];
		}

		//外積の計算
		for (int i = 0; i < VERTEX_NUM; i++) {
			cross[i] = { vD[i].y * sD[i].z - vD[i].z * sD[i].y, //X
						 vD[i].z * sD[i].x - vD[i].x * sD[i].z, //Y
						 vD[i].x * sD[i].y - vD[i].y * sD[i].x  //Z
			};



			dot[i] = D3DXVec3Dot(&cross[i], &t[i]);
		}
	}
	


	//当たり判定
	for (int i = 0; i < VERTEX_NUM; i++) {
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
