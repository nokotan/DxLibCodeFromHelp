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
    MV1SetPosition( ModelHandle, VGet( 320.0f, -300.0f, 600.0f ) ) ;

    // ３Ｄモデルに含まれる０番目のマテリアルのスペキュラカラーを明るくします
    MV1SetMaterialSpcColor( ModelHandle, 0, GetColorF( 0.457f, 0.687f, 0.948f, 0.f ) ) ;

    // ３Ｄモデルに含まれる０番目のマテリアルのスペキュラの強さを 0.1f にします
    MV1SetMaterialSpcPower( ModelHandle, 0, 19.0f ) ;

    // ３Ｄモデルの描画
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
