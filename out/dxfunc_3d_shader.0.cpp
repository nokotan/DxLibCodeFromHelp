#include "DxLib.h"

int main()
{
    int Direct3DVersion ;

    // Direct3D 9Ex の使用を指定
    SetUseDirect3DVersion( DX_DIRECT3D_9EX ) ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 ) return -1;

    // 使用している Direct3D のバージョンを取得
    Direct3DVersion = GetUseDirect3DVersion() ;

    // 使用バージョンが Direct3D 9Ex かどうかをチェック
    if( Direct3DVersion == DX_DIRECT3D_9EX )
    {
        DrawString( 0, 0, "Direct3D 9Ex を使用しています", GetColor( 255,255,255 ) ) ;
    }
    else
    {
        DrawString( 0, 0, "Direct3D 9Ex を使用していません", GetColor( 255,255,255 ) ) ;
    }

    // キー入力待ち
    WaitKey();

    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}
