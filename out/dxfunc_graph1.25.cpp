#include "DxLib.h"

int main()
{
    int Handle ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
        return -1 ;

    // 画像を読み込む
    Handle = LoadGraph( "Src1.bmp" ) ;

    // 縮小フィルターを施す
    GraphFilter( Handle, DX_GRAPH_FILTER_DOWN_SCALE, 4 ) ;

    // 画像を画面に描画
    DrawGraph( 0, 0, Handle, FALSE ) ;

    // 読み込んだ画像のグラフィックハンドルを削除
    DeleteGraph( Handle ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    return 0 ;
}
