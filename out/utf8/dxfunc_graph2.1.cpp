#include "DxLib.h"

int main()
{
    int Start , Time ;
    unsigned int Cr ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() == -1 ) return 0;

    // 白の色コードを保存
    Cr = GetColor( 255 , 255, 255 ) ;

    // スタートタイムを取得
    Start = GetNowCount() ;

    // メッセージを表示
    DrawString( 0 , 0 , "なにかキーを押してください" , Cr ) ;

    // ボタンが押されるまで待つ
    WaitKey() ;

    // 終了、経過時間を算出
    Time = GetNowCount() - Start ;

    // 画面に表示
    ClearDrawScreen() ;
    DrawFormatString( 0, 0, Cr, "ボタンが押されるまでに %dミリ秒経過しました", Time ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリ使用の終了
    DxLib_End() ;

    return 0 ;
}
