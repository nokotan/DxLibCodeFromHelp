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

    // ロードしたマスクデータを画面の左上に描画します
    DrawMask( 0 , 0 , MaskHandle , DX_MASKTRANS_NONE ) ;

    // 画面いっぱいに赤い四角を描きます
    DrawBox( 0 , 0 , 640 , 480 , GetColor( 255 , 0 , 0 ) , TRUE ) ;

    // キーの入力待ちをします
    WaitKey() ;

    // マスクデータを削除します
    DeleteMask( MaskHandle ) ;

    // マスク画面を削除します
    DeleteMaskScreen() ;

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
