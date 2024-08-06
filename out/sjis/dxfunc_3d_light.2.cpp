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

    // Ｘ軸のマイナス方向のディレクショナルライトに変更
    ChangeLightTypeDir( VGet( -1.0f, 0.0f, 0.0f  ) ) ;

    // モデルをカメラの映る位置に移動
    MV1SetPosition( ModelHandle, VGet( 320.0f, 240.0f, 0.0f ) ) ;

    // モデルを描画
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
