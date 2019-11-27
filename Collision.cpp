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
	Hit hit;						//hit����Ɖ����o�����W
	bool isOn = false;				//�ʂ̏�ɂ��邩
	bool isInside = false;			//�ʂ̓����ɂ��邩

	const int VERTEX_NUM = 4;		//�ʂ̒��_��
	D3DXVECTOR3 v[VERTEX_NUM];		//�ʂ̒��_
	D3DXVECTOR3 planeCenter;        //�ʂ̒��S
	D3DXVECTOR3 vD[VERTEX_NUM];		//�ʂ̕ӂ̃x�N�g��
	D3DXVECTOR3 sD[VERTEX_NUM];		//�ʂ̒��_�Ɠ_(�v���C���[)�̃x�N�g��
	D3DXVECTOR3 t[VERTEX_NUM];		//�ʂ̒��S�Ɩʂ̒��_�̃x�N�g��

	D3DXVECTOR3 cross[VERTEX_NUM];  //vD��sD�Ƃ̊O��
	float dot[VERTEX_NUM];			//cross�Ƃ��̓���

	D3DXVECTOR3 nor = { 0,1,0 };   //�ʂ̖@���x�N�g��

	//���_���W���擾���邽�߂̍s��
	D3DXMATRIX vertexMatrixWorld;
	D3DXMATRIX mtxRot;
	D3DXMATRIX mtxTrs;

	//���_���W���w���x�N�g�����v�Z����
	{
		//�s���������
		D3DXMatrixIdentity(&vertexMatrixWorld);

		//���_�ւ̃x�N�g��
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

		//��]�s����쐬
		D3DXMatrixRotationYawPitchRoll(&mtxRot, plane.rotation.y, plane.rotation.x, plane.rotation.z);
		D3DXMatrixMultiply(&vertexMatrixWorld, &vertexMatrixWorld, &mtxRot);

		//���s�s��
		D3DXMatrixTranslation(&mtxTrs, plane.position.x, plane.position.y, plane.position.z);
		D3DXMatrixMultiply(&vertexMatrixWorld, &vertexMatrixWorld, &mtxTrs);

		for (int i = 0; i < VERTEX_NUM; i++) {
			D3DXVec3TransformCoord(&v[i], &v[i], &vertexMatrixWorld);
		}
		D3DXVec3TransformCoord(&planeCenter, &planeCenter, &vertexMatrixWorld);
	}

	//�����蔻��ɕK�v�ȏ����v�Z����
	{

		//�ʂ̕ӂ̃x�N�g�������߂�
		vD[0] = Vec3Normalize(v[1] - v[0]);
		vD[1] = Vec3Normalize(v[2] - v[1]);
		vD[2] = Vec3Normalize(v[3] - v[2]);
		vD[3] = Vec3Normalize(v[0] - v[3]);

		//�ʂ̒��_�Ɠ_(�v���C���[)�̃x�N�g�������߂�
		sD[0] = Vec3Normalize(point.position - v[0]);
		sD[1] = Vec3Normalize(point.position - v[1]);
		sD[2] = Vec3Normalize(point.position - v[2]);
		sD[3] = Vec3Normalize(point.position - v[3]);

		//�ʂ̒��S�Ɩʂ̒��_�̃x�N�g�������߂�
		for (int i = 0; i < VERTEX_NUM; i++) {
			//���_���W-�ʂ̒��S
			t[i] = v[i] - planeCenter;
		}


		//���ςƊO�ς��v�Z����
		for (int i = 0; i < VERTEX_NUM; i++) {
			//�ӂ̃x�N�g���ƒ��_�Ɠ_(�v���C���[)�̋����̃x�N�g���̊O�ς����߂�
			cross[i] = { vD[i].y * sD[i].z - vD[i].z * sD[i].y, //X
						 vD[i].z * sD[i].x - vD[i].x * sD[i].z, //Y
						 vD[i].x * sD[i].y - vD[i].y * sD[i].x  //Z
			};
			//�O�ςŋ��߂��@���x�N�g�� �� �ʂ̒��S�ƒ��_�̃x�N�g���̓��ς����߂�
			dot[i] = D3DXVec3Dot(&cross[i], &t[i]);
		}
	}


	//----------------------�����蔻��----------------------------//
	{
		for (int i = 0; i < VERTEX_NUM; i++) {
			//�O�ς̌��ʂ�0�ȏゾ������ʂ̓����ɂ���
			if (cross[i].y >= 0) {
				isInside = true;
			} else {
				isInside = false;
				break;
			}
		}
		if (isInside == true) {
			for (int i = 0; i < VERTEX_NUM; i++) {
				//���ς̌��ʂ�1�ł�0�ȉ���������ʂ̉��ɂ���
				if (dot[i] <= 0.05f) {
					isOn = true;
					break;
				} else {
					isOn = false;
				}
			}
		}
		//���ςƊO�ς�2�̌��ʂ�true�������瓖�����Ă���
		if (isInside == true && isOn == true) {
			hit.isHit = true;
		} else {
			hit.isHit = false;
		}
	}


	//���܂��Ă����ꍇ�ɉ����߂�
	{
		//�@���x�N�g�������߂�
		if (hit.isHit == true) {
			//�s���������
			D3DXMatrixIdentity(&vertexMatrixWorld);

			//��]�s����쐬
			D3DXMatrixRotationYawPitchRoll(&mtxRot, plane.rotation.y, plane.rotation.x, plane.rotation.z);
			D3DXMatrixMultiply(&vertexMatrixWorld, &vertexMatrixWorld, &mtxRot);

			nor = D3DXVECTOR3(vertexMatrixWorld._21, vertexMatrixWorld._22, vertexMatrixWorld._23);
		}

		//���ς̌��ʂ�1�ł�0.04�ȉ�������Ώ�ɉ����o��
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
