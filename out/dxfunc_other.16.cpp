#include "DxLib.h"

int main()
{
    int handle, i, j, w, h, r, g, b, a ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 ) return -1;

    // 画像を ARGB8 形式で読み込み
    handle = LoadARGB8ColorSoftImage( "Test1.bmp" ) ;

    // 画像のサイズを取得
    GetSoftImageSize( handle, &w, &h ) ;

    // 画像の全ピクセルのアルファ値を 128 にする
    for( i = 0; i < h; i ++ )
    {
        for( j = 0; j < w; j ++ )
        {
            // １ドットの色を取得
            GetPixelSoftImage( handle, j, i, &r, &g, &b, &a ) ;

            // アルファ値を 128 にして書き込み
            DrawPixelSoftImage( handle, j, i, r, g, b, 128 ) ;
        }
    }

    // 画面に画像を描画
    DrawSoftImage( 0, 0, handle ) ;

    // 使い終わったら解放
    DeleteSoftImage( handle ) ;

    // キー入力待ち
    WaitKey();

    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}
