#include "DxLib.h"

int main()
{
    int ModelHandle ;
    int Add, y ;
    VECTOR StartPos, EndPos ;
    MV1_COLL_RESULT_POLY HitPoly ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;

    // ３Ｄモデルを見える位置に移動する
    MV1SetPosition( ModelHandle, VGet( 320.0f, 300.0f, 600.0f ) ) ;

    // 描画先を裏画面に変更
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // モデル全体のコリジョン情報を構築
    MV1SetupCollInfo( ModelHandle, -1, 8, 8, 8 ) ;

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

        // ３Ｄモデルの描画
        MV1DrawModel( ModelHandle ) ;

        // モデルと線分との当たり判定
        StartPos = VGet( -300.0f, y, 600.0f ) ;
        EndPos   = VGet( 1000.0f, y, 600.0f ) ;
        HitPoly = MV1CollCheck_Line( ModelHandle, -1, StartPos, EndPos ) ;

        // 当たった場合はその位置を描画する線分の終点とする
        if( HitPoly.HitFlag == 1 )
        {
            EndPos = HitPoly.HitPosition ;
        }

        // 線分の描画
        DrawLine3D( StartPos, EndPos, GetColor( 255,255,0 ) ) ;

        // 当たったかどうかで処理を分岐
        if( HitPoly.HitFlag == 1 )
        {
            // 当たった場合は衝突の情報を描画する

            // 交差した座標を描画
            DrawFormatString( 0, 0, GetColor( 255,255,255 ),  "Hit Pos   %f  %f  %f",
                HitPoly.HitPosition.x, HitPoly.HitPosition.y, HitPoly.HitPosition.z ) ;

            // 当たったポリゴンが含まれるフレームの番号を描画
            DrawFormatString( 0, 16, GetColor( 255,255,255 ), "Frame     %d", HitPoly.FrameIndex ) ;

            // 当たったポリゴンが使用しているマテリアルの番号を描画
            DrawFormatString( 0, 32, GetColor( 255,255,255 ), "Material  %d", HitPoly.MaterialIndex ) ;

            // 当たったポリゴンを形成する三頂点の座標を描画
            DrawFormatString( 0, 48, GetColor( 255,255,255 ), "Position  %f  %f  %f",
                HitPoly.Position[ 0 ].x, HitPoly.Position[ 0 ].y, HitPoly.Position[ 0 ].z ) ;
            DrawFormatString( 0, 64, GetColor( 255,255,255 ), "          %f  %f  %f",
                HitPoly.Position[ 1 ].x, HitPoly.Position[ 1 ].y, HitPoly.Position[ 1 ].z ) ;
            DrawFormatString( 0, 80, GetColor( 255,255,255 ), "          %f  %f  %f",
                HitPoly.Position[ 2 ].x, HitPoly.Position[ 2 ].y, HitPoly.Position[ 2 ].z ) ;

            // 当たったポリゴンの法線を描画
            DrawFormatString( 0, 96, GetColor( 255,255,255 ), "Normal    %f  %f  %f",
                HitPoly.Normal.x, HitPoly.Normal.y, HitPoly.Normal.z ) ;
        }
        else
        {
            // 当たらなかった場合は衝突しなかった旨だけ描画する
            DrawString( 0, 0, "NO HIT", GetColor( 255,255,255 ) ) ;
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
