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

	// 左右交互に音を鳴らす
	while( ProcessMessage() == 0 )
	{
		// 左側のスピーカーから音を鳴らす
		ChangeNextPlayPanSoundMem( -255, SoundHandle ) ;
		PlaySoundMem( SoundHandle, DX_PLAYTYPE_BACK ) ;

		// ０．１５秒待つ
		WaitTimer( 150 ) ;

		// 右側のスピーカーから音を鳴らす
		ChangeNextPlayPanSoundMem( 255, SoundHandle ) ;
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
