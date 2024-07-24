#include "DxLib.h"

int main()
{
    float yadd, length ;
    VECTOR Line1, Line2, Point ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // 描画先を裏画面にする
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // 線分の座標と点の座標をセット
    Line1 = VGet( 0.0f, 0.0f, 0.0f ) ;
    Line2 = VGet( 640.0f, 480.0f, 0.0f ) ;
    Point = VGet( 320.0f, 0.0f, 0.0f ) ;

    // 座標と加算数の初期化
    yadd = 4.0f ;

    // ウインドウが閉じられるか何かキーが押されるまでループ
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // 点の座標を移動
        Point.y += yadd ;
        if( Point.y < 0.0f || Point.y > 480.0f )
            yadd = -yadd ;

        // 線分と点が最も近づく座標間の距離を求める
        length = Segment_Point_MinLength( Line1, Line2, Point ) ;

        // 点の描画
        DrawPixel( Point.x, Point.y, GetColor( 255,255,255 ) ) ;

        // 点との距離が 64 以下だったら色を変えて描画
        if( length < 64.0f )
        {
            DrawLine( Line1.x, Line1.y, Line2.x, Line2.y, GetColor( 255,0,0 ) ) ;
        }
        else
        {
            DrawLine( Line1.x, Line1.y, Line2.x, Line2.y, GetColor( 0,255,0 ) ) ;
        }

        // 裏画面の内容を表画面に反映させる
        ScreenFlip() ;
    }

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
