#include "DxLib.h"

int main()
{
    int LineLength ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() == -1 ) return -1 ;

    // 線の長さ入力指示文字列の描画
    DrawString( 0 , 0 , "線の長さを入力してください(０～６４０)" , GetColor( 255 , 255 , 255 ) ) ;

    // 線の長さ入力
    LineLength = KeyInputNumber( 0 , 16 , 640 , 0 , FALSE ) ;

    // 画面の初期化
    ClearDrawScreen() ;

    // 線の描画
    DrawLine( 0 , 100 , LineLength , 100 , GetColor( 255 , 255 , 255 ) ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの使用終了
    DxLib_End() ;

    // 終了
    return 0 ;
}
