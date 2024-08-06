#include "DxLib.h"

int main()
{
    int handle, i, j, w, h, r, g, b, a ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 ) return -1;

    // 画像の読み込み
    handle = LoadSoftImage( "Test1.bmp" ) ;

    // 画像のサイズを取得
    GetSoftImageSize( handle, &w, &h ) ;

    // 画像の色を１ドットづつ参照して DrawBox で３倍の大きさにして描画
    for( i = 0; i < h; i ++ )
    {
        for( j = 0; j < w; j ++ )
        {
            // １ドットの色を取得
            GetPixelSoftImage( handle, j, i, &r, &g, &b, &a ) ;

            // DrawBox で描画
            DrawBox( j * 3, i * 3, j * 3 + 3, i * 3 + 3, GetColor( r, g, b ), TRUE ) ;
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
