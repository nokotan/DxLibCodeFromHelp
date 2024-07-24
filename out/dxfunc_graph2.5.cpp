#include "DxLib.h"

int main()
{
    unsigned int Cr ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // 描画する文字列の文字セットを変更します
    ChangeFont( "ＭＳ 明朝" ) ;

    // 白色の値を取得
    Cr = GetColor( 255 , 255 , 255 ) ;

    // 文字列の描画
    DrawString( 100 , 240 - 42 , "Hello C World!" , Cr );

    WaitKey() ;        // キーの入力待ち(『WaitKey』を使用)

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
