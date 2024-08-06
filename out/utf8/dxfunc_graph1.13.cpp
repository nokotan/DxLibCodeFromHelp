#include "DxLib.h"

int main()
{
    int Graph, Graph2 ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() == -1 ) return -1 ;

    // グラフィックのロード
    Graph = LoadGraph( "testDiv.bmp" ) ;

    // Graph 中の (0,32)-(32,64) の部分を抜き出し、新たな
    // グラフィックハンドルを作成
    Graph2 = DerivationGraph( 0, 32, 32, 32, Graph ) ;

    // 新たに作成したグラフィックハンドルで描画
    DrawGraph( 100, 100, Graph2, TRUE ) ;

    // 読み込んだ画像のグラフィックハンドルを削除
    DeleteGraph( Graph2 ) ;
    DeleteGraph( Graph ) ;

    // キーの入力待ち
    WaitKey() ;

    // ＤＸライブラリ使用の終了処理
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
