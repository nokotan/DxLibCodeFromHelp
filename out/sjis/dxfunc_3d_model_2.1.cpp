#include "DxLib.h"

int main()
{
    int ModelHandle ;
    int GrHandle ;
    int TexIndex ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // 緑色の目の画像の読みこみ
    GrHandle = LoadGraph( "DxCharaEye2.tga" ) ;

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // モデルを画面に映る位置に移動
    MV1SetPosition( ModelHandle, VGet( 320.0f, -300.0f, 400.0f ) ) ;

    // 目の部分のマテリアルで使用されているテクスチャの番号を取得
    TexIndex = MV1GetMaterialDifMapTexture( ModelHandle, 4 ) ;

    // テクスチャで使用するグラフィックハンドルを変更する
    MV1SetTextureGraphHandle( ModelHandle, TexIndex, GrHandle, FALSE ) ;

    // モデルを描画する
    MV1DrawModel( ModelHandle ) ;

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // 読み込んだ画像のグラフィックハンドルを削除
    DeleteGraph( GrHandle ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
