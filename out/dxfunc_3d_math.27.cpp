#include "DxLib.h"

int main()
{
    float xadd, length ;
    VECTOR Line1, Line2, Tri1, Tri2, Tri3 ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // 描画先を裏画面にする
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // 線分の座標と三角形を形成する３頂点の座標をセット
    Line1 = VGet( 0.0f, 0.0f, 0.0f ) ;
    Line2 = VGet( 0.0f, 400.0f, 0.0f ) ;
    Tri1 = VGet( 320.0f, 200.0f, 0.0f ) ;
    Tri2 = VGet( 280.0f, 260.0f, 0.0f ) ;
    Tri3 = VGet( 360.0f, 260.0f, 0.0f ) ;

    // 座標と加算数の初期化
    xadd = 8.0f ;

    // ウインドウが閉じられるか何かキーが押されるまでループ
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // 線分の終点を移動
        Line2.x += xadd ;
        if( Line2.x < 0.0f || Line2.x > 640.0f )
            xadd = -xadd ;

        // 線分と三角形の最近点間の距離を求める
        length = Segment_Triangle_MinLength( Line1, Line2, Tri1, Tri2, Tri3 ) ;

        // 線分の描画
        DrawLine( Line1.x, Line1.y, Line2.x, Line2.y, GetColor( 255,255,255 ) ) ;

        // 三角形との距離が 64 以下だったら色を変えて描画
        if( length < 64.0f )
        {
            DrawTriangle( Tri1.x, Tri1.y, Tri2.x, Tri2.y, Tri3.x, Tri3.y,  GetColor( 255,0,0 ), TRUE ) ;
        }
        else
        {
            DrawTriangle( Tri1.x, Tri1.y, Tri2.x, Tri2.y, Tri3.x, Tri3.y,  GetColor( 0,255,0 ), TRUE ) ;
        }

        // 裏画面の内容を表画面に反映させる
        ScreenFlip() ;
    }

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
