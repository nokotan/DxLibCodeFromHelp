#include "DxLib.h"

#define CHARA_POS_SPACE         (1500.0f)
#define CHARA_NUM               (4)
#define CHARA_POS_DISTANCE      ( ( CHARA_NUM - 1 ) * CHARA_POS_SPACE )

int StageModelHandle ;
int CharaModelHandle ;
int ShadowMapHandle ;

// キャラクターを描画する
void CharaDraw( void )
{
	int i ;
	int j ;
	VECTOR Position ;

	// キャラクターを１６体描画
	for( i = 0 ; i < CHARA_NUM ; i ++ )
	{
		for( j = 0 ; j < CHARA_NUM ; j ++ )
		{
			// 描画位置を設定
			Position.x = -CHARA_POS_DISTANCE / 2.0f + CHARA_POS_SPACE * j ;
			Position.y = 0.0f ;
			Position.z = -CHARA_POS_DISTANCE / 2.0f + CHARA_POS_SPACE * i ;
			MV1SetPosition( CharaModelHandle, Position ) ;

			// ３Ｄモデルを描画
			MV1DrawModel( CharaModelHandle ) ;
		}
	}
}

int main()
{
	float DrawAreaSize ;
	VECTOR DrawAreaMinPos ;
	VECTOR DrawAreaMaxPos ;

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
	SetCameraPositionAndTarget_UpVecY( VGet( 0.0f, 3600.0f, -3400.0f ), VGet( 0.000f, 500.000f, -500.000f ) );

	// 描画する奥行き方向の範囲を設定
	SetCameraNearFar( 200.000f, 10000.000f );

	// ライトの方向を設定
	SetLightDirection( VGet( 0.5f, -0.5f, 0.5f ) );

	// シャドウマップが想定するライトの方向もセット
	SetShadowMapLightDirection( ShadowMapHandle, VGet( 0.5f, -0.5f, 0.5f ) ) ;

	// 描画するサイズを初期化
	DrawAreaSize = 1000.0f ;

	// メインループ
	while( ProcessMessage() == 0 )
	{
		// 画面をクリア
		ClearDrawScreen() ;


		// 上下キーで描画するサイズを変更
		if( CheckHitKey( KEY_INPUT_UP ) == 1 )
		{
			DrawAreaSize += 10.0f ;
		}

		if( CheckHitKey( KEY_INPUT_DOWN ) == 1 )
		{
			DrawAreaSize -= 10.0f ;
			if( DrawAreaSize < 1.0f )
			{
				DrawAreaSize = 1.0f ;
			}
		}

		// シャドウマップに描画する範囲を設定
		DrawAreaMinPos = VGet( -DrawAreaSize,   -1.0f, -DrawAreaSize ) ;
		DrawAreaMaxPos = VGet(  DrawAreaSize, 1000.0f,  DrawAreaSize ) ;
		SetShadowMapDrawArea( ShadowMapHandle, DrawAreaMinPos, DrawAreaMaxPos ) ;

		// シャドウマップへの描画の準備
		ShadowMap_DrawSetup( ShadowMapHandle ) ;

		// シャドウマップへステージモデルの描画
		MV1DrawModel( StageModelHandle ) ;

		// シャドウマップへキャラクターモデルの描画
		CharaDraw() ;

		// シャドウマップへの描画を終了
		ShadowMap_DrawEnd() ;


		// 描画に使用するシャドウマップを設定
		SetUseShadowMap( 0, ShadowMapHandle ) ;

		// ステージモデルの描画
		MV1DrawModel( StageModelHandle ) ;

		// キャラクターモデルの描画
		CharaDraw() ;

		// 描画に使用するシャドウマップの設定を解除
		SetUseShadowMap( 0, -1 ) ;


		// 画面に現在のサイズと範囲を描画
		DrawFormatString( 0,  0, GetColor( 255,255,255 ), "AreaSize:%.1f", DrawAreaSize ) ;
		DrawFormatString( 0, 16, GetColor( 255,255,255 ), "MinPos( %.1f, %.1f, %.1f )",
			DrawAreaMinPos.x, DrawAreaMinPos.y, DrawAreaMinPos.z ) ;
		DrawFormatString( 0, 32, GetColor( 255,255,255 ), "MaxPos( %.1f, %.1f, %.1f )",
			DrawAreaMaxPos.x, DrawAreaMaxPos.y, DrawAreaMaxPos.z ) ;

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
