#include "DxLib.h"

int main()
{
	int FontHandle ;
	int ScreenHandle ;

	// ＤＸライブラリ初期化処理
	if( DxLib_Init() == -1 )
		 return -1;

	// 描画対象にできるαチャンネル付きのグラフィックハンドルを作成する
	ScreenHandle = MakeScreen( 256, 64, TRUE ) ;

	// 乗算済みα用のフォントハンドルを作成する
	SetFontCacheUsePremulAlphaFlag( TRUE ) ;
	FontHandle = CreateFontToHandle( "ＭＳ ゴシック", 32, 4, DX_FONTTYPE_ANTIALIASING_8X8 ) ;

	// 描画先を作成したグラフィックハンドルにする
	SetDrawScreen( ScreenHandle ) ;

	// グラフィックハンドルに乗算済みα用のαブレンドモードで透明度50%で文字を描画する
	SetDrawBlendMode( DX_BLENDMODE_PMA_ALPHA, 128 ) ;
	DrawStringToHandle( 0, 0, "テスト文字列", GetColor( 255,255,255 ), FontHandle ) ;

	// 描画先を裏画面に変更する
	SetDrawScreen( DX_SCREEN_BACK ) ;

	// 結果が分かりやすいように裏画面を緑で塗りつぶす
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 255 ) ;
	DrawBox( 0, 0, 640, 480, GetColor( 0,200,0 ), TRUE ) ;

	// 裏画面に文字列を描画したグラフィックハンドルを乗算済みα用のαブレンドモードで描画する
	SetDrawBlendMode( DX_BLENDMODE_PMA_ALPHA, 255 ) ;
	DrawGraph( 100, 100, ScreenHandle, TRUE ) ;

	// 裏画面の内容を表画面に反映させる
	ScreenFlip() ;

	// 作成したフォントハンドルを削除する
	DeleteFontToHandle( FontHandle ) ;

	// MakeScreen で作成したグラフィックハンドルの削除
	DeleteGraph( ScreenHandle ) ;

	// キー入力待ち
	WaitKey() ;

	// ＤＸライブラリ使用の終了処理
	DxLib_End() ;

	// ソフトの終了
	return 0 ;
}
