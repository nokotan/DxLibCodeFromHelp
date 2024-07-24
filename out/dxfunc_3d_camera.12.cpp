#include "DxLib.h"

int main()
{
    VECTOR Position ;
    VECTOR BoxPos1, BoxPos2 ;
    float XAdd ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // 描画先を裏画面にする
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // Ｚバッファを使用する
    SetUseZBuffer3D( TRUE ) ;

    // Ｚバッファへの書き込みを行う
    SetWriteZBuffer3D( TRUE ) ; 

    // 飛び回るボックスの座標を初期化
    Position = VGet( 320, 240, 0.0f ) ;

    // 飛び回るボックスのＸ軸の移動速度をセット
    XAdd = 8.0f ;

    // ＥＳＣキーが押されるかウインドウが閉じられるまでループ
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // 画面を初期化
        ClearDrawScreen() ;

        // ボックスの座標を更新
        Position.x += XAdd ;

        // もし画面内から大きく外れたら方向を反転する
        if( Position.x < -200.0f || Position.x > 840.0f )
        {
            XAdd = -XAdd ;
        }

        // ボックスを現す２点の座標を準備
        BoxPos1 = VSub( Position, VGet( 10.0f, 10.0f, 10.0f ) ) ;
        BoxPos2 = VAdd( Position, VGet( 10.0f, 10.0f, 10.0f ) ) ;

        // 画面内にボックスが入っていないかどうかを描画する
        if( CheckCameraViewClip_Box( BoxPos1, BoxPos2 ) == TRUE )
        {
            DrawString( 0, 0, "Screen Out:Yes", GetColor( 255,255,255 ) ) ;
        }
        else
        {
            DrawString( 0, 0, "Screen Out:No", GetColor( 255,255,255 ) ) ;
        }

        // ボックスを描画する
        DrawCube3D( BoxPos1, BoxPos2, GetColor( 255,255,255 ), GetColor( 0,0,0 ), TRUE ) ;

        // 裏画面の内容を表画面に反映
        ScreenFlip() ;
    }

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
