#include "DxLib.h"

int main()
{
    int CharBytes ;
    int CharNum ;
    int i ;
    const char *String = "aあbいcうdえeお" ;

    // ウインドウモードで起動
    ChangeWindowMode( TRUE ) ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 ) return -1 ;

    // 文字の数を数える
    i = 0 ;
    CharNum = 0 ;
    while( String[ i ] != '\0' )
    {
        // 文字のバイト数を取得
        CharBytes = GetCharBytes( DX_CHARCODEFORMAT_SHIFTJIS, &String[ i ] ) ;

        // 文字の数を増やす
        CharNum ++ ;

        // 調べる位置を移動する
        i += CharBytes ;
    }

    // 結果を表示
    DrawFormatString( 0, 0, GetColor( 255,255,255 ), "「%s」の文字数は %d です", String, CharNum ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}
