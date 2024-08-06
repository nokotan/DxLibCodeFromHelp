#include "DxLib.h"

int main()
{
    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが発生したら終了
    }

    PlayMovie( "test.avi" , 1 , DX_MOVIEPLAYTYPE_NORMAL ) ;

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
