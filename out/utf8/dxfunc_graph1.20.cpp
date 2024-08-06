#include "DxLib.h"

int main()
{
    int GHandle ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // test1.bmpの読み込み
    GHandle = LoadGraph( "test1.bmp" ) ;

    // 描画輝度を赤のみにセット
    SetDrawBright( 255 , 0 , 0 ) ;

    // グラフィックの描画
    DrawGraph( 0 , 0 , GHandle , FALSE ) ;

    // 読み込んだ画像のグラフィックハンドルを削除
    DeleteGraph( GHandle ) ;

    // キー待ち(『WaitKey』を使用)
    WaitKey() ;

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
