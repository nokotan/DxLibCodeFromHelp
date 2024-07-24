#include "DxLib.h"

int main()
{
    int MaskHandle ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // マスク画面を作成します
    CreateMaskScreen() ;

    // マスクデータをロードします
    MaskHandle = LoadMask( "testMask.bmp" ) ;

    // (100,200)-(400,400)の領域にマスクをタイル上に並べて描画します
    DrawFillMask( 100 , 200 , 400 , 400 , MaskHandle ) ;

    // 画面いっぱいに緑の四角を描画
    DrawBox( 0 , 0 , 640 , 480 , GetColor( 0 , 255 , 0 ) , TRUE ) ;

    // キー入力待ち
    WaitKey() ;

    // マスク画面を白で覆い尽くします
    FillMaskScreen( 1 ) ;

    // もう一度画面いっぱいに緑の四角を描きます
    DrawBox( 0 , 0 , 640 , 480 , GetColor( 0 , 255 , 0 ) , TRUE ) ;

    // キー入力待ち
    WaitKey() ;

    // マスクを削除します
    DeleteMask( MaskHandle ) ;

    // マスク画面を削除します
    DeleteMaskScreen() ;

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
