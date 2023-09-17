#include "DxLib.h"

// カプセルの高さ
#define CAPSULE_H        64.0f

int main()
{
    int ModelHandle ;
    int Add, y, i ;
    VECTOR CapsulePos1, CapsulePos2 ;
    MV1_COLL_RESULT_POLY_DIM HitPolyDim ;

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

        // 当たり判定を行う球の位置をセット
        CapsulePos1 = VGet( 250.0f, y, 600.0f ) ;
        CapsulePos2 = VGet( 250.0f, y + CAPSULE_H, 600.0f ) ;

        // モデルとカプセルとの当たり判定
        HitPolyDim = MV1CollCheck_Capsule( ModelHandle, -1, CapsulePos1, CapsulePos2,  100.0f ) ;

        // カプセルの描画
        DrawCapsule3D( CapsulePos1, CapsulePos2, 100.0f, 8, GetColor( 255,255,0 ), GetColor( 255,255,255 ), FALSE ) ;

        // 当たったかどうかで処理を分岐
        if( HitPolyDim.HitNum >= 1 )
        {
            // 当たった場合は衝突の情報を描画する

            // 当たったポリゴンの数を描画
            DrawFormatString( 0, 0, GetColor( 255,255,255 ), "Hit Poly Num   %d", HitPolyDim.HitNum ) ;

            // 当たったポリゴンの数だけ繰り返し
            for( i = 0 ; i < HitPolyDim.HitNum ; i ++ )
            {
                // 当たったポリゴンを描画
                DrawTriangle3D(
                    HitPolyDim.Dim[ i ].Position[ 0 ], 
                    HitPolyDim.Dim[ i ].Position[ 1 ], 
                    HitPolyDim.Dim[ i ].Position[ 2 ], GetColor( 0,255,255 ), TRUE ) ;
            }
        }

        // 当たり判定情報の後始末
        MV1CollResultPolyDimTerminate( HitPolyDim ) ;

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
