#include "DxLib.h"

int main()
{
    VECTOR Vect1, Vect2 ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // Vect1 と Vect2 に値を代入
    Vect1 = VGet( 100.0f, 200.0f, 500.0f ) ;
    Vect2 = VGet( 30.0f, 100.0f, 80.0f ) ;

    // Vect1 から Vect2 を減算して結果を Vect1 に代入
    Vect1 = VSub( Vect1, Vect2 ) ;

    // Vect1 の内容を画面に表示
    DrawFormatString( 0, 0, GetColor( 255,255,255 ), "Vect1  x=%f y=%f z=%f", Vect1.x, Vect1.y, Vect1.z ) ;  

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
