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

    // ブレンドモードが変更されたことがわかるように画面全体を青色で塗りつぶす
    DrawBox( 0, 0, 640, 480, GetColor( 0,0,255 ), TRUE ) ;

    // 画面に映る位置に３Ｄモデルを移動
    MV1SetPosition( ModelHandle, VGet( 320.0f, -300.0f, 600.0f ) ) ;

    // ３Ｄモデルに含まれる１番目のメッシュの描画ブレンドモードを DX_BLENDMODE_ADD に変更する
    MV1SetMeshDrawBlendMode( ModelHandle, 1, DX_BLENDMODE_ADD ) ;

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
