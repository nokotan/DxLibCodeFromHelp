#include "DxLib.h"

int main()
{
    int GHandle ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // test1.bmpの読み込み
    GHandle = LoadGraph( "test1.bmp" ) ;

    // 描画モードをネアレストネイバー法にする
    SetDrawMode( DX_DRAWMODE_NEAREST ) ;

    // 読みこんだグラフィックを画面左上に拡大描画
    DrawExtendGraph( 0 , 0 , 130 * 2 , 480 * 2 , GHandle , FALSE ) ;

    // 描画モードをバイリニア法にする
    SetDrawMode( DX_DRAWMODE_BILINEAR ) ;

    // 読みこんだグラフィックを先ほどの隣に描画
    DrawExtendGraph( 260 , 0 , 260 + 130 * 2 , 480 * 2 , GHandle , FALSE ) ;

    // 読み込んだ画像のグラフィックハンドルを削除
    DeleteGraph( GHandle ) ;

    WaitKey() ;        // 結果を見るためにキー待ち(『WaitKey』を使用)

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
