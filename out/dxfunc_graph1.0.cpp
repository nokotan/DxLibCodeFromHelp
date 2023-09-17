#include "DxLib.h"

int main()
{
    if( DxLib_Init() == -1 )        // ＤＸライブラリ初期化処理
    {
         return -1;        // エラーが起きたら直ちに終了
    }

    // ＢＭＰ画像の表示
    LoadGraphScreen( 0 , 0 , "test1.bmp" , TRUE ) ;

    WaitKey() ;            // キーの入力待ち(『WaitKey』を使用)

    DxLib_End() ;            // ＤＸライブラリ使用の終了処理

    return 0 ;            // ソフトの終了
}
