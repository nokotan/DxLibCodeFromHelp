#include "DxLib.h"

int main()
{
    int SHandle[ 5 ] ;
    int i ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // test.wavのメモリへの読み込みサウンドハンドルをSHandleに保存します
    for( i = 0 ; i < 5 ; i ++ )
    {
        SHandle[ i ] = LoadSoundMem( "test.wav" ) ;
    }

    // 読みこんだ音を０．１秒おきにバックグラウンド再生します(『PlaySoundMem』関数使用)
    for( i = 0 ; i < 10 ; i ++ )
    {
        // 音の再生
        PlaySoundMem( SHandle[ i ] , DX_PLAYTYPE_BACK ) ;

        // ０．５秒待つ(『WaitTimer』使用)
        WaitTimer( 100 ) ;
    }

    // 音をすべて削除します
    InitSoundMem() ;

    // キー入力があるまで待ちます(『WaitKey』使用)
    WaitKey() ;

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
