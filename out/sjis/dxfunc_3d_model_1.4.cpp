#include "DxLib.h"

int main()
{
    int ModelHandle, AttachIndex1, AttachIndex2 ;
    float Rate ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // 画面が切り替わるのをちょっと待つ
    WaitTimer( 1000 ) ;

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // 画面に映る位置に３Ｄモデルを移動
    MV1SetPosition( ModelHandle, VGet( 320.0f, -300.0f, 600.0f ) ) ;

    // ３Ｄモデルの立っているアニメーション( ４番目のアニメーション )をアタッチする
    AttachIndex1 = MV1AttachAnim( ModelHandle, 4, -1, FALSE ) ;

    // ３Ｄモデルの手を前に出しているアニメーション( ５番目のアニメーション )をアタッチする
    AttachIndex2 = MV1AttachAnim( ModelHandle, 5, -1, FALSE ) ;

    // 描画先を裏画面に変更
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // ４番目のアニメーションから５番目のアニメーションに徐々に移行する
    for( Rate = 0.0f ; Rate < 1.0f ; Rate += 0.01f )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // 立っているアニメーションのブレンド率をセット
        MV1SetAttachAnimBlendRate( ModelHandle, AttachIndex1, 1.0f - Rate ) ;

        // 手を前に出しているアニメーションのブレンド率をセット
        MV1SetAttachAnimBlendRate( ModelHandle, AttachIndex2, Rate ) ;

        // モデルの描画
        MV1DrawModel( ModelHandle ) ;

        // 裏画面の内容を表画面に反映する
        ScreenFlip() ;
    }

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
