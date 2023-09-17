#include "DxLib.h"

int main()
{
	DINPUT_JOYSTATE input ;
	int i ;
	int Color ;

	// ＤＸライブラリの初期化
	if( DxLib_Init() < 0 ) return -1 ;

	// 描画先を裏画面にする
	SetDrawScreen( DX_SCREEN_BACK ) ;

	// メインループ(何かキーが押されたらループを抜ける)
	while( ProcessMessage() == 0 )
	{
		// 画面のクリア
		ClearDrawScreen() ;

		// 入力状態を取得
		GetJoypadDirectInputState( DX_INPUT_PAD1, &input ) ;

		// 画面に構造体の中身を描画
		Color = GetColor( 255,255,255 ) ;
		DrawFormatString( 0, 0, Color, "X:%d Y:%d Z:%d",
					input.X, input.Y, input.Z ) ;
		DrawFormatString( 0, 16, Color, "Rx:%d Ry:%d Rz:%d",
					input.Rx, input.Ry, input.Rz ) ;
		DrawFormatString( 0, 32, Color, "Slider 0:%d 1:%d",
					input.Slider[ 0 ], input.Slider[ 1 ] ) ;
		DrawFormatString( 0, 48, Color, "POV 0:%d 1:%d 2:%d 3:%d",
					input.POV[ 0 ], input.POV[ 1 ],
					input.POV[ 2 ], input.POV[ 3 ] ) ;
		DrawString( 0, 64, "Button", Color ) ;
		for( i = 0 ; i < 32 ; i ++ )
		{
			DrawFormatString( 64 + i % 8 * 64, 64 + i / 8 * 16, Color,
						"%2d:%d", i, input.Buttons[ i ] ) ;
		}

		// 裏画面の内容を表画面に反映
		ScreenFlip() ;
	}

	// ＤＸライブラリの後始末
	DxLib_End() ;

	// ソフトの終了
	return 0;
}
