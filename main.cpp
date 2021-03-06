

#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"dinput8.lib")


#include <Windows.h>
#include "common.h"
#include "mydirect3d.h"
#include "texture.h"
#include "sprite.h"
#include <d3dx9.h>
#include"input.h"
#include"main.h"
#include"Option.h"
#include"title.h"
#include"Game.h"
#include"Result.h"
#include"Ranking.h"
#include"debug_font.h"
#include"Light.h"
#include<time.h>
#include"system_timer.h"
#include"Setting.h"
#include"sound.h"
#include"BalanceBoardInput.h"
#include"Thank.h"

//ここまで3D用追加コード
//===============================================
Light light;


/*------------------------------------------------------------------------------
   定数定義
------------------------------------------------------------------------------*/
#define CLASS_NAME     "GameWindow"       // ウインドウクラスの名前
#define WINDOW_CAPTION "ゲームウィンドウ" // ウィンドウの名前


/*------------------------------------------------------------------------------
   プロトタイプ宣言
------------------------------------------------------------------------------*/
// ウィンドウプロシージャ(コールバック関数)
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// ゲームの初期化関数
// 戻り値:初期化に失敗したときfalse
static bool Initialize(void);
// ゲームの更新関数
static void Update(void);
// ゲームの描画関数
static void Draw(void);
// ゲームの終了処理
static void Finalize(void);

/*------------------------------------------------------------------------------
   グローバル変数宣言
------------------------------------------------------------------------------*/
static HWND g_hWnd;             // ウィンドウハンドル
int nowScene;
static int g_FrameCount = 0;            // フレームカウンター
static double g_StaticFrameTime = 0.0f; // フレーム固定用計測時間

bool ChangeTitle = false;
/*------------------------------------------------------------------------------
   関数定義
------------------------------------------------------------------------------*/

//#######################################################################
// メイン関数
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 使用しない一時変数を明示
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // ウィンドウクラス構造体の設定
    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;                          // ウィンドウプロシージャの指定
    wc.lpszClassName = CLASS_NAME;                     // クラス名の設定
    wc.hInstance = hInstance;                          // インスタンスハンドルの指定
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);          // マウスカーソルを指定
    wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1); // ウインドウのクライアント領域の背景色を設定

    // クラス登録
    RegisterClass(&wc);


    // ウィンドウスタイル
    DWORD window_style = WS_OVERLAPPEDWINDOW & ~(WS_MAXIMIZEBOX | WS_THICKFRAME);

    // 基本矩形座標
    RECT window_rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

    // 指定したクライアント領域を確保するために新たな矩形座標を計算
    AdjustWindowRect(&window_rect, window_style, FALSE);

    // 新たなWindowの矩形座標から幅と高さを算出
    int window_width = window_rect.right - window_rect.left;
    int window_height = window_rect.bottom - window_rect.top;

    // プライマリモニターの画面解像度取得
    int desktop_width = GetSystemMetrics(SM_CXSCREEN);
    int desktop_height = GetSystemMetrics(SM_CYSCREEN);

    // デスクトップの真ん中にウィンドウが生成されるように座標を計算
    // ※ただし万が一、デスクトップよりウィンドウが大きい場合は左上に表示
    int window_x = max((desktop_width - window_width) / 2, 0);
    int window_y = max((desktop_height - window_height) / 2, 0);

    // ウィンドウの生成
    g_hWnd = CreateWindow(
        CLASS_NAME,     // ウィンドウクラス
        WINDOW_CAPTION, // ウィンドウテキスト
		window_style,   // ウィンドウスタイル
        window_x,       // ウィンドウ座標x
        window_y,       // ウィンドウ座標y
        window_width,   // ウィンドウの幅
        window_height,  // ウィンドウの高さ
        NULL,           // 親ウィンドウハンドル
        NULL,           // メニューハンドル
        hInstance,      // インスタンスハンドル
        NULL            // 追加のアプリケーションデータ
    );

    if( g_hWnd == NULL ) {
        // ウィンドウハンドルが何らかの理由で生成出来なかった
        return -1;
    }

    // 指定のウィンドウハンドルのウィンドウを指定の方法で表示
    ShowWindow(g_hWnd, nCmdShow);


	// ゲームの初期化(Direct3Dの初期化)
	if( !Initialize() ) {
        // ゲームの初期化に失敗した
		return -1;
	}
	Keyboard_Initialize(hInstance, g_hWnd);

    // Windowsゲーム用メインループ
    MSG msg = {}; // msg.message == WM_NULL
    while( WM_QUIT != msg.message ) {

        if( PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) ) {
            // メッセージがある場合はメッセージ処理を優先
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else {
			// 現在のシステム時間を取得
			double time = SystemTimer_GetTime();

			if (time - g_StaticFrameTime < 1.0 / 70.0) {
				// 1 / 60 秒経っていなかったら空回り
				Sleep(0);
			} else {
				// フレーム固定用の計測時間を更新する
				g_StaticFrameTime = time;//ゲーム処理を行った時間を記録

				// ゲームの更新
				Update();
				// ゲームの描画
				Draw();
			}
			
        }
    }

	// ゲームの終了処理(Direct3Dの終了処理)
	Finalize();

    return (int)msg.wParam;
}

