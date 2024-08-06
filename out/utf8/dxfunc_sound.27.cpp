#include "DxLib.h"

int main()
{
    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // test.midのバックグラウンド演奏
    PlayMusic( "test.mid" , DX_PLAYTYPE_BACK ) ;

    // 演奏終了までここでループ
    while( CheckMusic() == 1 )
    {
        // メッセージ処理
        if( ProcessMessage() == -1 )
        {
            break ;    // エラーが起きたらループを抜ける
        }
    }

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
