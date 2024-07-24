#include "DxLib.h"

int main()
{
    int ModelHandle, i, ChildNum, FrameIndex ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // フレーム０番の子フレームの数を取得
    ChildNum = MV1GetFrameChildNum( ModelHandle, 0 ) ;

    // 子フレームの数だけループ
    for( i = 0 ; i < ChildNum ; i ++ )
    {
        // 子フレームのフレーム番号を取得
        FrameIndex = MV1GetFrameChild( ModelHandle, 0, i ) ;

        // 子フレームの名前を表示
        DrawFormatString( 0, i * 16, GetColor( 255,255,255 ), "%s", MV1GetFrameName( ModelHandle, FrameIndex ) ) ;
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
