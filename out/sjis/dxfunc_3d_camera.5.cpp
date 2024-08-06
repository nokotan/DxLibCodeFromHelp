#include "DxLib.h"

int main()
{
    int ModelHandle ;
    float Fov ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // モデルの読み込み
    ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;

    // 描画先を裏画面にする
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // 視野角を初期化
    Fov = 60.0f ;

    // ＥＳＣキーが押されるかウインドウが閉じられるまでループ
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // 左右キーで視野角の値を変更
        if( CheckHitKey( KEY_INPUT_LEFT ) == 1 )
        {
            Fov -= 2.0f ;
        }
        if( CheckHitKey( KEY_INPUT_RIGHT ) == 1 )
        {
            Fov += 2.0f ;
        }

        // 視野角が 8.0f 以下になったら補正
        if( Fov < 8.0f ) Fov = 8.0f ;

        // 視野角が 170.0f 以上になったら補正
        if( Fov > 170.0f ) Fov = 170.0f ;

        // 遠近法のセットアップ( ラジアン値に変換しています )
        SetupCamera_Perspective( Fov * DX_PI_F / 180.0f ) ;

        // カメラの前方にモデルを３個描画
        MV1SetPosition( ModelHandle, VGet( -1400.0f + 320.0f, 240.0f, 0.0f ) ) ;
        MV1DrawModel( ModelHandle ) ;

        MV1SetPosition( ModelHandle, VGet(     0.0f + 320.0f, 240.0f, 0.0f ) ) ;
        MV1DrawModel( ModelHandle ) ;

        MV1SetPosition( ModelHandle, VGet(  1400.0f + 320.0f, 240.0f, 0.0f ) ) ;
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
