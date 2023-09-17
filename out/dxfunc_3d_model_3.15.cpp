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

    // 描画先を裏画面に変更
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // モデルの０番目のフレームのコリジョン情報を構築
    MV1SetupCollInfo( ModelHandle, 0, 8, 8, 8 ) ;

    // モデルの進行方向をセット
    Add = 8 ;

    // モデルの移動位置をセット
    y = 0 ;

    // ウインドウが閉じられるかＥＳＣキーが押されるまでループ
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // ３Ｄモデルの移動位置を上下に移動させる
        y += Add ;
        if( y < -300 || y > 300 )
            Add = -Add ;

        // ３Ｄモデルの位置を変更する
        MV1SetPosition( ModelHandle, VGet( 320.0f, 300.0f + y, 600.0f ) ) ;

        // ０番目のフレームのコリジョン情報を更新する
        MV1RefreshCollInfo( ModelHandle, 0 ) ;

        // ３Ｄモデルの描画
        MV1DrawModel( ModelHandle ) ;

        // ０番のフレームと線分との当たり判定
        StartPos = VGet(    0.0f, 300.0f, 600.0f ) ;
        EndPos   = VGet( 1000.0f, 300.0f, 600.0f ) ;
        HitPoly = MV1CollCheck_Line( ModelHandle, 0, StartPos, EndPos ) ;

        // 当たった場合はその位置を描画する線分の終点とする
        if( HitPoly.HitFlag == 1 )
        {
            EndPos = HitPoly.HitPosition ;
        }

        // 線分の描画
        DrawLine3D( StartPos, EndPos, GetColor( 255,255,0 ) ) ;

        // 当たったかどうかを表示する
        DrawFormatString( 0, 0, GetColor( 255,255,255 ), "HIT:%d", HitPoly.HitFlag ) ;

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
