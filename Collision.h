#pragma once
#include "common.h"
#include "mydirect3d.h"
#include <d3dx9.h>

struct Hit {
	bool isHit = false;
	float posY;
};

class Collider3D {
public:
	D3DXVECTOR3 position;
	D3DXVECTOR3 size;
	D3DXVECTOR3 rotation;
};


class BoxCollider :public Collider3D {
public:
	bool Collider(Collider3D c1, Collider3D c2);
};

class BoxCollider2 :public Collider3D {
public:
	Hit Collider(Collider3D c1, Collider3D c2);
};

D3DXVECTOR3 Vec3Normalize(D3DXVECTOR3 pV);