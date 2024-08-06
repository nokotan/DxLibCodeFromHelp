#include "DxLib.h"
#include <math.h>

#define MOVE_SPEED		4.0f
#define ANGLE_SPEED		0.1f

int main()
{
	int SoundHandle ;
	VECTOR EmitterPos ;
	VECTOR ListenerVel ;
	VECTOR ListenerPos ;
	VECTOR ListenerBackPos ;
	VECTOR ListenerDir ;
	float ListenerAngle ;

	// １メートルに相当する値を設定する
	Set3DSoundOneMetre( 16.0f ) ;

	// ＤＸライブラリの初期化
	if( DxLib_Init() < 0 ) return -1;

	// 描画先を裏画面にする
	SetDrawScreen( DX_SCREEN_BACK );

	// リスナーの位置を初期化
	ListenerPos = VGet( 320.0f, 0.0f, 40.0f ) ;

	// リスナーの向きを初期化
	ListenerAngle = DX_PI_F / 2.0f ;
	ListenerDir.x = cos( ListenerAngle ) ;
	ListenerDir.y = 0.0f ;
	ListenerDir.z = sin( ListenerAngle ) ;

	// リスナーの位置と向きを設定
	Set3DSoundListenerPosAndFrontPos_UpVecY( ListenerPos, VAdd( ListenerPos, ListenerDir ) ) ;

	// 音を３Ｄサウンドとして読み込む
	SetCreate3DSoundFlag( TRUE ) ;
	SoundHandle = LoadSoundMem( "Test.wav" ) ;
	SetCreate3DSoundFlag( FALSE ) ;

	// 音が聞こえる距離を設定する
	Set3DRadiusSoundMem( 256.0f, SoundHandle ) ;

	// 音の再生位置を初期化
	EmitterPos = VGet( 320.0f, 0.0f, 240.0f ) ;

	// 音の再生位置を設定
	Set3DPositionSoundMem( EmitterPos, SoundHandle ) ;

	// 音の再生を開始
	PlaySoundMem( SoundHandle, DX_PLAYTYPE_LOOP ) ;

	// メインループ
	while( ProcessMessage() == 0 )
	{
		// 画面のクリア
		ClearDrawScreen();

		// 移動前のリスナーの位置を保存
		ListenerBackPos = ListenerPos ;

		// 方向キーでリスナーの位置を移動
		if( CheckHitKey( KEY_INPUT_LEFT ) == 1 )
		{
			ListenerPos.x -= MOVE_SPEED ;
		}

		if( CheckHitKey( KEY_INPUT_RIGHT ) == 1 )
		{
			ListenerPos.x += MOVE_SPEED ;
		}

		if( CheckHitKey( KEY_INPUT_UP ) == 1 )
		{
			ListenerPos.z += MOVE_SPEED ;
		}

		if( CheckHitKey( KEY_INPUT_DOWN ) == 1 )
		{
			ListenerPos.z -= MOVE_SPEED ;
		}

		// ＺＸキーで向きを変更
		if( CheckHitKey( KEY_INPUT_Z ) == 1 )
		{
			ListenerAngle += ANGLE_SPEED ;
			if( ListenerAngle > DX_PI_F )
			{
				ListenerAngle -= DX_TWO_PI_F ;
			}
		}

		if( CheckHitKey( KEY_INPUT_X ) == 1 )
		{
			ListenerAngle -= ANGLE_SPEED ;
			if( ListenerAngle < -DX_PI_F )
			{
				ListenerAngle += DX_TWO_PI_F ;
			}
		}

		// このフレームのリスナーの移動距離から移動速度を算出
		// ( ６０分の１秒経過している前提の計算です )
		ListenerVel = VScale( VSub( ListenerPos, ListenerBackPos ), 60.0f ) ;

		// リスナーの移動速度を設定
		Set3DSoundListenerVelocity( ListenerVel ) ;

		// リスナーの位置と向きを設定
		ListenerDir.x = cos( ListenerAngle ) ;
		ListenerDir.y = 0.0f ;
		ListenerDir.z = sin( ListenerAngle ) ;
		Set3DSoundListenerPosAndFrontPos_UpVecY( ListenerPos, VAdd( ListenerPos, ListenerDir ) ) ;

		// リスナーの位置を描画
		DrawBox(
			( int )( ListenerPos.x - 8 ), ( int )( 480.0f - ( ListenerPos.z + 8 ) ),
			( int )( ListenerPos.x + 8 ), ( int )( 480.0f - ( ListenerPos.z - 8 ) ),
			GetColor( 255,0,0 ),   TRUE ) ; 

		// リスナーの向きを描画
		DrawLine(
			( int )           ListenerPos.x,
			( int )( 480.0f - ListenerPos.z ),
			( int )(            ListenerPos.x + ListenerDir.x * 40.0f ),
			( int )( 480.0f - ( ListenerPos.z + ListenerDir.z * 40.0f ) ),
			GetColor( 255,255,255 ) ) ; 

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
