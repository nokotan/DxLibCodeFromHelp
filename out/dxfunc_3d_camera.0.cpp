#include "DxLib.h"

int main()
{
    int ModelHandle, i ;
    float Near, Far ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // モデルの読み込み
    ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;

    // Near Far 値の初期化
    Near = 100.0f ;
    Far = 2000.0f ;

    // 描画先を裏画面にする
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // ＥＳＣキーが押されるかウインドウが閉じられるまでループ
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // 上下のキー入力で Far を操作
        if( CheckHitKey( KEY_INPUT_UP ) == 1 )
        {
            Far += 20.0f ;
        }
        if( CheckHitKey( KEY_INPUT_DOWN ) == 1 )
        {
            Far -= 20.0f ;
        }

        // 左右のキーで Near を操作
        if( CheckHitKey( KEY_INPUT_LEFT ) == 1 )
        {
            Near -= 20.0f ;
        }
        if( CheckHitKey( KEY_INPUT_RIGHT ) == 1 )
        {
            Near += 20.0f ;
        }

        // Near の値が 0.0f 以下になっていたら補正
        if( Near <= 0.0f ) Near = 10.0f ;

        // Far の値が Near より小さくなっていたら補正
        if( Far <= Near ) Far = Near + 10.0f ;

        // Near, Far クリップの距離を設定
        SetCameraNearFar( Near, Far ) ; 

        // モデルを距離を変えて８個描画
        for( i = 0 ; i < 8 ; i ++ )
        {
            // モデルの座標を設定
            MV1SetPosition( ModelHandle, VGet( 320.0f, 180.0f, 100.0f + i * 400.0f ) ) ;

            // モデルの描画
            MV1DrawModel( ModelHandle ) ;
        }

        // 画面左上に Near の値と Far の値を描画
        DrawFormatString( 0, 0, GetColor( 255,255,255 ), "Near %f  Far %f", Near, Far ) ;

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
