#include "DxLib.h"

int main()
{
    int ModelHandle, TriangleListNum, i, TriangleListIndex ;
    int y ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // １番目のメッシュに含まれるトライアングルリストの数を取得する
    TriangleListNum = MV1GetMeshTListNum( ModelHandle, 1 ) ;

    // トライアングルリストの数だけループ
    y = 0 ;
    for( i = 0 ; i < TriangleListNum ; i ++ )
    {
        // トライアングルリスト番号の取得
        TriangleListIndex = MV1GetMeshTList( ModelHandle, 1, i ) ;

        // トライアングルリスト番号を描画
        DrawFormatString( 0, y, GetColor( 255,255,255 ), "TriangleListIndex %d", TriangleListIndex ) ;

        // トライアングルリストの頂点タイプを描画
        switch( MV1GetTriangleListVertexType( ModelHandle, TriangleListIndex ) )
        {
        case DX_MV1_VERTEX_TYPE_1FRAME :
            DrawString( 0, y + 16, "頂点タイプ：１フレームの影響を受ける頂点", GetColor( 255,255,255 ) ) ;
            break ;

        case DX_MV1_VERTEX_TYPE_4FRAME :
            DrawString( 0, y + 16, "頂点タイプ：１～４フレームの影響を受ける頂点", GetColor( 255,255,255 ) ) ;
            break ;

        case DX_MV1_VERTEX_TYPE_8FRAME :
            DrawString( 0, y + 16, "頂点タイプ：１～８フレームの影響を受ける頂点", GetColor( 255,255,255 ) ) ;
            break ;

        case DX_MV1_VERTEX_TYPE_FREE_FRAME :
            DrawString( 0, y + 16, "頂点タイプ：９フレーム以上の影響を受ける頂点", GetColor( 255,255,255 ) ) ;
            break ;

        case DX_MV1_VERTEX_TYPE_NMAP_1FRAME :
            DrawString( 0, y + 16, "頂点タイプ：法線マップ用の情報が含まれる１フレームの影響を受ける頂点", GetColor( 255,255,255 ) ) ;
            break ;

        case DX_MV1_VERTEX_TYPE_NMAP_4FRAME :
            DrawString( 0, y + 16, "頂点タイプ：法線マップ用の情報が含まれる１～４フレームの影響を受ける頂点", GetColor( 255,255,255 ) ) ;
            break ;

        case DX_MV1_VERTEX_TYPE_NMAP_8FRAME :
            DrawString( 0, y + 16, "頂点タイプ：法線マップ用の情報が含まれる１～８フレームの影響を受ける頂点", GetColor( 255,255,255 ) ) ;
            break ;

        case DX_MV1_VERTEX_TYPE_NMAP_FREE_FRAME :
            DrawString( 0, y + 16, "頂点タイプ：法線マップ用の情報が含まれる９フレーム以上の影響を受ける頂点", GetColor( 255,255,255 ) ) ;
            break ;
        }

        // トライアングルリストのポリゴン数と頂点数を描画
        DrawFormatString( 0, y + 32, GetColor( 255,255,255 ), "ポリゴン数：%-5d   頂点数：%-5d",
            MV1GetTriangleListPolygonNum( ModelHandle, TriangleListIndex ),
            MV1GetTriangleListVertexNum( ModelHandle, TriangleListIndex ) ) ;

        // 描画Ｙ座標を進める
        y += 64 ;
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
