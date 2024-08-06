#include "DxLib.h"

int main()
{
    int MouseInput ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // マウスを表示状態にする
    SetMouseDispFlag( TRUE ) ;

    // マウスの入力を待つ
    MouseInput = GetMouseInput() ;
    while( ( MouseInput & MOUSE_INPUT_RIGHT ) == 0 )
    {
        // メッセージ処理
        if( ProcessMessage() == -1 )
        {
            break ;    // エラーが起きたらループから抜ける
        }

        // マウスの入力を得る
        MouseInput = GetMouseInput() ;
    }

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
