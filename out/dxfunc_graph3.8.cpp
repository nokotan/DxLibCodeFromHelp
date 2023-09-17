#include "DxLib.h"

int main()
{
    int i ;
    unsigned int Cr ;
    int x , y ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが発生したら終了
    }

    // 描画先画面を表にする
    SetDrawScreen( DX_SCREEN_FRONT ) ;

    // １００００個四角形を描きます
    for( i = 0 ; i < 10000 ; i ++ )
    {
        // ランダムな色を取得する『GetRand』使用
        Cr = GetColor( GetRand( 255 ) , GetRand( 255 ) , GetRand( 255 ) ) ;

        // ランダムな位置に四角形を描く 
        x = GetRand( 639 ) ;
        y = GetRand( 479 ) ;
        DrawBox( x , y , x + GetRand( 639 ) , y + GetRand( 479 ) , Cr , TRUE ) ;
    }

    WaitKey() ;        // 結果を見るためにキー待ち(『WaitKey』を使用)

    // 画面を初期化
    ClearDrawScreen() ;

    // 描画先画面を裏にする
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // １００００個四角形を描きます
    for( i = 0 ; i < 10000 ; i ++ )
    {
        // ランダムな色を取得する『GetRand』使用
        Cr = GetColor( GetRand( 255 ) , GetRand( 255 ) , GetRand( 255 ) ) ;

        // ランダムな位置に四角形を描く 
        x = GetRand( 639 ) ;
        y = GetRand( 479 ) ;
        DrawBox( x , y , x + GetRand( 639 ) , y + GetRand( 479 ) , Cr , TRUE ) ;
    }

    // 裏画面の内容を表画面に反映します
    ScreenFlip() ;

    WaitKey() ;        // 結果を見るためにキー待ち(『WaitKey』を使用)

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
