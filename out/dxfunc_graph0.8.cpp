#include "DxLib.h"

int main()
{
    unsigned int Cr ;

    // ＤＸライブラリ初期化
    if( DxLib_Init() == -1 ) return -1;

    // 黄色の値を取得
    Cr = GetColor( 255 , 255 , 0 ) ;

    // 三角形を描画
    DrawTriangle( 320, 100, 160, 420, 480, 420, Cr, TRUE ) ;

    // キーの入力待ち((7-3)『WaitKey』を使用)
    WaitKey() ;

    // ＤＸライブラリ使用の終了処理
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
