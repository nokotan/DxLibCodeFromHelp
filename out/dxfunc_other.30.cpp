#include "DxLib.h"
#include <stdio.h>
#include <malloc.h>

int main()
{
    FILE *fp ;
    unsigned char *Data ;
    int Size, GrHandle, i ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() == -1 )
        return -1 ;

    // ファイル test1.enc を丸ごとメモリに読み込む
    {
        // バイナリモードで開く
        fp = fopen( "test1.enc", "rb" ) ;

        // ファイルのサイズを得る
        {
            // ファイルポインタをファイルの末端に
            fseek( fp, 0L, SEEK_END ) ;

            // ファイルの末端でファイルポインタのアドレスを
            // 取得すればそれはファイルのサイズ
            Size = ftell( fp ) ;

            // ファイルポインタをファイルの先頭に戻す
            fseek( fp, 0L, SEEK_SET ) ;
        }

        // ファイルを丸々読み込めるメモリ領域を確保する
        Data = ( unsigned char * )malloc( Size ) ;

        // ファイルを丸々読み込む
        fread( Data, Size, 1, fp ) ;

        // ファイルを閉じる
        fclose( fp ) ;
    }

    // ＮＯＴ演算の暗号を解く
    for( i = 0 ; i < Size ; i ++ )
    {
        // ＮＯＴ演算されたデータは、もう一回ＮＯＴ演算をすると元に戻る
        Data[i] = ~Data[i] ;
    }

    // 元に戻ったグラフィックデータでグラフィックハンドルを作成する
    GrHandle = CreateGraphFromMem( Data, Size ) ;

    // グラフィックを作成し終わったらグラフィックデータを
    // 格納していたメモリ領域を開放する
    free( Data ) ;

    // 画像を画面に描画
    DrawGraph( 0, 0, GrHandle, FALSE ) ;

    // グラフィックハンドルの削除
    DeleteGraph( GrHandle ) ;

    // キーが押されるまで待つ
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフト終了
    return 0 ;
}
