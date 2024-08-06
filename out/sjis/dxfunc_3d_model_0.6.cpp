#include "DxLib.h"

#define CHARA_SPACE			(300.0f)
#define CHARA_X				(250.0f)

int CharaModelHandle ;

// キャラクターモデルの描画
void Chara_Draw( float x )
{
	int i ;

	// 手前から２体描画
	for( i = 0 ; i < 2 ; i ++ )
	{
		// 先頭のキャラを半透明にする
		MV1SetOpacityRate( CharaModelHandle, i == 0 ? 0.5f : 1.0f ) ;

		// 座標を設定
		MV1SetPosition( CharaModelHandle, VGet( x, 0.0f, i * CHARA_SPACE ) ) ;

		// モデルを描画
		MV1DrawModel( CharaModelHandle ) ;
	}
}

int main()
{
	// ＤＸライブラリの初期化
	if( DxLib_Init() < 0 )
	{
		// エラーが発生したら終了
		return -1 ;
	}

	// 描画先を裏画面に変更
	SetDrawScreen( DX_SCREEN_BACK ) ;

	// キャラクターモデルの読み込み
	CharaModelHandle = MV1LoadModel( "DxChara.x" ) ;

	// カメラの位置と向きを設定
	SetCameraPositionAndTarget_UpVecY( VGet( 0.0f, 400.0f, -700.0f ), VGet( 0.0f, 400.0f, 0.0f ) );

	// 描画する奥行き方向の範囲を設定
	SetCameraNearFar( 20.0f, 5000.0f );

	// 背景の色を灰色に変更
	SetBackgroundColor( 128,128,128 ) ;

	// 画面をクリア
	ClearDrawScreen() ;

	// メインループ
	while( ProcessMessage() == 0 )
	{
		// 画面をクリア
		ClearDrawScreen() ;

		// 通常の設定で画面左側にキャラクターを描画
		MV1SetSemiTransDrawMode( DX_SEMITRANSDRAWMODE_ALWAYS ) ;
		Chara_Draw( -CHARA_X ) ;

		// 画面右側に先に半透明要素の無い３Ｄモデルのみ描画する設定でキャラクターを描画した後、
		// 半透明要素のある３Ｄモデルのみ描画する設定でキャラクターを描画する
		MV1SetSemiTransDrawMode( DX_SEMITRANSDRAWMODE_NOT_SEMITRANS_ONLY ) ;
		Chara_Draw( CHARA_X ) ;

		MV1SetSemiTransDrawMode( DX_SEMITRANSDRAWMODE_SEMITRANS_ONLY ) ;
		Chara_Draw( CHARA_X ) ;

		// 裏画面の内容を表画面に反映
		ScreenFlip() ;
	}

	// モデルハンドルの削除
	MV1DeleteModel( CharaModelHandle ) ;

	// ＤＸライブラリの後始末
	DxLib_End() ;

	// ソフトの終了
	return 0 ;
}
