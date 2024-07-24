#include "DxLib.h"

int main()
{
	int ClickX, ClickY, Button, LogType ;
	int DrawFlag, DrawX, DrawY, DrawColor ;

	// ＤＸライブラリの初期化
	if( DxLib_Init() < 0 ) return -1 ;

	// 描画先を裏画面にする
	SetDrawScreen( DX_SCREEN_BACK ) ;

	// 描画情報の初期化
	DrawFlag = FALSE ;
	DrawX = 0 ;
	DrawY = 0 ;
	DrawColor = 0 ;

	// メインループ(何かキーが押されたらループを抜ける)
	while( ProcessMessage() == 0 )
	{
		// 画面のクリア
		ClearDrawScreen() ;

		// マウスのボタンが押されたり離されたりしたかどうかの情報を取得する
		if( GetMouseInputLog2( &Button, &ClickX, &ClickY, &LogType, TRUE ) == 0 )
		{
			// 左ボタンが押されたり離されたりしていたら描画するかどうかのフラグを立てて、座標も保存する
			if( ( Button & MOUSE_INPUT_LEFT ) != 0 )
			{
				DrawFlag = TRUE ;
				DrawX = ClickX ;
				DrawY = ClickY ;

				// 四角形の色を押された場合は白に、離された場合は紫にする
				DrawColor = LogType == MOUSE_INPUT_LOG_DOWN ? GetColor( 255,255,255 ) : GetColor( 255,0,255 ) ;
			}
		}

		// 描画するかどうかのフラグが立っていたら、マウスの左ボタンが押されたり離されたりした座標に小さい四角形を描画する
		if( DrawFlag == TRUE )
		{
			DrawBox( DrawX - 8, DrawY - 8, DrawX + 8, DrawY + 8, DrawColor, TRUE ) ;
		}

		// 裏画面の内容を表画面に反映
		ScreenFlip() ;

		// ０．５秒待つ
		WaitTimer( 500 ) ;
	}

	// ＤＸライブラリの後始末
	DxLib_End() ;

	// ソフトの終了
	return 0 ;
}
