#include "DxLib.h"

int main()
{
    int Rot ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
         return -1;    // エラーが起きたら直ちに終了

    // 裏画面を使用
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // 合計値を初期化
    Rot = 0 ;

    // 何かキーが押されるまでループ
    while( CheckHitKeyAll() == 0 )
    {
        // メッセージ処理
        if( ProcessMessage() == -1 ) break ;    // エラーが起きたらループから抜ける

        // 前回 GetMouseWheelRotVol が呼ばれてから今回までの回転量を足す
        Rot += GetMouseWheelRotVol() ;

        // 画面を初期化
        ClearDrawScreen() ;

        // 画面に回転量を描画
        DrawFormatString( 0, 0, GetColor( 255,255,255 ), "%d", Rot ) ;

        // 裏画面の内容を表画面に表示
        ScreenFlip() ;
    }

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
