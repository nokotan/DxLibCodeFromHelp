#include "DxLib.h"

int main()
{
    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // Ｚバッファを有効にする
    SetUseZBuffer3D( TRUE ) ;

    // Ｚバッファへの書き込みを有効にする
    SetWriteZBuffer3D( TRUE ) ;

    // ３Ｄ空間上にカプセルを描画する
    DrawCapsule3D( VGet( 320.0f, 100.0f, 0.0f ), VGet( 320.0f, 300.0f, 0.0f ), 40.0f, 8, GetColor( 0,255,0 ), GetColor( 255,255,255 ), TRUE ) ;

    // キー入力待ちをする
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
