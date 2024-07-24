#include "DxLib.h"
#include <stdlib.h>

int main()
{
    int Count ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // マウスを表示状態にする
    SetMouseDispFlag( TRUE ) ;

    // 現在のカウンタ値を得る『GetNowCount』関数使用
    Count = GetNowCount() ;

    // キーが押されるまでループ
    while( CheckHitKeyAll() == 0 )
    {
        // 前回のカウンタ参照から１秒たっているか判定
        if( GetNowCount() - Count > 1000 )
        {
            // 経っていたらマウスの位置を画面左上に移動

            // マウスの位置をセット
            SetMousePoint( 0 , 0 ) ;

            // 現在のカウンタ値を得る
            Count = GetNowCount() ;
        }

        // メッセージ処理
        if( ProcessMessage() == -1 )
        {
            break ;    // エラーが起きたらループを抜ける
        }
    }

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
