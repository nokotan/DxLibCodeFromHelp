#include <string.h> 
#include "DxLib.h"

int main()
{
    int StrWidth , StrLen ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() == -1 ) return -1 ;

    // 最初の文字列を描画
    DrawString( 0 , 0 , "今日もいい天気だ" , GetColor( 255 , 255 , 255 ) ) ;

    // 文字列の長さを取得
    StrLen = strlen( "今日もいい天気だ" ) ;

    // 描画時の文字列の幅を取得
    StrWidth = GetDrawStringWidth( "今日もいい天気だ" , StrLen ) ;

    // 「今日もいい天気だ」の直後に新たな文字列を描画
    DrawString( StrWidth , 0 , "明日も晴れると良いなあ" , GetColor( 255 , 255 , 255 ) ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの使用終了
    DxLib_End() ;

    // 終了
    return 0 ;
}
