#include "DxLib.h"
#include <math.h>

int main()
{
    int ModelHandle ;
    float Roll ;

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

    // カメラの視線の回転値を初期化
    Roll = 0.0f ;

    // ＥＳＣキーが押されるかウインドウが閉じられるまでループ
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // 左右キーでカメラの回転値を変更
        if( CheckHitKey( KEY_INPUT_LEFT ) == 1 )
        {
            Roll -= DX_PI_F / 60.0f ;
        }
        if( CheckHitKey( KEY_INPUT_RIGHT ) == 1 )
        {
            Roll += DX_PI_F / 60.0f ;
        }

        // カメラの位置と注視点をセット
        // 視点はＺ軸のマイナス800の位置
        // 注視点は原点
        // 上方向は Roll の値から算出
        SetCameraPositionAndTargetAndUpVec( 
            VGet( 0.0f, 0.0f, -800.0f ),
            VGet( 0.0f, 0.0f, 0.0f ),
            VGet( sin( Roll ), cos( Roll ), 0.0f ) ) ;

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
