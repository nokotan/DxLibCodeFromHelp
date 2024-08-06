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

    // ループ、GetMovieStateToGraph 関数はムービーの再生状態を得る関数です
    // 戻り値が１の間は再生状態ですのでループを続けます
    while( ProcessMessage() == 0 && GetMovieStateToGraph( MovieGraphHandle ) == 1 )
    {
        // ムービー映像を画面いっぱいに描画します
        DrawExtendGraph( 0 , 0 , 640 , 480 , MovieGraphHandle , FALSE ) ;

        // ウエイトをかけます、あまり速く描画すると画面がちらつくからです
        WaitTimer( 17 ) ;
    }

    // 読み込んだムービーファイルのグラフィックハンドルの削除
    DeleteGraph( MovieGraphHandle ) ;

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
