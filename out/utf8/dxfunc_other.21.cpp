#include "DxLib.h"

int main()
{
    int handle, i, j, r, g, b ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 ) return -1;

    // 画像の読み込み
    handle = LoadSoftImage( "Test1.bmp" ) ;

    // パレットの一覧を描画
    for( i = 0 ; i < 16 ; i ++ )
    {
        for( j = 0 ; j < 16 ; j ++ )
        {
            // パレットの色を取得する
            GetPaletteSoftImage( handle, j + i * 16, &r, &g, &b, 0 ) ;

            // DrawBox を使って描画
            DrawBox( j * 16, i * 16, j * 16 + 16, i * 16 + 16, GetColor( r, g, b ), TRUE ) ;
        }
    }

    // 使い終わったら解放
    DeleteSoftImage( handle ) ;

    // キー入力待ち
    WaitKey();

    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}
