#pragma once

#include <Windows.h>
#include "mydirect3d.h"
#include <d3dx9.h>

class Light {
private:
	D3DLIGHT9 light;

public:
	Light(){}
	void Init(_D3DLIGHTTYPE type, D3DXVECTOR3 direction = { 0.0f, -1.0f, 1.0f }, D3DXCOLOR lightColor = {1,1,1,1});
	void Use(bool isUse);

};