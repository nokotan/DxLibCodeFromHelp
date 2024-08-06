#include "DxLib.h"

int main()
{
    // ＤＸライブラリ初期化処理
    if( DxLib_Init() == -1 )
         return -1;    // エラーが起きたら直ちに終了

    // 振動開始
    StartJoypadVibration( DX_INPUT_PAD1, 1000, 2000, -1 ) ;

    // ２秒間経過するまで待つ
    WaitTimer( 2000 ) ;

    // ＤＸライブラリ使用の終了処理
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
