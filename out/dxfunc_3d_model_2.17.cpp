#include "DxLib.h"

int main()
{
    int ModelHandle ;
    int WaitCounter, ViewPattern ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "TexAddrTransfTest.mqo" ) ;

    // 描画先を裏画面に変更
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // 画面に映る位置に３Ｄモデルを移動
    MV1SetPosition( ModelHandle, VGet( 320.0f, 240.0f, 600.0f ) ) ;

    // 描画するパターンと、描画パターンを変更する間隔をカウントする変数の初期化
    ViewPattern = 0 ;
    WaitCounter = 0 ;

    // ＥＳＣキーが押されるかウインドウが閉じられるまでループ
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // 描画するパターンを変更する処理
        WaitCounter ++ ;
        if( WaitCounter == 60 )
        {
            WaitCounter = 0 ;

            // ６０フレーム経過したら描画パターンを変更
            ViewPattern ++ ;
            if( ViewPattern == 4 )
            {
                ViewPattern = 0 ;
            }
        }

        // 描画するパターンに応じてテクスチャ座標のＵ値をずらす値を変更
        MV1SetFrameTextureAddressTransform( ModelHandle, 0, 0.25f * ViewPattern, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f ) ;

        // モデルの描画
        MV1DrawModel( ModelHandle ) ;

        // 裏画面の内容を表画面に反映
        ScreenFlip() ;
    }

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
