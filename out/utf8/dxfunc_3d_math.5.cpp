#include "DxLib.h"

int main()
{
    VECTOR Vect ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // Vect に値を代入
    Vect = VGet( 100.0f, 200.0f, 500.0f ) ;

    // Vect を 8.0f 倍して、その結果を Vect に代入
    Vect = VScale( Vect, 8.0f ) ;

    // Vect の内容を画面に表示
    DrawFormatString( 0, 0, GetColor( 255,255,255 ), "Vect  x=%f y=%f z=%f", Vect.x, Vect.y, Vect.z ) ;  

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
