#include "DxLib.h"

int main()
{
    float xadd, length ;
    VECTOR LineA1, LineA2, LineB1, LineB2 ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // 描画先を裏画面にする
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // 二線分の座標をセット
    LineA1 = VGet( 0.0f, 0.0f, 0.0f ) ;
    LineA2 = VGet( 0.0f, 200.0f, 0.0f ) ;
    LineB1 = VGet( 320.0f, 480.0f, 0.0f ) ;
    LineB2 = VGet( 320.0f, 240.0f, 0.0f ) ;

    // 座標と加算数の初期化
    xadd = 8.0f ;

    // ウインドウが閉じられるか何かキーが押されるまでループ
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // 線分の片方の終点を移動
        LineA2.x += xadd ;
        if( LineA2.x < 0.0f || LineA2.x > 640.0f )
            xadd = -xadd ;

        // 二線分の最近点どうしの距離を求める
        length = Segment_Segment_MinLength( LineA1, LineA2, LineB1, LineB2 ) ;

        // 片方の線分の描画
        DrawLine( LineB1.x, LineB1.y, LineB2.x, LineB2.y, GetColor( 255,255,255 ) ) ;

        // もう一つの線分を距離が 64 以下だったら色を変えて描画
        if( length < 64.0f )
        {
            DrawLine( LineA1.x, LineA1.y, LineA2.x, LineA2.y, GetColor( 255,0,0 ) ) ;
        }
        else
        {
            DrawLine( LineA1.x, LineA1.y, LineA2.x, LineA2.y, GetColor( 0,255,0 ) ) ;
        }

        // 裏画面の内容を表画面に反映させる
        ScreenFlip() ;
    }

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
