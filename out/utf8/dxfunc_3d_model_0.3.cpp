#include "DxLib.h"

int main()
{
    int ModelHandle, AttachIndex ;
    float TotalTime, PlayTime ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // 次に読み込むモデルの物理演算モードをリアルタイム物理演算にする
    MV1SetLoadModelUsePhysicsMode( DX_LOADMODEL_PHYSICS_REALTIME ) ;

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "Test.pmd" ) ;

    // 描画先を裏画面に変更
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // カメラに映る範囲( カメラからの距離の範囲 )を設定
    SetCameraNearFar( 10.0f, 1000.0f ) ;

    // カメラの位置と向きを設定
    SetCameraPositionAndTarget_UpVecY( VGet( 0.0f, 19.0f, -22.5f ), VGet( 0.0f, 10.0f, 0.0f ) ) ;

    // ３Ｄモデルの０番目のアニメーションをアタッチする
    AttachIndex = MV1AttachAnim( ModelHandle, 0, -1, FALSE ) ;

    // アタッチしたアニメーションの総再生時間を取得する
    TotalTime = MV1GetAttachAnimTotalTime( ModelHandle, AttachIndex ) ;

    // 物理演算の状態をリセット
    MV1PhysicsResetState( ModelHandle ) ;

    // 再生時間の初期化
    PlayTime = 0.0f ;

    // 何かキーが押されるかウインドウが閉じられるまでループ
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // 再生時間を進める
        PlayTime += 0.5f ;

        // 再生時間がアニメーションの総再生時間に達したら再生時間を０に戻す
        if( PlayTime >= TotalTime )
        {
            PlayTime = 0.0f ;

            // 再生時間をセットする
            MV1SetAttachAnimTime( ModelHandle, AttachIndex, PlayTime ) ;

            // モーションがループしたときに位置が移動することがあるので物理演算の状態をリセット
            MV1PhysicsResetState( ModelHandle ) ;
        }
        else
        {
            // 再生時間をセットする
            MV1SetAttachAnimTime( ModelHandle, AttachIndex, PlayTime ) ;
        }

        // 物理演算を６０分の１秒経過したという設定で実行
        MV1PhysicsCalculation( ModelHandle, 1000.0f / 60.0f ) ;

        // ３Ｄモデルの描画
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
