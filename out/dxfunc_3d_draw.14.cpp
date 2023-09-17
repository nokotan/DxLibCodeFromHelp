#include "DxLib.h"

int main()
{
    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // バックカリングなしで３Ｄ空間上に球を描画する
    DrawSphere3D( VGet( 500.0f, 200.0f, 0.0f ), 80.0f, 8, GetColor( 255,0,0 ), GetColor( 255, 255, 255 ), TRUE ) ;

    // バックカリングを有効にする
    SetUseBackCulling( TRUE ) ;

    // バックカリングありで３Ｄ空間上に球を描画する
    DrawSphere3D( VGet( 140.0f, 200.0f, 0.0f ), 80.0f, 8, GetColor( 255,0,0 ), GetColor( 255, 255, 255 ), TRUE ) ;

    // キー入力待ちをする
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
