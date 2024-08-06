#include "DxLib.h"

int main()
{
    LONGLONG StartTime ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // 現在経過時間を得る
    StartTime = GetNowHiPerformanceCount() ;

    // 計測開始から６秒が過ぎるまでループ
    while( GetNowHiPerformanceCount() - StartTime < 6000000 )
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
