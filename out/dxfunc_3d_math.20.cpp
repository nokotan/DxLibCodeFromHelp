#include "DxLib.h"

int main()
{
    MATRIX Matrix ;
    VECTOR Vect1, Vect2 ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // 基本軸上のベクトルを
    // 基本軸上のＹのプラス値をＸ軸
    // 基本軸上のＺのプラス値をＹ軸
    // 基本軸上のＸのマイナス値をＺ軸とし、
    // 且つ基本軸上の x=100.0f y=0.0f z=200.0f を原点とする
    // ３軸上のベクトルに変換する行列の取得
    Matrix = MGetAxis2( 
                VGet(  0.0f, 1.0f, 0.0f ),
                VGet(  0.0f, 0.0f, 1.0f ),
                VGet( -1.0f, 0.0f, 0.0f ),
                VGet( 100.0f, 0.0f, 200.0f ) ) ;

    // 任意の３軸上の原点に位置する基本軸上のベクトルを Vect に代入
    Vect1 = VGet( 100.0f, 0.0f, 200.0f ) ;

    // Vect1 を Matrix を使用して変換した値を Vect2 に代入
    Vect2 = VTransform( Vect1, Matrix ) ;

    // Matrix の値を画面に表示
    DrawString( 0, 0, "変換行列", GetColor( 255,255,255 ) ) ;
    DrawFormatString( 0, 16, GetColor( 255,255,255 ), "m00 %f  m01 %f  m02 %f  m03 %f",
        Matrix.m[0][0], Matrix.m[0][1], Matrix.m[0][2], Matrix.m[0][3] ) ;

    DrawFormatString( 0, 32, GetColor( 255,255,255 ), "m10 %f  m11 %f  m12 %f  m13 %f",
        Matrix.m[1][0], Matrix.m[1][1], Matrix.m[1][2], Matrix.m[1][3] ) ;

    DrawFormatString( 0, 48, GetColor( 255,255,255 ), "m20 %f  m21 %f  m22 %f  m23 %f",
        Matrix.m[2][0], Matrix.m[2][1], Matrix.m[2][2], Matrix.m[2][3] ) ;

    DrawFormatString( 0, 64, GetColor( 255,255,255 ), "m30 %f  m31 %f  m32 %f  m33 %f",
        Matrix.m[3][0], Matrix.m[3][1], Matrix.m[3][2], Matrix.m[3][3] ) ;

    // 変換元のベクトル値 Vect1 を画面に表示
    DrawString( 0, 96, "変換前のベクトル", GetColor( 255,255,255 ) ) ;
    DrawFormatString( 0, 112, GetColor( 255,255,255 ), "x=%f y=%f z=%f", Vect1.x, Vect1.y, Vect1.z ) ;

    // 変換後のベクトル値 Vect2 を画面に表示
    DrawString( 0, 144, "変換後のベクトル", GetColor( 255,255,255 ) ) ;
    DrawFormatString( 0, 160, GetColor( 255,255,255 ), "x=%f y=%f z=%f", Vect2.x, Vect2.y, Vect2.z ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}