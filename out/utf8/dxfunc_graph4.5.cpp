#include "DxLib.h"

int main()
{
    int MaskHandle ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;        // エラーが起きたら直ちに終了
    }

    // マスク画面を作成します
    CreateMaskScreen() ;

    // マスクデータをロードします
    MaskHandle = LoadMask( "testMask.bmp" ) ;

    // 画面全体にマスクをタイル上に並べて描画します
    DrawFillMask( 0 , 0 , 640 , 480 , MaskHandle ) ;

    // 画面いっぱいに緑の四角を描画
    DrawBox( 0 , 0 , 640 , 480 , GetColor( 0 , 255 , 0 ) , TRUE ) ;
    ScreenFlip() ;

    // キー入力待ち
    WaitKey() ;


    // マスク画面を無効にします
    SetUseMaskScreenFlag( FALSE );

    // もう一度画面いっぱいに緑の四角を描きます
    ClearDrawScreen() ;    // 画面初期化
    DrawBox( 0 , 0 , 640 , 480 , GetColor( 0 , 255 , 0 ) , TRUE ) ;
    ScreenFlip() ;

    // キー入力待ち
    WaitKey() ;


    // マスク画面を有効にします
    SetUseMaskScreenFlag( TRUE ) ;

    // 再び一度画面いっぱいに緑の四角を描きます
    ClearDrawScreen() ;    // 画面初期化
    DrawBox( 0 , 0 , 640 , 480 , GetColor( 0 , 255 , 0 ) , TRUE ) ;
    ScreenFlip() ;

    // キー入力待ち
    WaitKey() ;


    // マスクを削除します
    DeleteMask( MaskHandle ) ;

    // マスク画面を削除します
    DeleteMaskScreen() ;

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
