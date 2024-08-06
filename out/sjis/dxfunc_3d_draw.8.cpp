#include "DxLib.h"

int main()
{
    VERTEX3D Vertex[ 4 ] ;
    WORD Index[ 6 ] ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // ４頂点分のデータをセット
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

    // ２ポリゴン分のインデックスデータをセット
    Index[ 0 ] = 0 ;
    Index[ 1 ] = 1 ;
    Index[ 2 ] = 2 ;
    Index[ 3 ] = 3 ;
    Index[ 4 ] = 2 ;
    Index[ 5 ] = 1 ;

    // ２ポリゴンの描画
    DrawPolygonIndexed3D( Vertex, 4, Index, 2, DX_NONE_GRAPH, FALSE ) ;

    // キー入力待ちをする
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
