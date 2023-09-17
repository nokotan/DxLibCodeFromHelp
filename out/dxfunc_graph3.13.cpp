#include "DxLib.h"

int main()
{
    int MovieGraphHandle ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが発生したら終了
    }

    // ムービーファイルをロードします。
    MovieGraphHandle = LoadGraph( "??.mpg" ) ;

    // ムービーを再生状態にします
    PlayMovieToGraph( MovieGraphHandle ) ;

    // 描画先の画面を裏画面に
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // ループ、GetMovieStateToGraph 関数はムービーの再生状態を得る関数です
    // 戻り値が１の間は再生状態ですのでループを続けます
    while( ProcessMessage() == 0 && GetMovieStateToGraph( MovieGraphHandle ) == 1 )
    {
        // ムービー映像を画面いっぱいに描画します
        DrawExtendGraph( 0 , 0 , 640 , 480 , MovieGraphHandle , FALSE ) ;

        // 画面左上に再生時間を描画します
        DrawFormatString( 0, 0, GetColor( 255,255,255 ), "Time:%d", TellMovieToGraph( MovieGraphHandle ) ) ;

        // 裏画面の内容を表画面に反映します
        ScreenFlip() ;
    }

    // 読み込んだムービーファイルのグラフィックハンドルの削除
    DeleteGraph( MovieGraphHandle ) ;

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
