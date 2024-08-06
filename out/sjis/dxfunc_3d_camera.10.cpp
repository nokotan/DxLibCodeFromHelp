#include "DxLib.h"

#define X1    100.0f
#define X2    540.0f
#define Y1    100.0f
#define Y2    380.0f
#define Z1    0.0f
#define Z2    1000.0f

int main()
{
    unsigned int Color ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // 描画先を裏画面にする
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // カメラの注視点の画面上の位置を右寄りにする
    SetCameraScreenCenter( 480.0f, 240.0f ) ;

    // 直方体を描画する
    Color = GetColor( 255,255,255 ) ;
    DrawLine3D( VGet( X1, Y1, Z1 ), VGet( X2, Y1, Z1 ), Color ) ;
    DrawLine3D( VGet( X2, Y1, Z1 ), VGet( X2, Y2, Z1 ), Color ) ;
    DrawLine3D( VGet( X2, Y2, Z1 ), VGet( X1, Y2, Z1 ), Color ) ;
    DrawLine3D( VGet( X1, Y2, Z1 ), VGet( X1, Y1, Z1 ), Color ) ;
    DrawLine3D( VGet( X1, Y1, Z2 ), VGet( X2, Y1, Z2 ), Color ) ;
    DrawLine3D( VGet( X2, Y1, Z2 ), VGet( X2, Y2, Z2 ), Color ) ;
    DrawLine3D( VGet( X2, Y2, Z2 ), VGet( X1, Y2, Z2 ), Color ) ;
    DrawLine3D( VGet( X1, Y2, Z2 ), VGet( X1, Y1, Z2 ), Color ) ;
    DrawLine3D( VGet( X1, Y1, Z1 ), VGet( X1, Y1, Z2 ), Color ) ;
    DrawLine3D( VGet( X2, Y1, Z1 ), VGet( X2, Y1, Z2 ), Color ) ;
    DrawLine3D( VGet( X2, Y2, Z1 ), VGet( X2, Y2, Z2 ), Color ) ;
    DrawLine3D( VGet( X1, Y2, Z1 ), VGet( X1, Y2, Z2 ), Color ) ;

    // 裏画面の内容を表画面に反映
    ScreenFlip() ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
