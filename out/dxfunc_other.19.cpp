#include "DxLib.h"

int main()
{
    int handle, i, j, grhandle ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 ) return -1;

    // 空のフルカラー画像を作成する
    handle = MakeXRGB8ColorSoftImage( 256, 256 ) ;

    // 縦方向に黒から赤にグラデーションした画像を作成する
    for( i = 0; i < 256; i ++ )
    {
        for( j = 0; j < 256; j ++ )
        {
            // 色をセット
            DrawPixelSoftImage( handle, j, i, i, 0, 0, 0 ) ;
        }
    }

    // グラフィックハンドルを作成
    grhandle = CreateGraphFromSoftImage( handle ) ;

    // 使い終わったら解放
    DeleteSoftImage( handle ) ;

    // グラフィックハンドルを描画
    DrawGraph( 0, 0, grhandle, TRUE ) ;

    // グラフィックハンドルの削除
    DeleteGraph( grhandle ) ;

    // キー入力待ち
    WaitKey();

    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}
