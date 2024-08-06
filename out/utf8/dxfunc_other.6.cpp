#include "DxLib.h"

int main()
{
    int i ;
    int Cr ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // 白色の値を取得
    Cr = GetColor( 255 , 255 , 255 ) ;

    // １０００個の点を描く
    for( i = 0 ; i < 1000 ; i ++ )
    {
        // ランダムな位置に点を描く（『GetRand』を使用） 
        DrawPixel( GetRand( 639 ) , GetRand( 479 ) , Cr ) ;
    }

    WaitKey() ;        // 結果を見るためにキー待ち(『WaitKey』を使用)

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
