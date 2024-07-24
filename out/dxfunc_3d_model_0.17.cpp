#include "DxLib.h"

int main()
{
    int ModelHandle ;
    float OpacityRate ;

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

    // 不透明度を初期化
    OpacityRate = 1.0f ;

    // ESCキーが押されるかウインドウが閉じられるまでループ
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // 画面のクリア
        ClearDrawScreen() ;

        // 上キーが押されたら不透明度を上げる
        if( CheckHitKey( KEY_INPUT_UP ) )
        {
            OpacityRate += 0.05f ;
            if( OpacityRate > 1.0f )
            {
                OpacityRate = 1.0f ;
            }
        }

        // 下キーが押されたら不透明度を下げる
        if( CheckHitKey( KEY_INPUT_DOWN ) )
        {
            OpacityRate -= 0.05f ;
            if( OpacityRate < 0.0f )
            {
                OpacityRate = 0.0f ;
            }
        }

        // ３Ｄモデルの不透明度を設定する
        MV1SetOpacityRate( ModelHandle, OpacityRate ) ;

        // ３Ｄモデルの描画
        MV1DrawModel( ModelHandle ) ;

        // 現在の不透明度と、MV1GetSemiTransState の戻り値を描画する
        DrawFormatString( 0, 0, GetColor( 255,255,255 ),
            "ESC Key:Exit OpacityRate:%f SemiTransState:%d",
            OpacityRate, MV1GetSemiTransState( ModelHandle ) ) ;

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
