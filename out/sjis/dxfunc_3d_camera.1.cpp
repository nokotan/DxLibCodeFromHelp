#include "DxLib.h"

int main()
{
    int ModelHandle ;
    VECTOR CameraPos ;

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

    // カメラの座標を初期化
    CameraPos.x = 0.0f ;
    CameraPos.y = 0.0f ;
    CameraPos.z = -800.0f ;

    // ＥＳＣキーが押されるかウインドウが閉じられるまでループ
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // 方向キーでカメラの座標を移動
        if( CheckHitKey( KEY_INPUT_UP ) == 1 )
        {
            CameraPos.y += 20.0f ;
        }
        if( CheckHitKey( KEY_INPUT_DOWN ) == 1 )
        {
            CameraPos.y -= 20.0f ;
        }
        if( CheckHitKey( KEY_INPUT_LEFT ) == 1 )
        {
            CameraPos.x -= 20.0f ;
        }
        if( CheckHitKey( KEY_INPUT_RIGHT ) == 1 )
        {
            CameraPos.x += 20.0f ;
        }

        // カメラの位置と注視点をセット、注視点は原点
        SetCameraPositionAndTarget_UpVecY( CameraPos, VGet( 0.0f, 0.0f, 0.0f ) ) ;

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
