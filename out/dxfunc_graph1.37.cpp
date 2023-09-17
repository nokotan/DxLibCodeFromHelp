#include "DxLib.h"

int main()
{
    int SrcHandle ;
    int DestHandle ;
    int BlendHandle ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
        return -1 ;

    // 画像を読み込む
    SrcHandle = LoadGraph( "Src1.bmp" ) ;

    // ブレンドする画像を読み込む
    BlendHandle = LoadGraph( "Src2.tga" ) ;

    // 出力先のグラフィックハンドルを作成する
    DestHandle = MakeScreen( 128, 128, FALSE ) ;

    // Handle と BlendHandle で覆い焼き合成を行う
    GraphBlendRectBlt( SrcHandle, BlendHandle, DestHandle, 128, 128, 256, 256, 64, 64, 0, 0, 255, DX_GRAPH_BLEND_DODGE ) ;

    // 合成後の画像を画面に描画
    DrawGraph( 0, 0, DestHandle, FALSE ) ;

    // 読み込んだ画像のグラフィックハンドルを削除
    DeleteGraph( SrcHandle ) ;
    DeleteGraph( BlendHandle ) ;

    // MakeScreen で作成したグラフィックハンドルの削除
    DeleteGraph( DestHandle ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    return 0 ;
}
