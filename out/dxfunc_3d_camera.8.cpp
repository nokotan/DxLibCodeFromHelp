#include "DxLib.h"

int main()
{
    int ModelHandle, AttachIndex ;
    float TotalTime, PlayTime ;
    VECTOR ScreenPos ;

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

    // 何かキーが押されるかウインドウが閉じられるまでループ
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // 再生時間を進める
        PlayTime += 100.0f ;

        // 再生時間がアニメーションの総再生時間に達したら再生時間を０に戻す
        if( PlayTime >= TotalTime )
        {
            PlayTime = 0.0f ;
        }

        // 再生時間をセットする
        MV1SetAttachAnimTime( ModelHandle, AttachIndex, PlayTime ) ;

        // ３Ｄモデルの描画
        MV1DrawModel( ModelHandle ) ;

        // ナンバー２６のフレームの画面上での座標を取得する
        ScreenPos = ConvWorldPosToScreenPos( MV1GetFramePosition( ModelHandle, 26 ) ) ;

        // 取得したスクリーン座標に四角形を描画
        DrawBox( ScreenPos.x - 2, ScreenPos.y - 2, ScreenPos.x + 2, ScreenPos.y + 2, GetColor( 255,0,0 ), TRUE ) ;

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
