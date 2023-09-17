#include "DxLib.h"

int main()
{
    int LightHandle, ModelHandle ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;

    // ライトハンドルのライトの効果がわかり易いように標準ライトを無効化
    SetLightEnable( FALSE ) ;

    // ディレクショナルタイプのライトハンドルを作成
    LightHandle = CreateDirLightHandle( VGet( 1.0f, -1.0f, 1.0f ) ) ;

    // ライトハンドルのアンビエントカラーを暗い緑色にする
    SetLightAmbColorHandle( LightHandle, GetColorF( 0.0f, 0.2f, 0.0f, 0.0f ) ) ;

    // 画面に映る位置に３Ｄモデルを移動
    MV1SetPosition( ModelHandle, VGet( 320.0f, 240.0f, 600.0f ) ) ;

    // ３Ｄモデルの描画
    MV1DrawModel( ModelHandle ) ;

    // ライトハンドルの削除
    DeleteLightHandle( LightHandle ) ;

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
