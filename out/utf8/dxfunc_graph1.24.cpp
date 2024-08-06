#include "DxLib.h"

int main()
{
    int Handle ;

    // 画面モードを32bitカラーにする
    SetGraphMode( 640, 480, 32 ) ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
        return -1 ;

    // 画像を読み込む
    Handle = LoadGraph( "Src1.bmp" ) ;

    // ガウスフィルターを施す
    GraphFilter( Handle, DX_GRAPH_FILTER_GAUSS, 16, 1400 ) ;

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
