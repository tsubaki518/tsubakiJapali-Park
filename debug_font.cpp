#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>
#include<dxerr.h>
#include"mydirect3d.h"
#include"common.h"
#include<stdio.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dxerr.lib")

#define DEBUG_PRINTF_BUFFER_MAX (256)

//ƒOƒ[ƒoƒ‹•Ï”
#if defined(_DEBUG) || defined(DEBUG)
static LPD3DXFONT g_pD3DXFont = NULL;

#endif	//debugƒrƒ‹ƒh‚Å‚Ì‚Ý—LŒø

void DebugFont_Initialize(void) {
#if defined(_DEBUG)||defined(DEBUG)
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D_GetDevice();	//Œã‚Åì‚éŠÖ”
	D3DXCreateFont(pDevice, 24, 0, 0, 0, FALSE, SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "HGP‘n‰pŠpÎß¯Ìß‘Ì", &g_pD3DXFont);
#endif;
}

void DebugFont_Finalize(void) {
#if defined(_DEBUG) || defined(DEBUG)
	if (g_pD3DXFont) {
		g_pD3DXFont->Release();
		g_pD3DXFont = NULL;
	}
#endif
}

//...‚Í‰Â•Ï’·ˆø”‚Åˆø”‚Ì”‚©•Ï‰»‚·‚é
void DebugFont_Draw(int x, int y, const char* pFormat, ...) {
#if defined(_DEBUG) || defined(DEBUG)
	RECT rect = { x,y,SCREEN_WIDTH,SCREEN_HEIGHT };

	va_list argp;
	va_start(argp, pFormat);
	char buf[DEBUG_PRINTF_BUFFER_MAX];

	vsprintf_s(buf, DEBUG_PRINTF_BUFFER_MAX, pFormat, argp);
	va_end(argp);
	g_pD3DXFont->DrawText(NULL, buf, -1, &rect, DT_LEFT, D3DCOLOR_RGBA(255, 255, 255, 255));
#else
	UNREFERENCED_PARAMETER(pFormat);
	UNREFERENCED_PARAMETER(x);
	UNREFERENCED_PARAMETER(y);
#endif
}
	