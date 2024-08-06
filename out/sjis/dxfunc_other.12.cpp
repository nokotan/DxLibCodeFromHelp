#include "DxLib.h"

int main()
{
    int FileHandle ;
    char String[256] ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() == -1 ) return -1 ;

    // test.cpp ファイルを開く
    FileHandle = FileRead_open( "test.cpp" ) ;

    // １１バイト目までファイルポインタを移動する
    FileRead_seek( FileHandle, 11, SEEK_SET ) ;

    // 一行読む
    FileRead_gets( String, 256, FileHandle ) ;

    // 画面に描画
    DrawString( 0, 0, String, GetColor( 255,255,255 ) ) ;

    // キー入力を待つ
    WaitKey() ;

    // ファイルを閉じる
    FileRead_close( FileHandle ) ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    return 0 ;
}
