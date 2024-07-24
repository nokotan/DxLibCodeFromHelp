#include "DxLib.h"

int main()
{
    int ModelHandle, AttachIndex ;
    float TotalTime ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // ３Ｄモデルの０番目のアニメーションをアタッチする
    AttachIndex = MV1AttachAnim( ModelHandle, 0, -1, FALSE ) ;

    // アニメーション０番の総時間を画面に描画
    TotalTime = MV1GetAttachAnimTotalTime( ModelHandle, AttachIndex ) ;
    DrawFormatString( 0, 0, GetColor( 255,255,255 ), "%f", TotalTime ) ;

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
