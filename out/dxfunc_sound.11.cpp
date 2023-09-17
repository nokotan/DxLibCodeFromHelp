#include "DxLib.h"

int main()
{
	int SoundHandle ;

	// ＤＸライブラリの初期化
	if( DxLib_Init() == -1 )
	{
		return -1 ;
	}

	// 音の読み込み
	SoundHandle = LoadSoundMem( "Test.wav" ) ;

	// 「通常音量で音を再生」と「小音量で音を再生」を交互に行う
	while( ProcessMessage() == 0 )
	{
		// 通常音量で音を再生する
		ChangeNextPlayVolumeSoundMem( 255, SoundHandle ) ;
		PlaySoundMem( SoundHandle, DX_PLAYTYPE_BACK ) ;

		// ０．１５秒待つ
		WaitTimer( 150 ) ;

		// 小音量で音を再生する
		ChangeNextPlayVolumeSoundMem( 128, SoundHandle ) ;
		PlaySoundMem( SoundHandle, DX_PLAYTYPE_BACK ) ;

		// ０．１５秒待つ
		WaitTimer( 150 ) ;
	}

	// サウンドハンドルの削除
	DeleteSoundMem( SoundHandle ) ;

	// ＤＸライブラリの後始末
	DxLib_End() ;

	// ソフトの終了
	return 0 ;
}
