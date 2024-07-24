#include "DxLib.h"

int main()
{
    int Cr ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // 白色の値を取得
    Cr = GetColor( 255 , 255 , 255 ) ;

    // 文字列の描画
    DrawString( 200 , 240 - 32 , "キーを押してください" , Cr );

    // キーの入力待ち
    while( CheckHitKeyAll() == 0 )
    {
        // メッセージ処理
        if( ProcessMessage() == -1 )
        {
             break ;    // エラーが発生したらループを抜ける
        }
    }

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
