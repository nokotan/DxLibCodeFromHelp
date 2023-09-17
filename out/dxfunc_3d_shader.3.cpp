#include "DxLib.h"

int main()
{
    int texhandle, pshandle ;
    VERTEX2DSHADER Vert[ 6 ] ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 ) return -1;

    // テクスチャを読み込む
    texhandle = LoadGraph( "Tex1.bmp" ) ;

    // ピクセルシェーダーを読み込む
    pshandle = LoadPixelShader( "PixelShaderTestPS.pso" ) ;

    // ２ポリゴン分の頂点のデータをセットアップ
    Vert[ 0 ].pos = VGet(   0.0f,   0.0f, 0.0f ) ;
    Vert[ 0 ].rhw = 1.0f ;
    Vert[ 0 ].dif = GetColorU8( 255,255,255,255 ) ;
    Vert[ 0 ].spc = GetColorU8(   0,  0,  0,  0 ) ;
    Vert[ 0 ].u   = 0.0f ;
    Vert[ 0 ].v   = 0.0f ;
    Vert[ 0 ].su  = 0.0f ;
    Vert[ 0 ].sv  = 0.0f ;

    Vert[ 1 ].pos = VGet( 256.0f,   0.0f, 0.0f ) ;
    Vert[ 1 ].rhw = 1.0f ;
    Vert[ 1 ].dif = GetColorU8( 255,255,255,255 ) ;
    Vert[ 1 ].spc = GetColorU8(   0,  0,  0,  0 ) ;
    Vert[ 1 ].u   = 1.0f ;
    Vert[ 1 ].v   = 0.0f ;
    Vert[ 1 ].su  = 1.0f ;
    Vert[ 1 ].sv  = 0.0f ;

    Vert[ 2 ].pos = VGet(   0.0f, 256.0f, 0.0f ) ;
    Vert[ 2 ].rhw = 1.0f ;
    Vert[ 2 ].dif = GetColorU8( 255,255,255,255 ) ;
    Vert[ 2 ].spc = GetColorU8(   0,  0,  0,  0 ) ;
    Vert[ 2 ].u   = 0.0f ;
    Vert[ 2 ].v   = 1.0f ;
    Vert[ 2 ].su  = 0.0f ;
    Vert[ 2 ].sv  = 1.0f ;

    Vert[ 3 ].pos = VGet( 256.0f, 256.0f, 0.0f ) ;
    Vert[ 3 ].rhw = 1.0f ;
    Vert[ 3 ].dif = GetColorU8( 255,255,255,255 ) ;
    Vert[ 3 ].spc = GetColorU8(   0,  0,  0,  0 ) ;
    Vert[ 3 ].u   = 1.0f ;
    Vert[ 3 ].v   = 1.0f ;
    Vert[ 3 ].su  = 1.0f ;
    Vert[ 3 ].sv  = 1.0f ;

    Vert[ 4 ].pos = VGet(   0.0f, 256.0f, 0.0f ) ;
    Vert[ 4 ].rhw = 1.0f ;
    Vert[ 4 ].dif = GetColorU8( 255,255,255,255 ) ;
    Vert[ 4 ].spc = GetColorU8(   0,  0,  0,  0 ) ;
    Vert[ 4 ].u   = 0.0f ;
    Vert[ 4 ].v   = 1.0f ;
    Vert[ 4 ].su  = 0.0f ;
    Vert[ 4 ].sv  = 1.0f ;

    Vert[ 5 ].pos = VGet( 256.0f,   0.0f, 0.0f ) ;
    Vert[ 5 ].rhw = 1.0f ;
    Vert[ 5 ].dif = GetColorU8( 255,255,255,255 ) ;
    Vert[ 5 ].spc = GetColorU8(   0,  0,  0,  0 ) ;
    Vert[ 5 ].u   = 1.0f ;
    Vert[ 5 ].v   = 0.0f ;
    Vert[ 5 ].su  = 1.0f ;
    Vert[ 5 ].sv  = 0.0f ;

    // 使用するテクスチャを０番にセット
    SetUseTextureToShader( 0, texhandle ) ;

    // 使用するピクセルシェーダーをセット
    SetUsePixelShader( pshandle ) ;

    // シェーダーを使用した２Ｄの２ポリゴンの描画
    DrawPolygon2DToShader( Vert, 2 ) ;

    // キー入力待ち
    WaitKey() ;

    // 読み込んだピクセルシェーダーの削除
    DeleteShader( pshandle ) ;

    // 読み込んだ画像のグラフィックハンドルを削除
    DeleteGraph( texhandle ) ;

    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}
