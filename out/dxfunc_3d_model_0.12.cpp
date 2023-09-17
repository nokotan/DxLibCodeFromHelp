#include "DxLib.h"

int main()
{
    int ModelHandle ;

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

    // 何かキーが押されるかウインドウが閉じられるまでループする
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // 画面をクリアする
        ClearDrawScreen() ;

        // ３Ｄモデルをカウンタが奇数秒の時は描画して、偶数表のときは描画しないようにする
        if( GetNowCount() % 2000 < 1000 )
        {
            MV1SetVisible( ModelHandle, TRUE ) ;
        }
        else
        {
            MV1SetVisible( ModelHandle, FALSE ) ;
        }

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
