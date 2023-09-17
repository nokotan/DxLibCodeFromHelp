#include "DxLib.h"

int main()
{
    int GHandle ;

    if( DxLib_Init() == -1 )        // ＤＸライブラリ初期化処理
    {
         return -1;        // エラーが起きたら直ちに終了
    }

    // ＢＭＰ画像のメモリへの読みこみ
    GHandle = LoadGraph( "test1.bmp" ) ;

    // 画面左上に描画します(『DrawGraph』を使用)
    DrawGraph( 0 , 0 , GHandle , FALSE ) ;

    // 読み込んだ画像のグラフィックハンドルを削除
    DeleteGraph( GHandle ) ;

    // キーの入力待ち(『WaitKey』を使用)
    WaitKey() ;

    DxLib_End() ;            // ＤＸライブラリ使用の終了処理

    return 0 ;            // ソフトの終了
}
