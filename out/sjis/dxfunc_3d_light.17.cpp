#include "DxLib.h"

int main()
{
    int LightHandle[ 3 ], ModelHandle ;

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

    // ディレクショナルタイプのライトハンドルを３つ作成
    LightHandle[ 0 ] = CreateDirLightHandle( VGet( 1.0f, 0.0f, 0.0f ) ) ;
    LightHandle[ 1 ] = CreateDirLightHandle( VGet( 0.0f, 1.0f, 0.0f ) ) ;
    LightHandle[ 2 ] = CreateDirLightHandle( VGet( 0.0f, 0.0f, 1.0f ) ) ;

    // 各ライトを５０％の確率で無効にする
    if( GetRand( 99 ) >= 50 )
    {
        SetLightEnableHandle( LightHandle[ 0 ], FALSE ) ;
    }

    if( GetRand( 99 ) >= 50 )
    {
        SetLightEnableHandle( LightHandle[ 1 ], FALSE ) ;
    }

    if( GetRand( 99 ) >= 50 )
    {
        SetLightEnableHandle( LightHandle[ 2 ], FALSE ) ;
    }

    // 画面に映る位置に３Ｄモデルを移動
    MV1SetPosition( ModelHandle, VGet( 320.0f, 240.0f, 600.0f ) ) ;

    // ３Ｄモデルの描画
    MV1DrawModel( ModelHandle ) ;

    // ライトハンドルの削除
    DeleteLightHandle( LightHandle[ 0 ] ) ;
    DeleteLightHandle( LightHandle[ 1 ] ) ;
    DeleteLightHandle( LightHandle[ 2 ] ) ;

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
