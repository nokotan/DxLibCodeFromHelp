#include "DxLib.h"

int main()
{
    unsigned int Cr ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが発生したら終了
    }

    // 描画可能領域セット
    SetDrawArea( 0 , 0 , 320 , 480 ) ;

    // 青色の値を取得
    Cr = GetColor( 0 , 0 , 255 ) ;

    // 青い四角形の描画
    DrawBox( 0 , 0 , 640 , 480 , Cr , TRUE ) ;

    // キー待ち(『WaitKey』を使用)
    WaitKey() ;

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
