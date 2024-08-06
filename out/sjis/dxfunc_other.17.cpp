#include "DxLib.h"

int main()
{
    int handle, i, j, w, h, r, g, b, a, fhandle ;
    void *image ;
    int image_size ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 ) return -1;

    // 画像ファイルを丸ごとメモリに読み込む
    fhandle = FileRead_open( "test1.bmp" ) ;
    image_size = FileRead_size( "test1.bmp" ) ;
    image = malloc( image_size ) ;
    FileRead_read( image, image_size, fhandle ) ;
    FileRead_close( fhandle ) ;

    // LoadSoftImageToMem で読み込む
    handle = LoadSoftImageToMem( image, image_size ) ;

    // 読み込んでしまった後はファイルイメージは必要なし
    free( image ) ;

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
