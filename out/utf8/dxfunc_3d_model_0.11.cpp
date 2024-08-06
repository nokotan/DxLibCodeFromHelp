#include "DxLib.h"

int main()
{
    int ModelHandle, SubModelHandle ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // ModelHandle と同じモデルを使用するモデルの作成
    SubModelHandle = MV1DuplicateModel( ModelHandle ) ;

    // 画面に映る位置に３Ｄモデルを移動
    MV1SetPosition( ModelHandle, VGet( 320.0f, 0.0f, 600.0f ) ) ;

    // ３Ｄモデルの拡大率を０．５倍にする
    MV1SetScale( ModelHandle, VGet( 0.5f, 0.5f, 0.5f ) ) ;

    // ModelHandle に設定した座標変換パラメータの結果の行列を SubModelHandle の座標変換行列として設定する
    MV1SetMatrix( SubModelHandle, MV1GetMatrix( ModelHandle ) ) ;

    // SubModelHandle の方の３Ｄモデルを描画
    MV1DrawModel( SubModelHandle ) ;

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;
    MV1DeleteModel( SubModelHandle ) ;

    // キーの入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
