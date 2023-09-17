#include "DxLib.h"

int main()
{
    int ModelHandle, DupModelHandle ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // 描画先を裏画面に変更
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // 何かボタンが押されるかウインドウが閉じられるまでループ
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // 読み込んだデータと同じデータを使用するモデルハンドルを作成する
        DupModelHandle = MV1DuplicateModel( ModelHandle ) ;

        // 画面に映るランダムな位置に３Ｄモデルを移動
        MV1SetPosition( DupModelHandle, VGet( ( float )GetRand( 639 ), ( float )-GetRand( 300 ), GetRand( 300 ) + 300.0f ) ) ;

        // ３Ｄモデルの描画
        MV1DrawModel( DupModelHandle ) ;

        // ３Ｄモデルの削除
        MV1DeleteModel( DupModelHandle ) ;

        // 裏画面の内容を表画面に反映
        ScreenFlip() ;
    }

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
