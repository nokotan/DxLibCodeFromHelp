#include "DxLib.h"

int main()
{
    int GHandle ;

    // 画面モードの設定
    SetGraphMode( 800 , 600 , 32 ) ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが発生したら終了
    }

    // test.bmpの読み込み
    GHandle = LoadGraph( "test1.bmp" ) ;

    // グラフィックの描画
    DrawGraph( 0 , 0 , GHandle , FALSE ) ;

    // 読み込んだ画像のグラフィックハンドルを削除
    DeleteGraph( GHandle ) ;

    // キー待ち(『WaitKey』を使用)
    WaitKey() ;

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
