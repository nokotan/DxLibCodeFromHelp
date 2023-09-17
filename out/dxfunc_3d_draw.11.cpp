#include "DxLib.h"

int main()
{
    MATERIALPARAM Material ;

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

    // マテリアルの自己発光色を暗い青色にする
    Material.Diffuse  = GetColorF( 0.0f, 0.0f, 0.0f, 1.0f ) ;
    Material.Specular = GetColorF( 0.0f, 0.0f, 0.0f, 0.0f ) ;
    Material.Ambient  = GetColorF( 0.0f, 0.0f, 0.0f, 0.0f ) ;
    Material.Emissive = GetColorF( 0.0f, 0.0f, 0.5f, 0.0f ) ;
    Material.Power    = 20.0f ;
    SetMaterialParam( Material ) ;

    // デフォルトの設定で３Ｄ空間上に球を描画する
    DrawSphere3D( VGet( 320.0f, 200.0f, 0.0f ), 80.0f, 32, GetColor( 128,0,0 ), GetColor( 255,255,255 ), TRUE ) ;

    // キー入力待ちをする
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
