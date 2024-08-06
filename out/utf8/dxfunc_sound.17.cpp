#include "DxLib.h"

int main()
{
	int SoundHandle ;
	VECTOR EmitterPos ;
	VECTOR ListenerPos ;
	VECTOR ListenerDir ;
	float xadd ;

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
	EmitterPos = VGet( 320.0f, 0.0f, 300.0f ) ;

	// 音の再生位置を設定
	Set3DPositionSoundMem( EmitterPos, SoundHandle ) ;

	// 音の再生を開始
	PlaySoundMem( SoundHandle, DX_PLAYTYPE_LOOP ) ;

	// メインループ
	xadd = 4.0f ;
	while( ProcessMessage() == 0 )
	{
		// 画面のクリア
		ClearDrawScreen();

		// 音の再生位置をＸ軸方向に移動
		EmitterPos.x += xadd ;
		if( EmitterPos.x > 640.0f || EmitterPos.x < 0.0f )
		{
			xadd = -xadd ;
			EmitterPos.x += xadd ;
		}
		Set3DPositionSoundMem( EmitterPos, SoundHandle ) ;

		// リスナーの位置を描画
		DrawBox(
			( int )( ListenerPos.x - 8 ), ( int )( 480.0f - ( ListenerPos.z + 8 ) ),
			( int )( ListenerPos.x + 8 ), ( int )( 480.0f - ( ListenerPos.z - 8 ) ),
			GetColor( 255,0,0 ),   TRUE ) ; 

		// 音の再生位置を描画
		DrawBox(
			( int )( EmitterPos.x - 8 ), ( int )( 480.0f - ( EmitterPos.z + 8 ) ),
			( int )( EmitterPos.x + 8 ), ( int )( 480.0f - ( EmitterPos.z - 8 ) ),
			GetColor( 255,0,255 ), TRUE ) ; 

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
