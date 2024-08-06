#include "DxLib.h"

int main()
{
    char String[256] ;
    int FileHandle, y ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() == -1 ) return -1 ;

    // test.cpp を開く
    FileHandle = FileRead_open( "test.cpp" ) ;

    // 表示Ｙ座標の初期化
    y = 0 ;

    // ファイルの終端が来るまで表示する
    while( FileRead_eof( FileHandle ) == 0 )
    {
        // 一行読み込み
        FileRead_gets( String, 256, FileHandle ) ;

        // 画面に描画
        DrawString( 0, y, String, GetColor( 255,255,255 ) ) ;

        // 表示Ｙ座標を下にずらす
        y += 16 ;
    }

    // ファイルを閉じる
    FileRead_close( FileHandle ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    return 0 ;
}
