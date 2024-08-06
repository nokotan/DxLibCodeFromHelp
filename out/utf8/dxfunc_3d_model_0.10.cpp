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

    // ２倍に拡大した後画面に映る位置に３Ｄモデルを移動する行列のセット
    MV1SetMatrix( ModelHandle, MMult( MGetScale( VGet( 2.0f, 2.0f, 2.0f ) ), MGetTranslate( VGet( 320.0f, -600.0f, 600.0f ) ) ) ) ;

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
