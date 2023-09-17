#include "DxLib.h"

int main()
{
    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // test.midのループ演奏
    PlayMusic( "test.wav" , DX_PLAYTYPE_LOOP ) ;

    // ２秒待つ『WaitTimer』使用
    WaitTimer( 2000 ) ;

    // 演奏を止めます
    StopMusic() ;

    // キー入力があるまで待ちます(『WaitKey』使用)
    WaitKey() ;

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
