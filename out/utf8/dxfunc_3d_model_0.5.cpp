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

    // ３Ｄモデルの０番目のメッシュを描画
    MV1DrawMesh( ModelHandle, 0 ) ;

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // キーの入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
