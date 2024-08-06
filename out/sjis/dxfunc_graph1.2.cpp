#include "DxLib.h"

int main()
{
    int GHandle[ 10 ] ;
    int i ;

    if( DxLib_Init() == -1 )        // ＤＸライブラリ初期化処理
    {
         return -1;        // エラーが起きたら直ちに終了
    }

    // ＢＭＰ画像のメモリへの分割読み込み
    LoadDivGraph( "test2.bmp" , 10 , 4 , 3 , 48 , 56 , GHandle ) ;

    // ロードしたグラフィックのアニメーション
    i = 0 ;
    // キーが押されるまでループ(キー判定には『CheckHitKeyAll』を使用)
    while( CheckHitKeyAll() == 0 )
    {
        // グラフィックの描画(『DrawGraph』使用)
        DrawGraph( 0 , 0 , GHandle[ i ] , FALSE ) ;

        // アニメーションパターンナンバーを変更
        i ++ ;
        if( i == 10 ) i = 0 ;

        // 一定時間待つ(『WaitTimer』使用)
        WaitTimer( 100 ) ;

        // メッセージ処理
        if( ProcessMessage() == -1 )
        {
            break ;        // エラーが起きたらループから抜ける
        }
    }

    // 読み込んだ画像のグラフィックハンドルを削除
    for( i = 0 ; i < 10 ; i ++ )
    {
        DeleteGraph( GHandle[ i ] ) ;
    }

    DxLib_End() ;            // ＤＸライブラリ使用の終了処理

    return 0 ;            // ソフトの終了
}
