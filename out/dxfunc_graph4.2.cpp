#include "DxLib.h"

int main()
{
    int MaskHandle[ 16 ] ;
    int i ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // 描画先画面を裏画面にします
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // マスク画面を作成します
    CreateMaskScreen() ;

    // マスクデータをロードします
    LoadDivMask( "testMask2.bmp", 16, 8, 2, 8, 16, MaskHandle ) ;

    // マスクを画面全体にタイル上に描画しアニメーションさせます
    for( i = 0 ; i < 16 ; i ++ )
    {
        // 画面初期化
        ClearDrawScreen() ;

        // 画面全体にタイル上描画
        DrawFillMask( 0 , 0 , 640 , 480 , MaskHandle[ i ] ) ;

        // 画面いっぱいに青い四角を描きます
        DrawBox( 0 , 0 , 640 , 480 , GetColor( 0 , 0 , 255 ) , TRUE ) ;

        // 時間待ち
        WaitTimer( 100 ) ;

        // 裏画面の内容を表画面に反映させる
        ScreenFlip() ;
    }

    // 最後の時間待ち
    WaitTimer( 1000 ) ;

    // マスクデータを削除します
    for( i = 0 ; i < 16 ; i ++ )
    {
        DeleteMask( MaskHandle[ i ] ) ;
    }

    // マスク画面を削除します
    DeleteMaskScreen() ;

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
