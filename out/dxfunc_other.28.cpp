#include "DxLib.h"

int main()
{
    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
         return -1;    // エラーが起きたら直ちに終了

    // 縦書きフォントを指定
    ChangeFont( "@ＭＳ 明朝" ) ;

    // 文字列を縦書き
    DrawVString( 0, 0, "縦書きフォント", GetColor( 255,255,255 ) ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    return 0 ;
}
