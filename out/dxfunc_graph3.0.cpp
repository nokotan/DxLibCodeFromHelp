#include "DxLib.h"

int main()
{
    // ＤＸライブラリ初期化
    if( DxLib_Init() == -1 ) return 0;

    // Ｈｅｌｌｏ Ｃ Ｗｏｒｌｄ！と表示、最後に改行
    printfDx( "Hello Ｃ World!\n" ) ;

    // 画面に適当に数値を描画
    printfDx( " 600 x 800 = %d \n" , 600 * 800 ) ;

    // 画面が降り切れるほど文字列を描画
    printfDx( "実験実験実験実験実験実験実験実験実験" ) ;
    printfDx( "実験実験実験実験実験実験実験実験実験" ) ;
    printfDx( "実験実験実験実験実験実験実験実験実験実験" ) ;

    // 画面を青くする
    DrawBox( 0 , 0 , 640 , 480 , GetColor( 0 , 0 , 255 ) , TRUE ) ;

    // 出力した文字列を表示
    ScreenFlip() ;

    // キーが押されるまで待つ
    WaitKey() ;

    // ＤＸライブラリの使用終了
    DxLib_End() ;

    return 0 ;
}
