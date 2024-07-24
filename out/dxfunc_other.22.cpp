#include "DxLib.h"

int main()
{
    int handle, w, h, handle2 ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 ) return -1;

    // 画像の読み込み
    handle = LoadSoftImage( "Test1.bmp" ) ;

    // 画像のサイズを取得
    GetSoftImageSize( handle, &w, &h ) ;

    // 読み込んだ画像と同じサイズの空パレット画像の作成
    handle2 = MakePAL8ColorSoftImage( w, h ) ;

    // 空パレット画像に読み込んだ画像を転送
    BltSoftImage( 0, 0, w, h, handle, 0, 0, handle2 ) ;

    // 画面に描画
    DrawSoftImage( 0, 0, handle2 ) ;

    // 使い終わったら解放
    DeleteSoftImage( handle ) ;
    DeleteSoftImage( handle2 ) ;

    // キー入力待ち
    WaitKey();

    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}
