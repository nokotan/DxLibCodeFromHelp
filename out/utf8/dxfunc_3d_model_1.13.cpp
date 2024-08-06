#include "DxLib.h"

int main()
{
    int ModelHandle ;
    int TexIndex ;
    int GrHandle ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // マテリアル番号４で使用されているテクスチャの番号を取得する
    TexIndex = MV1GetMaterialDifMapTexture( ModelHandle, 4 ) ;

    // モデルで使用されているテクスチャのグラフィックハンドルを取得する
    GrHandle = MV1GetTextureGraphHandle( ModelHandle, TexIndex ) ;

    // 取得したグラフィックハンドルを画面に描画する
    DrawGraph( 0, 0, GrHandle, TRUE ) ;

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // キーの入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
