#include "DxLib.h"

int main()
{
    int GraphHandle ;

    // 画面モードを１６ビットカラーにセット
    SetGraphMode( 640 , 480 , 16 ) ;

    // ＤＸライブラリ初期化
    if( DxLib_Init() == -1 )    return -1 ;

    // 画像のロード
    GraphHandle = LoadGraph( "test1.bmp" ) ;

    // 描画輝度を設定、赤成分を０にする
    SetDrawBright( 0 , 255 , 255 ) ;

    // 画面に描画
    DrawGraph( 0 , 0 , GraphHandle , FALSE ) ;

    // 画面全体を Save.bmp として保存
    SaveDrawScreen( 0 , 0 , 640 , 480 , "Save.bmp" ) ;

    // 読み込んだ画像のグラフィックハンドルを削除
    DeleteGraph( GraphHandle ) ;

    // ＤＸライブラリ使用の終了処理
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
