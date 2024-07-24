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

    // Vect1 と Vect2 の内積を画面に表示
    DrawFormatString( 0, 0, GetColor( 255,255,255 ), "Dot  %f", VDot( Vect1, Vect2 ) ) ;  

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
