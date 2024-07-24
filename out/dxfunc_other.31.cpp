#include "DxLib.h"

int GraphHandle1, GraphHandle2;

// ファイルの復元関数
void ReloadFunction( void )
{
    // ファイルから読み込んだ画像を復元する
    ReloadFileGraphAll();

    // MakeScreen で作成したグラフィックハンドルを描画対象にする
    SetDrawScreen( GraphHandle1 );

    // 内容をクリア
    ClearDrawScreen();

    // 中心に四角形を描画する
    DrawBox( 64, 64, 256 - 64, 256 - 64, GetColor( 255,255,255 ), TRUE );

    // 描画先を裏画面に戻す
    SetDrawScreen( DX_SCREEN_BACK );
}

int main()
{
    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 ) return -1;

    // 画像復元関数を登録
    SetRestoreGraphCallback( ReloadFunction );

    // 256x256 の描画対象にできるグラフィックハンドルを作成する
    GraphHandle1 = MakeScreen( 256, 256 ) ;

    // MakeScreen で作成したグラフィックハンドルを描画対象にする
    SetDrawScreen( GraphHandle1 );

    // 内容をクリア
    ClearDrawScreen();

    // 中心に四角形を描画する
    DrawBox( 64, 64, 256 - 64, 256 - 64, GetColor( 255,255,255 ), TRUE );

    // ファイルから画像を直接読み込む
    GraphHandle2 = LoadGraph( "Test2.bmp" );

    // 描画先を裏画面にする
    SetDrawScreen( DX_SCREEN_BACK );

    // メインループ(ＥＳＣキーが押されたらループを抜ける)
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // 画面のクリア
        ClearDrawScreen();

        // 画像の描画
        DrawGraph(   0, 0, GraphHandle1, FALSE );
        DrawGraph( 300, 0, GraphHandle2, FALSE );

        // 裏画面の内容を表画面に反映
        ScreenFlip();
    }

    // グラフィックハンドルを削除
    DeleteGraph( GraphHandle1 ) ;
    DeleteGraph( GraphHandle2 ) ;

    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}
