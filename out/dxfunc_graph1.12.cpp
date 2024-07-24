#include "DxLib.h"

int main()
{
    int GHandle ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() == -1 ) return -1 ;

    // グラフィックのロード
    GHandle = LoadGraph( "testDiv.bmp" ) ;

    // グラフィック中の(32,32)-(64,64)の部分を画面座標(100,100)に
    // 透過色処理あり、反転処理なしで描画
    DrawRectGraph( 100, 100, 32, 32, 32, 32, GHandle, TRUE, FALSE ) ;

    // 読み込んだ画像のグラフィックハンドルを削除
    DeleteGraph( GHandle ) ;

    // キーの入力待ち
    WaitKey() ;

    // ＤＸライブラリ使用の終了処理
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
