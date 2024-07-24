#include "DxLib.h"

int main()
{
    int ModelHandle, Time, UseMatrix ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // モデルの読み込み
    ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;

    // モデルを見える位置に移動
    MV1SetPosition( ModelHandle, VGet( 320.0f, 240.0f, 800.0f ) ) ;

    // 行列を使用するかどうかのフラグを１にする
    UseMatrix = 1 ;

    // 現在のタイムカウントを記録しておく
    Time = GetNowCount() ;

    // 何かキーが押されるまでループ
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // １秒経つ毎に独自の行列を使用するかどうかを変更する
        if( GetNowCount() - Time > 1000 )
        {
            // フラグによって処理を分岐
            if( UseMatrix == 1 )
            {
                // ２番目のフレームに下に動くのローカル行列をセットする
                MV1SetFrameUserLocalMatrix( ModelHandle, 2, MGetTranslate( VGet( 0.0f, -300.0f, 0.0f ) ) ) ;

                // フラグを０にする
                UseMatrix = 0 ;
            }
            else
            {
                // ２番目のフレームに設定した行列を無効化する
                MV1ResetFrameUserLocalMatrix( ModelHandle, 2 ) ;

                // フラグを１にする
                UseMatrix = 1 ;
            }

            // 現在のタイムカウントを記録しておく
            Time = GetNowCount() ;
        }

        // モデルを描画
        MV1DrawModel( ModelHandle ) ;
    }

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
