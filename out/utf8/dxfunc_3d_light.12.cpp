#include "DxLib.h"

int main()
{
    int ModelHandle, LightHandle ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // モデルの読み込み
    ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;

    // 効果がわかり易いように標準ライトを無効化
    SetLightEnable( FALSE ) ;

    // Ｘ軸にマイナス方向のディレクショナルタイプのライトの作成
    LightHandle = CreateDirLightHandle( VGet( -1.0f, 0.0f, 0.0f ) ) ;

    // モデルをカメラの映る位置に移動
    MV1SetPosition( ModelHandle, VGet( 320.0f, 240.0f, 600.0f ) ) ;

    // モデルを描画
    MV1DrawModel( ModelHandle ) ;

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // ライトハンドルの削除
    DeleteLightHandle( LightHandle ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
