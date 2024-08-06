#include "DxLib.h"

int main()
{
    int StartTime ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // 現在経過時間を得る
    StartTime = GetNowCount() ;

    // 計測開始から６秒が過ぎるまでループ
    while( GetNowCount() - StartTime < 6000 )
    {
        // メッセージ処理
        if( ProcessMessage() == -1 )
        {
            break ;    // エラーが起きたらループから抜ける
        }
    }

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
