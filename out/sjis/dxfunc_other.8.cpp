#include "DxLib.h"

int main()
{
    // タイトルを test に変更
    SetMainWindowText( "test" ) ;

    // ウインドウモードに変更
    ChangeWindowMode( TRUE ) ;

    // ＤＸライブラリ初期化処理
    if( DxLib_Init() == -1 )
         return -1;    // エラーが起きたら直ちに終了

    // キーの入力待ち(『WaitKey』を使用)
    WaitKey() ;

    // ＤＸライブラリ使用の終了処理
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
