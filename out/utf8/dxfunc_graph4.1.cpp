#include "DxLib.h"

int main()
{
    int MaskHandle ;
    int i ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // マスク画面を作成します
    CreateMaskScreen() ;

    // マスクデータをロードします
    MaskHandle = LoadMask( "testMask.bmp" ) ;

    // ロードしたマスクデータを画面のランダムな位置に１０個描画します
    for( i = 0 ; i < 10 ; i ++ )
        DrawMask( GetRand( 639 ) , GetRand( 479 ) , MaskHandle , DX_MASKTRANS_NONE ) ;

    // 画面いっぱいに青い四角を描きます
    DrawBox( 0 , 0 , 640 , 480 , GetColor( 0 , 0 , 255 ) , TRUE ) ;

    // キーの入力待ちをします
    WaitKey() ;

    // マスクデータを削除します
    DeleteMask( MaskHandle ) ;

    // マスク画面を削除します
    DeleteMaskScreen() ;

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
