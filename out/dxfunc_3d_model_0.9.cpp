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

    // 画面に映る位置に３Ｄモデルを移動
    MV1SetPosition( ModelHandle, VGet( 320.0f, 0.0f, 600.0f ) ) ;

    // ３ＤモデルのＺ軸を画面左上方向に向ける
    // ( DxChara.x はＺ軸のマイナス方向に向いているので右下方向に傾きます )
    MV1SetRotationZYAxis( ModelHandle, VGet( -0.5f, 0.5f, 0.0f ), VGet( 0.5f, 0.5f, 0.0f ), 0.0f ) ;

    // ３Ｄモデルを描画
    MV1DrawModel( ModelHandle ) ;

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // キーの入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
