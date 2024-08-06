#include "DxLib.h"

int main()
{
    unsigned char MaskData[ 16 ][ 16 ] ;
    int i , j ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // 描画先を裏画面にします
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // マスク画面を作成します
    CreateMaskScreen() ;

    // マスクデータを白で埋めます
    for( i = 0 ; i < 16 ; i ++ )
        for( j = 0 ; j < 16 ; j ++ )
            MaskData[ i ][ j ] = 0xff ;

    // ループ
    for( i = 0 ; i < 16 ; i ++ )
    {
        // 画面を初期化
        ClearDrawScreen() ;

        // マスクのデータを一部変更
        for( j = 0 ; j < 16 ; j ++ )
            MaskData[ i ][ j ] = 0 ;

        // マスクのデータを直接画面に転送
        DrawMaskToDirectData( 0 , 0 , 16 , 16 , MaskData , DX_MASKTRANS_NONE ) ;

        // 白の四角を画面全体に描画します
        DrawBox( 0 , 0 , 640 , 480 , GetColor( 255 , 255 , 255 ) , TRUE ) ;

        // 裏画面の内容を表画面に反映させます
        ScreenFlip() ;

        // 時間待ち
        WaitTimer( 100 ) ;
    }
    // マスク画面を削除します
    DeleteMaskScreen() ;

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
