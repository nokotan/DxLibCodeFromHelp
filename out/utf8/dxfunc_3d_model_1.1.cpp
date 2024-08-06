#include "DxLib.h"

int main()
{
    int ModelHandle, AttachIndex, PlayAnim ;
    float TotalTime, PlayTime ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // 描画先を裏画面に変更
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // 画面に映る位置に３Ｄモデルを移動
    MV1SetPosition( ModelHandle, VGet( 320.0f, -300.0f, 600.0f ) ) ;

    // ３Ｄモデルの０番目のアニメーションをアタッチする
    AttachIndex = MV1AttachAnim( ModelHandle, 0, -1, FALSE ) ;

    // アタッチしたアニメーションの総再生時間を取得する
    TotalTime = MV1GetAttachAnimTotalTime( ModelHandle, AttachIndex ) ;

    // 再生時間の初期化
    PlayTime = 0.0f ;

    // 再生しているアニメーションを０番にする
    PlayAnim = 0 ;

    // アニメーション０の再生が終わるか、何かキーが押されるかウインドウが閉じられるまでループ
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // 再生時間を進める
        PlayTime += 100.0f ;

        // 再生時間がアニメーションの総再生時間に達したら次のアニメーションにする
        if( PlayTime >= TotalTime )
        {
            // 再生しているアニメーションを、今までが０番だったら１番に、１番だったら０番にする
            if( PlayAnim == 0 )
            {
                PlayAnim = 1 ;
            }
            else
            {
                PlayAnim = 0 ;
            }

            // 今までアタッチしていたアニメーションのデタッチ
            MV1DetachAnim( ModelHandle, AttachIndex ) ;

            // ３Ｄモデルの PlayAnim 番目のアニメーションをアタッチする
            AttachIndex = MV1AttachAnim( ModelHandle, PlayAnim, -1, FALSE ) ;

            // アタッチしたアニメーションの総再生時間を取得する
            TotalTime = MV1GetAttachAnimTotalTime( ModelHandle, AttachIndex ) ;

            // 再生時間の初期化
            PlayTime = 0.0f ;
        }

        // 再生時間をセットする
        MV1SetAttachAnimTime( ModelHandle, AttachIndex, PlayTime ) ;

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
