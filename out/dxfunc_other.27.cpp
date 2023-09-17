#include "DxLib.h"
#include <malloc.h>

int main()
{
    char *NameBuffer ;
    int FontNum ;
    int i ;

    // ＤＸライブラリ初期化処理
    if( DxLib_Init() == -1 ) return -1 ;

    // フォントの数を取得
    FontNum = EnumFontName( NULL , 0 ) ;

    // メモリの確保
    NameBuffer = ( char * )malloc( FontNum * 64 ) ;

    // フォント名の取得
    EnumFontName( NameBuffer , FontNum ) ;

    // フォントのサイズを変更
    SetFontSize( 32 ) ;

    // 最初から１０番目までのフォント名を画面に描画
    if( FontNum >= 10 ) FontNum = 10 ;
    for( i = 0 ; i < FontNum ; i ++ )
    {
        // フォントの変更
        ChangeFont( NameBuffer + 64 * i ) ;

        // フォント名の描画
        DrawString( 100 , i * 40 , NameBuffer + 64 * i , GetColor( 255, 255, 255 ) ) ;
    }

    // 確保したメモリの解放
    free( NameBuffer ) ;

    // キー入力を待つ
    WaitKey() ;

    // ＤＸライブラリ使用の終了処理
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
