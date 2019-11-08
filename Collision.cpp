#include <Windows.h>
#include "common.h"
#include "mydirect3d.h"
#include "texture.h"
#include "sprite.h"
#include <d3dx9.h>

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
	if (tanf(c2.rad.z+0.15f)*(c2.position.y*2 + c1.position.x/* - c2.position.x*/) >= c1.position.y-c1.size.y*1.2f &&
		tanf(-c2.rad.x+0.15f)*(c2.position.y*2 + c1.position.z/* - c2.position.z*/) >= c1.position.y - c1.size.y*1.2f
		) {
		return true;
	}

	return false;
}

