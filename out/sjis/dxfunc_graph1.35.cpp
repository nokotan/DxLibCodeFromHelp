#include "DxLib.h"

int main()
{
    int Handle ;
    int BlendHandle ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
        return -1 ;

    // 画像を読み込む
    Handle = LoadGraph( "Src1.bmp" ) ;

    // ブレンドする画像を読み込む
    BlendHandle = LoadGraph( "Src2.tga" ) ;

    // Handle と BlendHandle でオーバーレイ合成を行う
    GraphBlend( Handle, BlendHandle, 255, DX_GRAPH_BLEND_OVERLAY ) ;

    // 合成後の画像を画面に描画
    DrawGraph( 0, 0, Handle, FALSE ) ;

    // 読み込んだ画像のグラフィックハンドルを削除
    DeleteGraph( Handle ) ;
    DeleteGraph( BlendHandle ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    return 0 ;
}
