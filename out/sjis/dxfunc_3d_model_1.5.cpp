#include "DxLib.h"

int main()
{
    int ModelHandle, AnimNum, i ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // モデルに含まれるアニメーションの数を取得する
    AnimNum = MV1GetAnimNum( ModelHandle ) ;

    // アニメーションの一覧を描画する
    for( i = 0 ; i < AnimNum ; i ++ )
    {
        // 左から順に、アニメーション番号、アニメーション名、アニメーションの総時間を描画する
        DrawFormatString( 0, i * 16, GetColor( 255,255,255 ),
            "No:%d Name:%s Time:%f",
            i,
            MV1GetAnimName( ModelHandle, i ),
            MV1GetAnimTotalTime( ModelHandle, i ) ) ;
    }

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
