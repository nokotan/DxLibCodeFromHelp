#include "DxLib.h"

int main()
{
    VECTOR Position ;
    float XAdd ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // 描画先を裏画面にする
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // 飛び回る点の座標を初期化
    Position = VGet( 320, 240, 0.0f ) ;

    // 飛び回る点のＸ軸の移動速度をセット
    XAdd = 8.0f ;

    // ＥＳＣキーが押されるかウインドウが閉じられるまでループ
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // 画面を初期化
        ClearDrawScreen() ;

        // 点の座標を更新
        Position.x += XAdd ;

        // もし画面内から大きく外れたら方向を反転する
        if( Position.x < -100.0f || Position.x > 740.0f )
        {
            XAdd = -XAdd ;
        }

        // 画面内に座標が入っていないかどうかを描画する
        if( CheckCameraViewClip( Position ) == TRUE )
        {
            DrawString( 0, 0, "Screen Out:Yes", GetColor( 255,255,255 ) ) ;
        }
        else
        {
            DrawString( 0, 0, "Screen Out:No", GetColor( 255,255,255 ) ) ;
        }

        // 点を描画する
        DrawPixel3D( Position, GetColor( 255,255,255 ) ) ;

        // 裏画面の内容を表画面に反映
        ScreenFlip() ;
    }

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
