#include "DxLib.h"

int main()
{
    int FontHandle ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
         return -1;    // エラーが起きたら直ちに終了

    // 縦書きフォントを作成
    FontHandle = CreateFontToHandle( "@ＭＳ 明朝", -1, -1, -1 ) ;

    // 文字列を縦書き
    DrawVStringToHandle( 0, 0, "縦書きフォント", GetColor( 255,255,255 ), FontHandle ) ;

    // 作成したフォントハンドルを削除する
    DeleteFontToHandle( FontHandle ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    return 0 ;
}
