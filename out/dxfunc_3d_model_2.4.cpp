#include "DxLib.h"

int main()
{
    int ModelHandle, FrameNum, i, Parent ;
    VECTOR Position ;
    MATRIX Matrix ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // フレームの数を取得する
    FrameNum = MV1GetFrameNum( ModelHandle ) ;

    // フレームの数だけループ
    for( i = 0 ; i < FrameNum ; i ++ )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // フレーム名の描画
        DrawFormatString( 0, 0, GetColor( 255,255,255 ),      "Name         %s", MV1GetFrameName( ModelHandle, i ) ) ;

        // 親フレーム名の描画
        Parent = MV1GetFrameParent( ModelHandle, i ) ;
        if( Parent == -2 )
        {
            DrawFormatString( 0, 16, GetColor( 255,255,255 ), "Parent Name  None" ) ;
        }
        else
        {
            DrawFormatString( 0, 16, GetColor( 255,255,255 ), "Parent Name  %s", MV1GetFrameName( ModelHandle, Parent ) ) ;
        }

        // 子フレームの数を描画
        DrawFormatString( 0, 32, GetColor( 255,255,255 ),     "Child Num    %d", MV1GetFrameChildNum( ModelHandle, i ) ) ;

        // フレームのワールド座標の描画
        Position = MV1GetFramePosition( ModelHandle, i ) ;
        DrawFormatString( 0, 48, GetColor( 255,255,255 ),     "Position     x:%f y:%f z:%f", Position.x, Position.y, Position.z ) ;

        // 変換行列を描画する
        Matrix = MV1GetFrameLocalMatrix( ModelHandle, i ) ;
        DrawFormatString( 0, 64,  GetColor( 255,255,255 ),    "   Matrix    %f %f %f %f", Matrix.m[ 0 ][ 0 ], Matrix.m[ 0 ][ 1 ], Matrix.m[ 0 ][ 2 ], Matrix.m[ 0 ][ 3 ] ) ;
        DrawFormatString( 0, 80,  GetColor( 255,255,255 ),    "             %f %f %f %f", Matrix.m[ 1 ][ 0 ], Matrix.m[ 1 ][ 1 ], Matrix.m[ 1 ][ 2 ], Matrix.m[ 1 ][ 3 ] ) ;
        DrawFormatString( 0, 96,  GetColor( 255,255,255 ),    "             %f %f %f %f", Matrix.m[ 2 ][ 0 ], Matrix.m[ 2 ][ 1 ], Matrix.m[ 2 ][ 2 ], Matrix.m[ 2 ][ 3 ] ) ;
        DrawFormatString( 0, 112, GetColor( 255,255,255 ),    "             %f %f %f %f", Matrix.m[ 3 ][ 0 ], Matrix.m[ 3 ][ 1 ], Matrix.m[ 3 ][ 2 ], Matrix.m[ 3 ][ 3 ] ) ;

        // フレームのローカル座標からワールド座標に変換する行列を描画する
        Matrix = MV1GetFrameLocalWorldMatrix( ModelHandle, i ) ;
        DrawFormatString( 0, 128,  GetColor( 255,255,255 ),   "LW Matrix    %f %f %f %f", Matrix.m[ 0 ][ 0 ], Matrix.m[ 0 ][ 1 ], Matrix.m[ 0 ][ 2 ], Matrix.m[ 0 ][ 3 ] ) ;
        DrawFormatString( 0, 144,  GetColor( 255,255,255 ),   "             %f %f %f %f", Matrix.m[ 1 ][ 0 ], Matrix.m[ 1 ][ 1 ], Matrix.m[ 1 ][ 2 ], Matrix.m[ 1 ][ 3 ] ) ;
        DrawFormatString( 0, 160,  GetColor( 255,255,255 ),   "             %f %f %f %f", Matrix.m[ 2 ][ 0 ], Matrix.m[ 2 ][ 1 ], Matrix.m[ 2 ][ 2 ], Matrix.m[ 2 ][ 3 ] ) ;
        DrawFormatString( 0, 176, GetColor( 255,255,255 ),    "             %f %f %f %f", Matrix.m[ 3 ][ 0 ], Matrix.m[ 3 ][ 1 ], Matrix.m[ 3 ][ 2 ], Matrix.m[ 3 ][ 3 ] ) ;

        // フレームの表示状態を描画
        DrawFormatString( 0, 192, GetColor( 255,255,255 ),    "Visible      %d", MV1GetFrameVisible( ModelHandle, i ) ) ;

        // フレームに半透明要素があるかどうかを描画
        DrawFormatString( 0, 208, GetColor( 255,255,255 ),    "Semi Trans   %d", MV1GetFrameSemiTransState( ModelHandle, i ) ) ;

        // フレームに含まれるメッシュの数を描画
        DrawFormatString( 0, 224, GetColor( 255,255,255 ),    "Mesh Num     %d", MV1GetFrameMeshNum( ModelHandle, i ) ) ;

        // フレームに含まれる三角形ポリゴンの数を描画
        DrawFormatString( 0, 240, GetColor( 255,255,255 ),    "Triangle Num %d", MV1GetFrameTriangleNum( ModelHandle, i ) ) ;

        // キーの入力待ち
        WaitKey() ;
    }

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
