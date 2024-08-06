#include "DxLib.h"

int main()
{
    int ModelHandle, i ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // フォグを有効にする
    SetFogEnable( TRUE ) ;

    // フォグの色を黄色にする
    SetFogColor( 255, 255, 0 ) ;

    // フォグの開始距離を１０００、終了距離を３５００にする
    SetFogStartEnd( 1000.0f, 3500.0f ) ;

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // 画面を黄色で塗りつぶす
    DrawBox( 0, 0, 640, 480, GetColor( 255, 255, 0 ), TRUE ) ;

    // ３Ｄモデルを画面から徐々に離しながら８体描画する
    for( i = 0 ; i < 8 ; i ++ )
    {
        // モデルの座標をセット
        MV1SetPosition( ModelHandle, VGet( 700.0f, -300.0f, 200.0f + i * 400.0f ) ) ;
        
        // モデルを描画
        MV1DrawModel( ModelHandle ) ;
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
