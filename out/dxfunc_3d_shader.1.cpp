#include "DxLib.h"

int main()
{
    int ShaderVersion ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 ) return -1;

    // 使用できるプログラマブルシェーダーのバージョンを取得
    ShaderVersion = GetValidShaderVersion() ;

    // バージョン番号が０だったら使用不可能
    if( ShaderVersion == 0 )
    {
        DrawString( 0, 0, "プログラマブルシェーダーを使うことはできません", GetColor( 255,255,255 ) ) ;
    }
    else
    {
        // ０以外だったら使用可能
        DrawFormatString( 0, 0, GetColor( 255,255,255 ), "プログラマブルシェーダーバージョン %.1f が使用可能です", ShaderVersion / 100.0f ) ;
    }

    // キー入力待ち
    WaitKey();

    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}
