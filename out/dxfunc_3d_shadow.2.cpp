#include "DxLib.h"
#include <math.h>

int main()
{
	int StageModelHandle ;
	int CharaModelHandle ;
	int StageShadowMapHandle ;
	int CharaShadowMapHandle ;
	float Angle ;
	VECTOR CharaPosition ;

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
	StageModelHandle = MV1LoadModel( "SimplePillarStage.mqo" ) ;

	// ステージモデル用のシャドウマップハンドルの作成
	StageShadowMapHandle = MakeShadowMap( 2048, 2048 ) ;

	// キャラクターモデル用のシャドウマップハンドルの作成
	CharaShadowMapHandle = MakeShadowMap( 2048, 2048 ) ;

	// カメラの位置と向きを設定
	SetCameraPositionAndTarget_UpVecY( VGet( 0.0f, 1500.0f, -1500.0f ), VGet( 0.0f, 800.0f, -800.0f ) );

	// 描画する奥行き方向の範囲を設定
	SetCameraNearFar( 160.000f, 80000.000f );

	// シャドウマップに描画する範囲を設定
	SetShadowMapDrawArea( StageShadowMapHandle, VGet( -4000.0f, -1.0f, -4000.0f ), VGet( 4000.0f, 4000.0f, 4000.0f ) ) ;
	SetShadowMapDrawArea( CharaShadowMapHandle, VGet( -4000.0f, -1.0f, -4000.0f ), VGet( 4000.0f, 4000.0f, 4000.0f ) ) ;

	// ライトの方向を設定
	SetLightDirection( VGet( 0.5f, -0.5f, 0.5f ) );

	// シャドウマップが想定するライトの方向もセット
	SetShadowMapLightDirection( StageShadowMapHandle, VGet( 0.5f, -0.5f, 0.5f ) ) ;
	SetShadowMapLightDirection( CharaShadowMapHandle, VGet( 0.5f, -0.5f, 0.5f ) ) ;

	// ステージモデル用のシャドウマップへの描画の準備
	ShadowMap_DrawSetup( StageShadowMapHandle ) ;

	// ステージモデル用のシャドウマップへステージモデルの描画
	MV1DrawModel( StageModelHandle ) ;

	// ステージモデル用のシャドウマップへの描画を終了
	ShadowMap_DrawEnd() ;

	// キャラクターの位置となる角度を初期化
	Angle = 0.0f ;

	// メインループ
	while( ProcessMessage() == 0 )
	{
		// 画面をクリア
		ClearDrawScreen() ;


		// キャラクターの位置となる角度を変更
		Angle += 0.0125f ;
		if( Angle > DX_PI_F * 2.0f )
		{
			Angle -= DX_PI_F * 2.0f ;
		}

		// キャラクターの座標を算出
		CharaPosition.x = sin( Angle ) * 1000.0f ;
		CharaPosition.z = cos( Angle ) * 1000.0f ;
		CharaPosition.y = 0.0f ;

		// キャラクターモデルの座標を変更
		MV1SetPosition( CharaModelHandle, CharaPosition ) ;


		// キャラクターモデル用のシャドウマップへの描画の準備
		ShadowMap_DrawSetup( CharaShadowMapHandle ) ;

		// キャラクターモデル用のシャドウマップへキャラクターモデルの描画
		MV1DrawModel( CharaModelHandle ) ;

		// キャラクターモデル用のシャドウマップへの描画を終了
		ShadowMap_DrawEnd() ;


		// 描画にキャラクターモデル用のシャドウマップと
		// ステージモデル用のシャドウマップのどちらも使用する
		SetUseShadowMap( 0, StageShadowMapHandle ) ;
		SetUseShadowMap( 1, CharaShadowMapHandle ) ;

		// ステージモデルの描画
		MV1DrawModel( StageModelHandle ) ;

		// キャラクターモデルの描画
		MV1DrawModel( CharaModelHandle ) ;

		// 描画に使用するシャドウマップの設定を解除
		SetUseShadowMap( 0, -1 ) ;
		SetUseShadowMap( 1, -1 ) ;


		// 裏画面の内容を表画面に反映
		ScreenFlip() ;
	}

	// シャドウマップの削除
	DeleteShadowMap( StageShadowMapHandle ) ;
	DeleteShadowMap( CharaShadowMapHandle ) ;

	// ステージモデルの削除
	MV1DeleteModel( StageModelHandle ) ;

	// キャラクターモデルの削除
	MV1DeleteModel( CharaModelHandle ) ;

	// ＤＸライブラリの後始末
	DxLib_End() ;

	// ソフトの終了
	return 0 ;
}
