#include "DxLib.h"

int main()
{
    // ＤＸライブラリ初期化
    if( DxLib_Init() == -1 ) return 0;

    // 描画先画面を裏画面にする
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // なにかキーが押されるまでループ
    while( CheckHitKeyAll() == 0 )
    {
        // Ｈｅｌｌｏ Ｃ Ｗｏｒｌｄ！と表示
        printfDx( "Hello C World" ) ;

        // 画面を青くする
        DrawBox( 0 , 0 , 640 , 480 , GetColor( 0 , 0 , 255 ) , TRUE ) ;

        // 出力した文字列を表示
        ScreenFlip() ;

        // Windows依存処理
        if( ProcessMessage() == -1 ) break ;
    }

    // 画面の文字達を消す
    clsDx() ;

    // 画面にメッセージを表示
    printfDx( "消えましたか？" ) ;

    // 画面を赤くする
    DrawBox( 0 , 0 , 640 , 480 , GetColor( 255 , 0 , 0 ) , TRUE ) ;

    // 画面の状態を更新
    ScreenFlip() ;

    // キーが押されるまで待つ
    WaitKey() ;

    // ＤＸライブラリの使用終了
    DxLib_End() ;

    return 0 ;
}