//#######################################################################
// ウィンドウプロシージャ(コールバック関数)
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch( uMsg ) {
        case WM_KEYDOWN:
            if( wParam == VK_ESCAPE ) {
                SendMessage(hWnd, WM_CLOSE, 0, 0); // WM_CLOSEメッセージの送信
            }
            break;

        case WM_CLOSE:
            if( MessageBox(hWnd, "本当に終了してよろしいですか？", "確認", MB_OKCANCEL | MB_DEFBUTTON2) == IDOK ) {
                DestroyWindow(hWnd); // 指定のウィンドウにWM_DESTROYメッセージを送る
            }
            return 0; // DefWindowProc関数にメッセージを流さず終了することによって何もなかったことにする

        case WM_DESTROY: // ウィンドウの破棄メッセージ
            PostQuitMessage(0); // WM_QUITメッセージの送信
            return 0;
    };

    // 通常メッセージ処理はこの関数に任せる
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


//#######################################################################
// ゲームの初期化関数
bool Initialize(void)
{
    // Direct3Dラッパーモジュールの初期化
    if( !MyDirect3D_Initialize(g_hWnd) ) {
        return false;
    }

    // テクスチャの読み込み
    if( Texture_Load() > 0 ) {
        MessageBox(g_hWnd, "いくつか読み込めなかったテクスチャファイルがあります", "エラー", MB_OK);
    }
	DebugFont_Initialize();

	light.Init(D3DLIGHT_DIRECTIONAL);
	light.Use(true);
	// システムタイマーの初期化
	SystemTimer_Initialize();

	// システムタイマーの起動
	SystemTimer_Start();

	//sound初期化
	InitSound(g_hWnd);

	//バランスボードの初期化
	BalanceBoard_Initialize();
	BalanceBoard_Reset();
	// フレーム固定用計測時間
	g_StaticFrameTime = SystemTimer_GetTime();
	srand((unsigned int)time(NULL));
	LoadSave();
	SetScene(TITLE);

    return true;
}

int count = 0;
//#######################################################################
// ゲームの更新関数
void Update(void){
	Keyboard_Update();
	BalanceBoard_Update();
	if (++count == 50) {
		BalanceBoard_Reset();
	}

	//各シーンごとのUpdate処理
	switch (nowScene) {
	case TITLE:
		TitleUpdate();
		break;

	case OPTION:
		OptionUpdate();
		break;

	case SETTING:
		SettingUpdate();
		break;

	case GAME:
		GameUpdate();
		break;

	case RESULT:
		ResultUpdate();
		break;

	case RANKING:
		RankingUpdate();
		break;

	case THANK:
		ThankUpdate();
		break;
	}
}

//#######################################################################
// ゲームの描画関数
void Draw(void)
{
    LPDIRECT3DDEVICE9 pDevice = MyDirect3D_GetDevice();
    if( !pDevice ) return;
     
    // 画面のクリア
    pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_RGBA(10, 40, 20, 255), 1.0f, 0);

    // 描画バッチ命令の開始
    pDevice->BeginScene();
	

	//各シーンごとのDraw処理
	switch (nowScene) {
	case TITLE:
		TitleDraw();
		break;

	case OPTION:
		OptionDraw();
		break;

	case SETTING:
		SettingDraw();
		break;

	case GAME:
		GameDraw();
		break;

	case RESULT:
		ResultDraw();
		break;

	case RANKING:
		RankingDraw();
		break;


	case THANK:
		ThankDraw();
		break;
	}
	
    // 描画バッチ命令の終了
    pDevice->EndScene();

    // バックバッファをフリップ（タイミングはD3DPRESENT_PARAMETERSの設定による）
    pDevice->Present(NULL, NULL, NULL, NULL);
}

//#######################################################################
// ゲームの終了処理
void Finalize(void){
	Keyboard_Finalize();
    // テクスチャの解放
    Texture_Release();

	DebugFont_Finalize();

	UninitSound();

	BalanceBoard_Finalize();

    // Direct3Dラッパーモジュールの終了処理
    MyDirect3D_Finalize();
	WriteSave();

}

void SetScene(int scene) {
	//各シーンごとの終了処理
	int beforScene = nowScene;
	switch (nowScene) {
	case TITLE:
		TitleUnInit();
		break;

	case OPTION:
		OptionUnInit();
		break;

	case SETTING:
		SettingUnInit();
		break;

	case GAME:
		GameUnInit();
		break;

	case RESULT:
		ResultUnInit();
		break;

	case RANKING:
		RankingUnInit();
		break;


	case THANK:
		ThankUnInit();
		break;
	}
	nowScene = scene;

	//各シーンごとのInit処理
	switch (nowScene) {
	case TITLE:
		TitleInit();
		break;

	case OPTION:
		OptionInit();
		break;

	case SETTING:
		SettingInit();
		break;

	case GAME:
		GameInit();
		break;

	case RESULT:
		ResultInit();
		break;

	case RANKING:
		if (beforScene == TITLE) {
			ChangeTitle = true;
		}
		else {
			ChangeTitle = false;
		}
		RankingInit();
		break;


	case THANK:
		ThankInit();
		break;
	}

}

bool ChangeScene_Title() {
	return ChangeTitle;
}