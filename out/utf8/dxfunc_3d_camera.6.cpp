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

    // モデルの読み込み
    ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;

    // カメラを正射影に変更
    SetupCamera_Ortho( 2000.0f ) ;

    // カメラの前方に奥行き座標の違うモデルを３個描画
    MV1SetPosition( ModelHandle, VGet( -700.0f + 320.0f, 240.0f, 0.0f ) ) ;
    MV1DrawModel( ModelHandle ) ;

    MV1SetPosition( ModelHandle, VGet(    0.0f + 320.0f, 240.0f, 500.0f ) ) ;
    MV1DrawModel( ModelHandle ) ;

    MV1SetPosition( ModelHandle, VGet(  700.0f + 320.0f, 240.0f, 1000.0f ) ) ;
    MV1DrawModel( ModelHandle ) ;

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
