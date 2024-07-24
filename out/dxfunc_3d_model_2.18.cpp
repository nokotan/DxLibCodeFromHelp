#include "DxLib.h"

int main()
{
    int ModelHandle, MeshNum, i, MeshIndex ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // １番目のフレームに含まれるメッシュの数を取得する
    MeshNum = MV1GetFrameMeshNum( ModelHandle, 1 ) ;

    // メッシュの数だけループ
    for( i = 0 ; i < MeshNum ; i ++ )
    {
        // メッシュ番号の取得
        MeshIndex = MV1GetFrameMesh( ModelHandle, 1, i ) ;

        // メッシュが使用しているマテリアルとメッシュに含まれる三角形ポリゴンの数を描画
        DrawFormatString( 0, i * 16, GetColor( 255,255,255 ), "Mesh No  %d   Material  %d    Triangle Polygon Num  %d",
            i, MV1GetMeshMaterial( ModelHandle, MeshIndex ), MV1GetMeshTriangleNum( ModelHandle, MeshIndex ) ) ;
    }

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // キーの入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
