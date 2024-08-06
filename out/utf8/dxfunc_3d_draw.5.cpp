#include "DxLib.h"

int main()
{
    int GrHandle ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // 画像の読み込み
    GrHandle = LoadGraph( "Test1.bmp" ) ;

    // ３Ｄ空間上に画像を描画
    DrawBillboard3D( VGet( 320.0f, 240.0f, 100.0f ), 0.5f, 0.5f, 120.0f, 0.0f, GrHandle, TRUE ) ;

    // 読み込んだ画像のグラフィックハンドルを削除
    DeleteGraph( GrHandle ) ;

    // キー入力待ちをする
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
