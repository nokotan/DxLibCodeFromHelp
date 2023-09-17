#include "DxLib.h"

int main()
{
    int LightHandle ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // ディレクショナルライトタイプのハンドルの作成
    LightHandle = CreateDirLightHandle( VGet( 1.0f, 0.0f, 0.0f ) ) ;

    // 直後に削除
    DeleteLightHandle( LightHandle ) ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
