#include "DxLib.h"

int main()
{
    unsigned int Cr ;

    // ＤＸライブラリ初期化
    if( DxLib_Init() == -1 ) return -1;

    // 黄色の値を取得
    Cr = GetColor( 255 , 255 , 0 ) ;

    // 三角形を描画
    DrawTriangleAA( 320.0f, 100.0f, 160.0f, 420.0f, 480.0f, 420.0f, Cr, TRUE ) ;

    // キーの入力待ち((7-3)『WaitKey』を使用)
    WaitKey() ;

    // ＤＸライブラリ使用の終了処理
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
