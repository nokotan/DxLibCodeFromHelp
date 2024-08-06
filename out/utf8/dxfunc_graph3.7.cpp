#include "DxLib.h"

int main()
{
    unsigned int Cr ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが発生したら終了
    }

    // 灰色の値を取得
    Cr = GetColor( 128 , 128 , 128 ) ;

    // 線の描画
    DrawLine( 120 , 150 , 300 , 240 , Cr );

    WaitKey() ;        // キーの入力待ち(『WaitKey』を使用)

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
