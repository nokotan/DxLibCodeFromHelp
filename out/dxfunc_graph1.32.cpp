#include "DxLib.h"

int main()
{
    int SrcHandle ;
    int DestHandle ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
        return -1 ;

    // 画像を読み込む
    SrcHandle = LoadGraph( "Src1.bmp" ) ;

    // 出力先に使用するグラフィックハンドルを作成
    DestHandle = MakeScreen( 256, 256, FALSE ) ;

    // モノトーンフィルターでセピア調の画像に変換
    GraphFilterBlt( SrcHandle, DestHandle, DX_GRAPH_FILTER_MONO, -60, 7 ) ;

    // 画像を画面に描画
    DrawGraph( 0, 0, DestHandle, FALSE ) ;

    // 読み込んだ画像のグラフィックハンドルを削除
    DeleteGraph( SrcHandle ) ;

    // MakeScreen で作成したグラフィックハンドルの削除
    DeleteGraph( DestHandle ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    return 0 ;
}
