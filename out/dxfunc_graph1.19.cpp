#include "DxLib.h"

int main()
{
    int TestHandle , BackHandle ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // test1.bmpの読み込み
    TestHandle = LoadGraph( "test1.bmp" ) ;

    // back.bmpの読み込み
    BackHandle = LoadGraph( "back.bmp" ) ;


    // 描画ブレンドモードをノーブレンドにする
    SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;

    // 背景を描画
    DrawGraph( 0 , 0 , BackHandle , FALSE ) ;

    // 上に載せるグラフィックを描画
    DrawGraph( 255 , 0 , TestHandle , TRUE ) ;

    // キー待ち(『WaitKey』を使用)
    WaitKey() ;


    // 背景を描画
    DrawGraph( 0 , 0 , BackHandle , FALSE ) ;

    // 描画ブレンドモードをアルファブレンド（５０％）にする
    SetDrawBlendMode( DX_BLENDMODE_ALPHA , 128 ) ;

    // 上に載せるグラフィックを描画
    DrawGraph( 255 , 0 , TestHandle , TRUE ) ;

    // キー待ち(『WaitKey』を使用)
    WaitKey() ;


    // 描画ブレンドモードをノーブレンドにする
    SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;

    // 背景を描画
    DrawGraph( 0 , 0 , BackHandle , FALSE ) ;

    // 描画ブレンドモードを加算ブレンド（１００％）にする
    SetDrawBlendMode( DX_BLENDMODE_ADD , 255 ) ;

    // 上に載せるグラフィックを描画
    DrawGraph( 255 , 0 , TestHandle , TRUE ) ;

    // キー待ち(『WaitKey』を使用)
    WaitKey() ;



    // 描画ブレンドモードをノーブレンドにする
    SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;

    // 背景を描画
    DrawGraph( 0 , 0 , BackHandle , FALSE ) ;

    // 描画ブレンドモードを減算ブレンド（８０％）にする
    SetDrawBlendMode( DX_BLENDMODE_SUB , 204 ) ;

    // 上に載せるグラフィックを描画
    DrawGraph( 255 , 0 , TestHandle , TRUE ) ;

    // キー待ち((7-3)『WaitKey』を使用)
    WaitKey() ;



    // 描画ブレンドモードをノーブレンドにする
    SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;

    // 背景を描画
    DrawGraph( 0 , 0 , BackHandle , FALSE ) ;

    // 描画ブレンドモードを乗算ブレンドにする
    SetDrawBlendMode( DX_BLENDMODE_MUL , 0 ) ;

    // 上に載せるグラフィックを描画
    DrawGraph( 255 , 0 , TestHandle , TRUE ) ;

    // キー待ち((7-3)『WaitKey』を使用)
    WaitKey() ;


    // 読み込んだ画像のグラフィックハンドルを削除
    DeleteGraph( TestHandle ) ;
    DeleteGraph( BackHandle ) ;


    DxLib_End() ;    // ＤＸライブラリ使用の終了処理

    return 0 ;    // ソフトの終了
}
