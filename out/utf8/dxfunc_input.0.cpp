#include "DxLib.h"

int main()
{
    int Cr , PadInput ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // 白色の値を取得
    Cr = GetColor( 255 , 255 , 255 ) ;

    // 文字列の描画
    DrawString( 150 , 240 - 32 , "パッドのSTARTボタンを押してください" , Cr );

    // パッド１の9ボタンの入力待ち
    PadInput = GetJoypadInputState( DX_INPUT_KEY_PAD1 ) ;
    while( ( PadInput & PAD_INPUT_9 ) == 0 )
    {
        // メッセージ処理
        if( ProcessMessage() == -1 )
        {
             break ;    // エラーが発生したらループを抜ける
        }

        // パッド１の入力を取得
        PadInput = GetJoypadInputState( DX_INPUT_KEY_PAD1 ) ;
    }

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
