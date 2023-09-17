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

    // フォグの色を黒色にする
    SetFogColor( 0, 0, 0 ) ;

    // フォグの開始距離を０、終了距離を１５００にする
    SetFogStartEnd( 0.0f, 1500.0f ) ;

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // ３Ｄモデルを徐々に画面から離しながら４体描画する
    for( i = 0 ; i < 4 ; i ++ )
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
