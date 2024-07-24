#include "DxLib.h"

int main()
{
    int ModelHandle ;
    int Add, y, i ;
    MV1_REF_POLYGONLIST RefPoly ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;

    // 描画先を裏画面に変更
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // ０番目のフレームの参照用メッシュを構築
    MV1SetupReferenceMesh( ModelHandle, 0, TRUE ) ;

    // モデルの進行方向をセット
    Add = 8 ;

    // モデルの移動位置をセット
    y = 0 ;

    // ウインドウが閉じられるか何かキーが押されるまでループ
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // ３Ｄモデルの移動位置を上下に移動させる
        y += Add ;
        if( y < 0 || y > 600 )
            Add = -Add ;

        // ３Ｄモデルを移動する
        MV1SetPosition( ModelHandle, VGet( 320.0f, y, 600.0f ) ) ;

        // ０番目のフレームの参照用メッシュを更新する
        MV1RefreshReferenceMesh( ModelHandle, 0, TRUE ) ;

        // ０番目のフレームの参照用メッシュの取得
        RefPoly = MV1GetReferenceMesh( ModelHandle, 0, TRUE ) ;

        // ポリゴンの数だけ繰り返し
        for( i = 0 ; i < RefPoly.PolygonNum ; i ++ )
        {
            // ポリゴンを形成する三頂点を使用してワイヤーフレームを描画する
            DrawLine3D(
                RefPoly.Vertexs[ RefPoly.Polygons[ i ].VIndex[ 0 ] ].Position,
                RefPoly.Vertexs[ RefPoly.Polygons[ i ].VIndex[ 1 ] ].Position,
                GetColor( 255,255,0 ) ) ;

            DrawLine3D(
                RefPoly.Vertexs[ RefPoly.Polygons[ i ].VIndex[ 1 ] ].Position,
                RefPoly.Vertexs[ RefPoly.Polygons[ i ].VIndex[ 2 ] ].Position,
                GetColor( 255,255,0 ) ) ;

            DrawLine3D(
                RefPoly.Vertexs[ RefPoly.Polygons[ i ].VIndex[ 2 ] ].Position,
                RefPoly.Vertexs[ RefPoly.Polygons[ i ].VIndex[ 0 ] ].Position,
                GetColor( 255,255,0 ) ) ;
        }

        // 裏画面の内容を表画面に反映
        ScreenFlip() ;
    }

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
