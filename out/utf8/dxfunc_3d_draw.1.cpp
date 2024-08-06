#include "DxLib.h"

int main()
{
    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // ３Ｄ空間上に三角形を描画する
    DrawTriangle3D(
        VGet(100.0f,100.0f,  0.0f),
        VGet(500.0f,400.0f,  0.0f),
        VGet(600.0f,100.0f,100.0f), GetColor( 255,255,255 ), FALSE ) ;

    // キー入力待ちをする
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
