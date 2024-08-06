#include "DxLib.h"

int main()
{
    // ＤＸライブラリの初期化
    if( DxLib_Init() == -1 ) return 0 ;

    // 画面を黄色で塗りつぶします
    DrawBox( 0 , 0 , 640 , 480 , GetColor( 128,128, 0) , TRUE ) ;

    // サイズを４０に変更
    SetFontSize( 40 ) ;

    // 『ＤＸライブラリ』と描画
    DrawString( 100 , 100 , "ＤＸライブラリ" , GetColor( 255,255,255 ) ) ;

    // フォントのタイプをエッジつきアンチエイリアスフォントに変更
    ChangeFontType( DX_FONTTYPE_ANTIALIASING_EDGE ) ;

    // 『ＤＸライブラリ』と描画
    DrawString( 100 , 160 , "ＤＸライブラリ" , GetColor( 255,255,255 ), GetColor( 0,0,0 ) ) ;


    // キー入力を待つ
    WaitKey() ;


    // ＤＸライブラリの終了
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
