#include "DxLib.h"

int main()
{
    int ModelHandle ;
    float Rotate ;
    MATRIX Matrix ;

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

    // カメラの回転値を初期化
    Rotate = 0.0f ;

    // ＥＳＣキーが押されるかウインドウが閉じられるまでループ
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // 左右キーでカメラの回転値を変更
        if( CheckHitKey( KEY_INPUT_LEFT ) == 1 )
        {
            Rotate -= DX_PI_F / 60.0f ;
        }
        if( CheckHitKey( KEY_INPUT_RIGHT ) == 1 )
        {
            Rotate += DX_PI_F / 60.0f ;
        }

        // 回転値を使用してＹ軸の回転行列を作成
        Matrix = MGetRotY( Rotate ) ;

        // 回転行列をビュー行列としてセット
        SetCameraViewMatrix( Matrix ) ;

        // モデルをカメラを囲むように４個描画
        MV1SetPosition( ModelHandle, VGet( 0.0f, 0.0f, 800.0f ) ) ;
        MV1DrawModel( ModelHandle ) ;

        MV1SetPosition( ModelHandle, VGet( 0.0f, 0.0f, -800.0f ) ) ;
        MV1DrawModel( ModelHandle ) ;

        MV1SetPosition( ModelHandle, VGet( 800.0f, 0.0f, 0.0f ) ) ;
        MV1DrawModel( ModelHandle ) ;

        MV1SetPosition( ModelHandle, VGet( -800.0f, 0.0f, 0.0f ) ) ;
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
