#include "DxLib.h"

int main()
{
    int ModelHandle ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // モデルの２番目のフレームが持つ子フレームの中から AnkleR という名前のフレームの番号を検索して画面に描画する
    DrawFormatString( 0, 0, GetColor( 255,255,255 ), "%d", MV1SearchFrameChild( ModelHandle, 2, "AnkleR" ) ) ;

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // キーの入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
