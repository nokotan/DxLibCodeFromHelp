#include "DxLib.h"

int main()
{
    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // test.wavのループ再生
    PlaySoundFile( "test.wav" , DX_PLAYTYPE_LOOP ) ;

    // ５秒待つ『WaitTimer』使用
    WaitTimer( 5000 ) ;

    // 再生を止めます
    StopSoundFile() ;

    // キー入力があるまで待ちます(『WaitKey』使用)
    WaitKey() ;

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
