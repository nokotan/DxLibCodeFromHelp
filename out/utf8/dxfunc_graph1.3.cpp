#include "DxLib.h"

int main()
{
    int handle;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 ) return -1;

    // 20x20サイズのアルファチャンネルなしの描画可能画像を作成する
    handle = MakeScreen( 20, 20, FALSE ) ;

    // 作成した画像を描画対象にする
    SetDrawScreen( handle ) ;

    // 画像に対して「あ」という文字を描画する
    DrawString( 0, 0, "あ", GetColor( 255, 255, 255 ) ) ;

    // 描画対象を表画面にする
    SetDrawScreen( DX_SCREEN_FRONT ) ;

    // 描画対象画像を画面いっぱいに拡大して描画する
    DrawExtendGraph( 0, 0, 640, 480, handle, FALSE ) ;

    // MakeScreen で作成したグラフィックハンドルの削除
    DeleteGraph( handle ) ;

    // キー入力待ち
    WaitKey();

    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}
