#include "DxLib.h"

int main()
{
    int ModelHandle[ 4 ] ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // ３Ｄモデルの読み込み
    ModelHandle[ 0 ] = MV1LoadModel( "DxChara.x" ) ;

    // 同じデータを使用するモデルハンドルを３つ作成する
    ModelHandle[ 1 ] = MV1DuplicateModel( ModelHandle[ 0 ] ) ;
    ModelHandle[ 2 ] = MV1DuplicateModel( ModelHandle[ 0 ] ) ;
    ModelHandle[ 3 ] = MV1DuplicateModel( ModelHandle[ 0 ] ) ;

    // 画面に映る位置に３Ｄモデルを移動
    MV1SetPosition( ModelHandle[ 0 ], VGet( -200.0f, -300.0f, 600.0f ) ) ;
    MV1SetPosition( ModelHandle[ 1 ], VGet(  150.0f, -300.0f, 600.0f ) ) ;
    MV1SetPosition( ModelHandle[ 2 ], VGet(  500.0f, -300.0f, 600.0f ) ) ;
    MV1SetPosition( ModelHandle[ 3 ], VGet(  850.0f, -300.0f, 600.0f ) ) ;

    // ３Ｄモデルの描画
    MV1DrawModel( ModelHandle[ 0 ] ) ;
    MV1DrawModel( ModelHandle[ 1 ] ) ;
    MV1DrawModel( ModelHandle[ 2 ] ) ;
    MV1DrawModel( ModelHandle[ 3 ] ) ;

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle[ 0 ] ) ;
    MV1DeleteModel( ModelHandle[ 1 ] ) ;
    MV1DeleteModel( ModelHandle[ 2 ] ) ;
    MV1DeleteModel( ModelHandle[ 3 ] ) ;

    // キーの入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
