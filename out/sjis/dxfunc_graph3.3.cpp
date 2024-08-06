#include "DxLib.h"

int main()
{
    // フルスクリーンモード時の解像度モードをモニターの最大解像度を使用するモードに設定
    SetFullScreenResolutionMode( DX_FSRESOLUTIONMODE_MAXIMUM ) ;

    // 画面の解像度を縦横２５６ドットに設定
    SetGraphMode( 256, 256, 32 ) ;

    // ＤＸライブラリ初期化処理
    if( DxLib_Init() == -1 )
    {
         return -1;      // エラーが発生したら終了
    }

    // 画面の中心に円を描画
    DrawCircle( 128, 128, 48, GetColor( 255,255,0 ), FALSE ) ;

    // キー待ち(『WaitKey』を使用)
    WaitKey() ;

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;           // ソフトの終了
}
