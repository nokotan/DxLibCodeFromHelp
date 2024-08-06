#include "DxLib.h"

int main()
{
    MATRIX Matrix, Matrix2 ;
    VECTOR Vect1, Vect2, Vect3 ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // 平行移動する行列を Matrix2 に代入
    Matrix2 = MGetTranslate( VGet( 200.0f, 100.0f, 80.0f ) ) ;

    // Matrix2 の逆行列を Matrix に代入
    Matrix = MInverse( Matrix2 ) ;

    // 適当な値を Vect1 に代入
    Vect1 = VGet( 200.0f, 0.0f, 0.0f ) ;

    // Vect1 を Matrix2 を使用して変換した値を Vect2 に代入
    Vect2 = VTransform( Vect1, Matrix2 ) ;

    // Vect2 を Matrix2 の逆行列である Matrix で変換したものを Vect3 に代入
    Vect3 = VTransform( Vect2, Matrix ) ;

    // Matrix2 の値を画面に表示
    DrawString( 0, 0, "平行移動行列", GetColor( 255,255,255 ) ) ;
    DrawFormatString( 0, 16, GetColor( 255,255,255 ), "m00 %f  m01 %f  m02 %f  m03 %f",
        Matrix2.m[0][0], Matrix2.m[0][1], Matrix2.m[0][2], Matrix2.m[0][3] ) ;

    DrawFormatString( 0, 32, GetColor( 255,255,255 ), "m10 %f  m11 %f  m12 %f  m13 %f",
        Matrix2.m[1][0], Matrix2.m[1][1], Matrix2.m[1][2], Matrix2.m[1][3] ) ;

    DrawFormatString( 0, 48, GetColor( 255,255,255 ), "m20 %f  m21 %f  m22 %f  m23 %f",
        Matrix2.m[2][0], Matrix2.m[2][1], Matrix2.m[2][2], Matrix2.m[2][3] ) ;

    DrawFormatString( 0, 64, GetColor( 255,255,255 ), "m30 %f  m31 %f  m32 %f  m33 %f",
        Matrix2.m[3][0], Matrix2.m[3][1], Matrix2.m[3][2], Matrix2.m[3][3] ) ;

    // Matrix の値を画面に表示
    DrawString( 0, 192, "逆行列", GetColor( 255,255,255 ) ) ;
    DrawFormatString( 0, 208, GetColor( 255,255,255 ), "m00 %f  m01 %f  m02 %f  m03 %f",
        Matrix.m[0][0], Matrix.m[0][1], Matrix.m[0][2], Matrix.m[0][3] ) ;

    DrawFormatString( 0, 224, GetColor( 255,255,255 ), "m10 %f  m11 %f  m12 %f  m13 %f",
        Matrix.m[1][0], Matrix.m[1][1], Matrix.m[1][2], Matrix.m[1][3] ) ;

    DrawFormatString( 0, 240, GetColor( 255,255,255 ), "m20 %f  m21 %f  m22 %f  m23 %f",
        Matrix.m[2][0], Matrix.m[2][1], Matrix.m[2][2], Matrix.m[2][3] ) ;

    DrawFormatString( 0, 256, GetColor( 255,255,255 ), "m30 %f  m31 %f  m32 %f  m33 %f",
        Matrix.m[3][0], Matrix.m[3][1], Matrix.m[3][2], Matrix.m[3][3] ) ;

    // 変換元のベクトル値 Vect1 を画面に表示
    DrawString( 0, 288, "変換前のベクトル", GetColor( 255,255,255 ) ) ;
    DrawFormatString( 0, 304, GetColor( 255,255,255 ), "x=%f y=%f z=%f", Vect1.x, Vect1.y, Vect1.z ) ;

    // 変換後のベクトル値 Vect2 を画面に表示
    DrawString( 0, 336, "平行移動後のベクトル", GetColor( 255,255,255 ) ) ;
    DrawFormatString( 0, 352, GetColor( 255,255,255 ), "x=%f y=%f z=%f", Vect2.x, Vect2.y, Vect2.z ) ;

    // 変換後のベクトル値 Vect3 を画面に表示
    DrawString( 0, 384, "逆行列乗算後のベクトル", GetColor( 255,255,255 ) ) ;
    DrawFormatString( 0, 400, GetColor( 255,255,255 ), "x=%f y=%f z=%f", Vect3.x, Vect3.y, Vect3.z ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
