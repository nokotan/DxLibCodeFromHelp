#include "DxLib.h"

int main()
{
	int SoundHandle ;
	VECTOR EmitterPos[ 2 ] ;
	VECTOR ListenerPos ;
	VECTOR ListenerDir ;
	int PositionNumber ;
	int FrameCounter ;
	int i ;

	// １メートルに相当する値を設定する
	Set3DSoundOneMetre( 16.0f ) ;

	// ＤＸライブラリの初期化
	if( DxLib_Init() < 0 ) return -1;

	// 描画先を裏画面にする
	SetDrawScreen( DX_SCREEN_BACK );

	// リスナーの位置を初期化
	ListenerPos = VGet( 320.0f, 0.0f, 240.0f ) ;

	// リスナーの向きを初期化
	ListenerDir.x = 0.0f ;
	ListenerDir.y = 0.0f ;
	ListenerDir.z = 1.0f ;

	// リスナーの位置と向きを設定
	Set3DSoundListenerPosAndFrontPos_UpVecY( ListenerPos, VAdd( ListenerPos, ListenerDir ) ) ;

	// 音を３Ｄサウンドとして読み込む
	SetCreate3DSoundFlag( TRUE ) ;
	SoundHandle = LoadSoundMem( "Test.wav" ) ;
	SetCreate3DSoundFlag( FALSE ) ;

	// 音が聞こえる距離を設定する
	Set3DRadiusSoundMem( 256.0f, SoundHandle ) ;

	// 音の再生位置を初期化
	EmitterPos[ 0 ] = VGet( 220.0f, 0.0f, 300.0f ) ;
	EmitterPos[ 1 ] = VGet( 420.0f, 0.0f, 300.0f ) ;

	// 鳴らす音の番号を初期化
	PositionNumber = 0 ;

	// フレームカウンターを初期化
	FrameCounter = 0 ;

	// メインループ
	while( ProcessMessage() == 0 )
	{
		// 画面のクリア
		ClearDrawScreen();

		// フレームカウンターをインクリメント
		FrameCounter ++ ;

		// １５フレーム経過したら音を鳴らす
		if( FrameCounter >= 15 )
		{
			// フレームカウンターを初期化
			FrameCounter = 0 ;

			// 次に鳴らす音の位置を設定する
			SetNextPlay3DPositionSoundMem( EmitterPos[ PositionNumber ], SoundHandle ) ;

			// 音を再生
			PlaySoundMem( SoundHandle, DX_PLAYTYPE_BACK ) ;

			// 音を鳴らす位置の座標番号を変更
			PositionNumber = ( PositionNumber + 1 ) % 2 ;
		}

		// リスナーの位置を描画
		DrawBox(
			( int )( ListenerPos.x - 8 ), ( int )( 480.0f - ( ListenerPos.z + 8 ) ),
			( int )( ListenerPos.x + 8 ), ( int )( 480.0f - ( ListenerPos.z - 8 ) ),
			GetColor( 255,0,0 ),   TRUE ) ; 

		// 音の再生位置を描画
		for( i = 0 ; i < 2 ; i ++ )
		{
			DrawBox(
				( int )( EmitterPos[ i ].x - 8 ), ( int )( 480.0f - ( EmitterPos[ i ].z + 8 ) ),
				( int )( EmitterPos[ i ].x + 8 ), ( int )( 480.0f - ( EmitterPos[ i ].z - 8 ) ),
				GetColor( 255,0,255 ), TRUE ) ; 
		}

		// 裏画面の内容を表画面に反映
		ScreenFlip() ;
	}

	// サウンドハンドルの削除
	DeleteSoundMem( SoundHandle ) ;

	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}
