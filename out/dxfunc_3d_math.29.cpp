#include "DxLib.h"

int main()
{
    float yadd ;
    HITRESULT_LINE Result ;
    VECTOR Line1, Line2, Tri1, Tri2, Tri3 ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // 描画先を裏画面にする
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // 線分の座標と三角形の座標をセット
    Line1 = VGet( 0.0f, 240.0f, 0.0f ) ;
    Line2 = VGet( 640.0f, 240.0f, 0.0f ) ;
    Tri1 = VGet( 320.0f, 128.0f, 0.0f ) ;
    Tri2 = VGet( 320.0f, 240.0f, 200.0f ) ;
    Tri3 = VGet( 320.0f, 240.0f, -200.0f ) ;

    // 座標と加算数の初期化
    yadd = 4.0f ;

    // ウインドウが閉じられるか何かキーが押されるまでループ
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // 線の終点座標を移動
        Line2.y += yadd ;
        if( Line2.y < 0.0f || Line2.y > 480.0f )
            yadd = -yadd ;

        // 線分と点が最も近づく座標間の距離を求める
        Result = HitCheck_Line_Triangle( Line1, Line2, Tri1, Tri2, Tri3 ) ;

        // 三角形を真横から見たときにできる線を描画
        DrawLine( Tri1.x, Tri1.y, Tri2.x, Tri2.y, GetColor( 255,255,255 ) ) ;

        // 三角形と接触していたら始点と接触点を結ぶ線を
        // そうでない場合は始点と終点を結ぶ線を描画する
        if( Result.HitFlag == 1 )
        {
            DrawLine( Line1.x, Line1.y, Result.Position.x, Result.Position.y, GetColor( 255,0,0 ) ) ;
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
