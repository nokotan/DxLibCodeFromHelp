#include "DxLib.h"
#include <math.h>

int main()
{
	int StageModelHandle ;
	int CharaModelHandle ;
	int ShadowMapHandle ;
	float Angle ;
	VECTOR LightDirection ;

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

	// ステージモデルの読み込み
	StageModelHandle = MV1LoadModel( "Plane.mqo" ) ;

	// シャドウマップハンドルの作成
	ShadowMapHandle = MakeShadowMap( 1024, 1024 ) ;

	// カメラの位置と向きを設定
	SetCameraPositionAndTarget_UpVecY( VGet( 0.0f, 800.0f, -800.0f ), VGet( 0.000f, 500.000f, 0.000f ) );

	// 描画する奥行き方向の範囲を設定
	SetCameraNearFar( 40.000f, 2000.000f );

	// シャドウマップに描画する範囲を設定
	SetShadowMapDrawArea( ShadowMapHandle, VGet( -1000.0f, -1.0f, -1000.0f ), VGet( 1000.0f, 1000.0f, 1000.0f ) ) ;

	// ライトの角度を初期化
	Angle = 0.0f ;

	// メインループ
	while( ProcessMessage() == 0 )
	{
		// 画面をクリア
		ClearDrawScreen() ;


		// ライトの角度を変更
		Angle += 0.0125f ;
		if( Angle > DX_PI_F * 2.0f )
		{
			Angle -= DX_PI_F * 2.0f ;
		}

		// ライトの方向ベクトルの算出
		LightDirection.x = sin( Angle ) ;
		LightDirection.z = cos( Angle ) ;
		LightDirection.y = -1.0f ;

		// ライトの方向を設定
		SetLightDirection( LightDirection );

		// シャドウマップが想定するライトの方向もセット
		SetShadowMapLightDirection( ShadowMapHandle, LightDirection ) ;


		// シャドウマップへの描画の準備
		ShadowMap_DrawSetup( ShadowMapHandle ) ;

		// シャドウマップへステージモデルの描画
		MV1DrawModel( StageModelHandle ) ;

		// シャドウマップへキャラクターモデルの描画
		MV1DrawModel( CharaModelHandle ) ;

		// シャドウマップへの描画を終了
		ShadowMap_DrawEnd() ;


		// 描画に使用するシャドウマップを設定
		SetUseShadowMap( 0, ShadowMapHandle ) ;

		// ステージモデルの描画
		MV1DrawModel( StageModelHandle ) ;

		// キャラクターモデルの描画
		MV1DrawModel( CharaModelHandle ) ;

		// 描画に使用するシャドウマップの設定を解除
		SetUseShadowMap( 0, -1 ) ;


		// 画面左上にシャドウマップをテスト描画
		TestDrawShadowMap( ShadowMapHandle, 0, 0, 320, 240 ) ;


		// 裏画面の内容を表画面に反映
		ScreenFlip() ;
	}

	// シャドウマップの削除
	DeleteShadowMap( ShadowMapHandle ) ;

	// ステージモデルの削除
	MV1DeleteModel( StageModelHandle ) ;

	// キャラクターモデルの削除
	MV1DeleteModel( CharaModelHandle ) ;

	// ＤＸライブラリの後始末
	DxLib_End() ;

	// ソフトの終了
	return 0 ;
}
