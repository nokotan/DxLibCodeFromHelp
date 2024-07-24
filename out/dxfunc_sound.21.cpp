#include "DxLib.h"

int main()
{
	SOUND3D_REVERB_PARAM ReverbParam ;
	int SoundHandle ;
	VECTOR ListenerPos ;
	VECTOR ListenerDir ;

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

	// 音を鳴らす位置を設定する
	Set3DPositionSoundMem( VGet( 320.0f, 0.0f, 300.0f ), SoundHandle ) ;

	// リバーブエフェクトパラメータを設定
	ReverbParam.WetDryMix           = 100.0f ;
	ReverbParam.ReflectionsDelay    = 20 ;
	ReverbParam.ReverbDelay         = 29 ;
	ReverbParam.RearDelay           = 5 ;
	ReverbParam.PositionLeft        = 6 ;
	ReverbParam.PositionRight       = 6 ;
	ReverbParam.PositionMatrixLeft  = 27 ;
	ReverbParam.PositionMatrixRight = 27 ;
	ReverbParam.EarlyDiffusion      = 15 ;
	ReverbParam.LateDiffusion       = 15 ;
	ReverbParam.LowEQGain           = 8 ;
	ReverbParam.LowEQCutoff         = 4 ;
	ReverbParam.HighEQGain          = 8 ;
	ReverbParam.HighEQCutoff        = 6 ;
	ReverbParam.RoomFilterFreq      = 5000.0f ;
	ReverbParam.RoomFilterMain      = -10.0f ;
	ReverbParam.RoomFilterHF        = -5.0f ;
	ReverbParam.ReflectionsGain     = -12.3f ;
	ReverbParam.ReverbGain          = -0.02f ;
	ReverbParam.DecayTime           = 3.9200001f ;
	ReverbParam.Density             = 100.0f ;
	ReverbParam.RoomSize            = 100.0f ;
	Set3DReverbParamSoundMem( &ReverbParam, SoundHandle ) ;

	// 音を再生を開始
	PlaySoundMem( SoundHandle, DX_PLAYTYPE_LOOP ) ;

	// 何かキーが押されるまで待つ
	WaitKey() ;

	// サウンドハンドルの削除
	DeleteSoundMem( SoundHandle ) ;

	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}
