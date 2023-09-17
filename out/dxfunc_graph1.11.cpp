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

    // 読みこんだグラフィックを自由変形描画
    DrawModiGraph( 0 , 0 , 145 , 62 , 168 , 121 , 12 , 56 , GHandle , TRUE ) ;

    // 読み込んだ画像のグラフィックハンドルを削除
    DeleteGraph( GHandle ) ;
                
    WaitKey() ;        // 結果を見るためにキー待ち(『WaitKey』を使用)

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
