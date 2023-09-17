#include "DxLib.h"

int main()
{
    int GrHandle[ 20 ] ;
    int i ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 ) return -1 ;

    // 非同期読み込み設定に変更
    SetUseASyncLoadFlag( TRUE ) ;

    // Test1.bmp を 20回読み込む
    for( i = 0 ; i < 20 ; i ++ )
    {
        GrHandle[ i ] = LoadGraph( "Test1.bmp" ) ;
    }

    // 同期読み込み設定に変更
    SetUseASyncLoadFlag( FALSE ) ;

    // 描画先を裏画面にする
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // メインループ(何かキーが押されたらループを抜ける)
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {                                                       
        // 画面のクリア
        ClearDrawScreen() ;

        // 読み込みが終わっていたら画像を描画する
        for( i = 0 ; i < 20 ; i ++ )
        {
            if( CheckHandleASyncLoad( GrHandle[ i ] ) == FALSE )
            {
                DrawGraph( i * 32, 0, GrHandle[ i ], TRUE ) ;
            }
        }

        // 非同期読み込みの数を描画
        DrawFormatString( 0, 0, GetColor( 255,255,255 ), "非同期読み込みの数 %d", GetASyncLoadNum() ) ;

        // 裏画面の内容を表画面に反映
        ScreenFlip();
    }

    // 読み込んだ画像のグラフィックハンドルを削除する
    for( i = 0 ; i < 20 ; i ++ )
    {
        DeleteGraph( GrHandle[ i ] ) ;
    }

    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}
