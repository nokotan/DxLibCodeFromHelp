#include "DxLib.h"

int main()
{
    int SoundHandle ;

    // ＤＸライブラリ初期化処理
    if( DxLib_Init() == -1 ) return -1;

    // 音をロードする
    SoundHandle = LoadSoundMem( "testMusic.wav" ) ;

    // ループ位置を音の先頭から２０秒後にセットする
    SetLoopPosSoundMem( 20000, SoundHandle ) ;

    // 音をループ再生する
    PlaySoundMem( SoundHandle, DX_PLAYTYPE_LOOP ) ;

    // キーの入力待ち
    WaitKey() ;

    // サウンドハンドルの削除
    DeleteSoundMem( SoundHandle ) ;

    // ＤＸライブラリ使用の終了処理
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
