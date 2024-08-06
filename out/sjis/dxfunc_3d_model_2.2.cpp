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
    ModelHandle = MV1LoadModel( "AddressTest.mqo" ) ;

    // モデルを画面に映る位置に移動
    MV1SetPosition( ModelHandle, VGet( 320.0f, 240.0f, 400.0f ) ) ;

    // テクスチャ０番のアドレスモードを横方向は DX_TEXADDRESS_MIRROR に、
    // 縦方向は DX_TEXADDRESS_CLAMP に変更する
    MV1SetTextureAddressMode( ModelHandle, 0, DX_TEXADDRESS_MIRROR, DX_TEXADDRESS_CLAMP ) ;

    // モデルを描画する
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
