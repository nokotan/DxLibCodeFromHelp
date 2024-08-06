#include "DxLib.h"

int main()
{
	int ModelHandle ;

	// ウィンドウモードで起動
	ChangeWindowMode( TRUE ) ;

	// 画面解像度を設定
	SetGraphMode( 1920, 1080, 32 ) ;

	// Live2D Cubism Core DLL の読み込み( 64bit アプリの場合と 32bit アプリの場合で読み込む dll を変更 )
#ifdef _WIN64
	Live2D_SetCubism4CoreDLLPath( "D:/CubismSdkForNative-4-beta.1/Core/dll/windows/x86_64/Live2DCubismCore.dll" ) ;
#else
	Live2D_SetCubism4CoreDLLPath( "D:/CubismSdkForNative-4-beta.1/Core/dll/windows/x86/Live2DCubismCore.dll" ) ;
#endif

	// ＤＸライブラリ初期化処理
	if( DxLib_Init() == -1 )
	{
		 return -1 ;
	}

	// Live2Dモデルの読み込み
	ModelHandle = Live2D_LoadModel( "D:/Cubism4SDKforNative-beta12-1/Samples/Res/Hiyori/Hiyori.model3.json" ) ;

	// 描画先を裏画面に変更
	SetDrawScreen( DX_SCREEN_BACK ) ;

	// メインループ
	while( ProcessMessage() == 0 )
	{
		// 画面の初期化
		ClearDrawScreen() ;

		// モーション再生が終了していたらアイドリングモーションをランダムで再生
		if( Live2D_Model_IsMotionFinished( ModelHandle ) == TRUE )
		{
			Live2D_Model_StartMotion( ModelHandle, "Idle", GetRand( 8 ) ) ;
		}

		// モデルの状態を60分の1秒分進める
		Live2D_Model_Update( ModelHandle, 1 / 60.0f ) ;

		// Live2D描画の開始
		Live2D_RenderBegin() ;

		// モデルの描画
		Live2D_Model_Draw( ModelHandle ) ;

		// Live2D描画の終了
		Live2D_RenderEnd() ;

		// 裏画面の内容を表画面に反映
		ScreenFlip() ;
	}

	// Live2D モデルの削除
	Live2D_DeleteModel( ModelHandle ) ;

	// ＤＸライブラリ使用の終了処理
	DxLib_End() ;

	// ソフトの終了
	return 0 ;
}
