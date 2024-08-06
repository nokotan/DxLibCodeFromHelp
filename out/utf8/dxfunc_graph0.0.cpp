#include "DxLib.h"

int main()
{
    unsigned int Cr ;

    if( DxLib_Init() == -1 )        // ＤＸライブラリ初期化処理
    {
         return -1;        // エラーが起きたら直ちに終了
    }

    Cr = GetColor( 255 , 255 , 255 ) ;    // 白色の値を取得

    DrawLine( 0 , 0 , 640 , 480 , Cr ) ;    // 線を描画

    WaitKey() ;            // キーの入力待ち(『WaitKey』を使用)

    DxLib_End() ;            // ＤＸライブラリ使用の終了処理

    return 0 ;            // ソフトの終了
}
