#include "DxLib.h"

int main()
{
    int ModelHandle ;
    int Screen ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // 描画可能なグラフィックのアンチエイリアス設定を行う
    SetCreateDrawValidGraphMultiSample( 4, 2 ) ;

    // 描画可能なグラフィックの作成
    Screen = MakeScreen( 640, 480, FALSE ) ;

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // 画面に映る位置に３Ｄモデルを移動
    MV1SetPosition( ModelHandle, VGet( 320.0f, -300.0f, 600.0f ) ) ;

    // 描画先を描画可能がグラフィックに設定
    SetDrawScreen( Screen ) ;

    // 画面を初期化
    ClearDrawScreen() ;

    // ３Ｄモデルの描画
    MV1DrawModel( ModelHandle ) ;

    // 描画先を裏画面に変更
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // 描画可能なグラフィックを描画
    DrawGraph( 0, 0, Screen, FALSE ) ;

    // 裏画面の内容を表画面に反映
    ScreenFlip() ;

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // MakeScreen で作成したグラフィックハンドルの削除
    DeleteGraph( Screen ) ;

    // キーの入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
