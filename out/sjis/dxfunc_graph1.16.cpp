#include "DxLib.h"

int main()
{
    int GHandle , GHandle2 ;
    int i ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // test1.bmpの読み込み
    GHandle = LoadGraph( "test1.bmp" ) ;

    // 適当な座標に１０回描画
    for( i = 0 ; i < 10 ; i ++ )
    {
        // 画像をランダムな座標に描画する(『GetRand』使用)
        DrawGraph( GetRand( 639 ), GetRand( 479 ), GHandle, TRUE ) ;
    }

    // 空のグラフィックを作成
    GHandle2 = MakeGraph( 128 , 128 ) ;

    // 適当な領域を取りこむ
    GetDrawScreenGraph( 156 , 24 , 156 + 128 , 24 + 128 , GHandle2 ) ;
                
    // 取り込んだ画像で１０回描画 
    for( i = 0 ; i < 10 ; i ++ )
    {
        // 画像をランダムな座標に描画する(『GetRand』使用)
        DrawGraph( GetRand( 639 ), GetRand( 479 ), GHandle2, TRUE ) ;
    }

    // 全グラフィックを初期化
    InitGraph() ;
                
    WaitKey() ;        // 結果を見るためにキー待ち(『WaitKey』を使用)

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
