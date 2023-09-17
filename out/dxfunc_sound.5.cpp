#include "DxLib.h"

int main()
{
    int SHandle ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // test.wavのメモリへの読み込みサウンドハンドルをSHandleに保存します
    SHandle = LoadSoundMem( "test.wav" ) ;

    // 読みこんだ音をループ再生します(『PlaySoundMem』関数使用)
    PlaySoundMem( SHandle , DX_PLAYTYPE_LOOP ) ;

    // ５秒待つ『WaitTimer』使用
    WaitTimer( 5000 ) ;

    // 再生を止めます
    StopSoundMem( SHandle ) ;

    // キー入力があるまで待ちます(『WaitKey』使用)
    WaitKey() ;

    // サウンドハンドルの削除
    DeleteSoundMem( SHandle ) ;

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
