#include "DxLib.h"

int main()
{
    VERTEX3D Vertex[ 6 ] ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // ２ポリゴン分の頂点のデータをセット
    Vertex[ 0 ].pos  = VGet( 100.0f, 100.0f,  0.0f ) ;
    Vertex[ 0 ].norm = VGet(   0.0f,   0.0f, -1.0f ) ;
    Vertex[ 0 ].dif  = GetColorU8( 255,255,255,255 ) ;
    Vertex[ 0 ].spc  = GetColorU8(   0,  0,  0,  0 ) ;
    Vertex[ 0 ].u    = 0.0f ;
    Vertex[ 0 ].v    = 0.0f ;
    Vertex[ 0 ].su   = 0.0f ;
    Vertex[ 0 ].sv   = 0.0f ;

    Vertex[ 1 ].pos  = VGet( 250.0f, 100.0f,  0.0f ) ;
    Vertex[ 1 ].norm = VGet(   0.0f,   0.0f, -1.0f ) ;
    Vertex[ 1 ].dif  = GetColorU8( 255,  0,255,255 ) ;
    Vertex[ 1 ].spc  = GetColorU8(   0,  0,  0,  0 ) ;
    Vertex[ 1 ].u    = 0.0f ;
    Vertex[ 1 ].v    = 0.0f ;
    Vertex[ 1 ].su   = 0.0f ;
    Vertex[ 1 ].sv   = 0.0f ;

    Vertex[ 2 ].pos  = VGet( 100.0f, 300.0f,  0.0f ) ;
    Vertex[ 2 ].norm = VGet(   0.0f,   0.0f, -1.0f ) ;
    Vertex[ 2 ].dif  = GetColorU8(   0,255,255,255 ) ;
    Vertex[ 2 ].spc  = GetColorU8(   0,  0,  0,  0 ) ;
    Vertex[ 2 ].u    = 0.0f ;
    Vertex[ 2 ].v    = 0.0f ;
    Vertex[ 2 ].su   = 0.0f ;
    Vertex[ 2 ].sv   = 0.0f ;


    Vertex[ 3 ].pos  = VGet( 400.0f, 200.0f,  0.0f ) ;
    Vertex[ 3 ].norm = VGet(   0.0f,   0.0f, -1.0f ) ;
    Vertex[ 3 ].dif  = GetColorU8(   0,255,255,255 ) ;
    Vertex[ 3 ].spc  = GetColorU8(   0,  0,  0,  0 ) ;
    Vertex[ 3 ].u    = 0.0f ;
    Vertex[ 3 ].v    = 0.0f ;
    Vertex[ 3 ].su   = 0.0f ;
    Vertex[ 3 ].sv   = 0.0f ;

    Vertex[ 4 ].pos  = VGet( 600.0f, 400.0f,  0.0f ) ;
    Vertex[ 4 ].norm = VGet(   0.0f,   0.0f, -1.0f ) ;
    Vertex[ 4 ].dif  = GetColorU8(   0,  0,255,255 ) ;
    Vertex[ 4 ].spc  = GetColorU8(   0,  0,  0,  0 ) ;
    Vertex[ 4 ].u    = 0.0f ;
    Vertex[ 4 ].v    = 0.0f ;
    Vertex[ 4 ].su   = 0.0f ;
    Vertex[ 4 ].sv   = 0.0f ;

    Vertex[ 5 ].pos  = VGet( 500.0f,  50.0f,  0.0f ) ;
    Vertex[ 5 ].norm = VGet(   0.0f,   0.0f, -1.0f ) ;
    Vertex[ 5 ].dif  = GetColorU8( 255,  0,255,255 ) ;
    Vertex[ 5 ].spc  = GetColorU8(   0,  0,  0,  0 ) ;
    Vertex[ 5 ].u    = 0.0f ;
    Vertex[ 5 ].v    = 0.0f ;
    Vertex[ 5 ].su   = 0.0f ;
    Vertex[ 5 ].sv   = 0.0f ;

    // ２ポリゴンの描画
    DrawPolygon3D( Vertex, 2, DX_NONE_GRAPH, FALSE ) ;

    // キー入力待ちをする
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
