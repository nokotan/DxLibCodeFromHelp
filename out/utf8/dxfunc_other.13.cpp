#include "DxLib.h"
#include <malloc.h>

int main()
{
    void *Buffer ;
    int FileSize, FileHandle, GrHandle ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() == -1 ) return -1 ;

    // ファイルのサイズを得る
    FileSize = FileRead_size( "test1.bmp" ) ;

    // ファイルを格納するメモリ領域の確保
    Buffer = malloc( FileSize ) ;

    // test1.bmp を開く
    FileHandle = FileRead_open( "test1.bmp" ) ;

    // ファイルを丸ごとメモリに読み込む
    FileRead_read( Buffer, FileSize, FileHandle ) ;

    // ファイルを閉じる
    FileRead_close( FileHandle ) ;

    // グラフィックハンドルの作成
    GrHandle = CreateGraphFromMem( Buffer, FileSize ) ;

    // メモリの解放
    free( Buffer ) ;

    // 画面に描画
    DrawGraph( 0, 0, GrHandle, TRUE ) ; 

    // グラフィックハンドルの削除
    DeleteGraph( GrHandle ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    return 0 ;
}
