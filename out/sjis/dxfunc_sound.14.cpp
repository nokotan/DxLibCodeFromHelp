#include "DxLib.h"

int main()
{
    int SHandle, DupSHandle ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // test.wavのメモリへの読み込みサウンドハンドルをSHandleに保存します
    SHandle = LoadSoundMem( "test.wav" ) ;

    // test.wavを使用する SHandle とは別のサウンドハンドルを作成する
    DupSHandle = DuplicateSoundMem( SHandle ) ;

    // 読みこんだ音をノーマル再生します(『PlaySoundMem』関数使用)
    PlaySoundMem( SHandle , DX_PLAYTYPE_NORMAL ) ;

    // SHandle から複製した DupSHandle をノーマル再生します
    PlaySoundMem( DupSHandle , DX_PLAYTYPE_NORMAL ) ;

    // サウンドハンドルの削除
    DeleteSoundMem( SHandle ) ;
    DeleteSoundMem( DupSHandle ) ;

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
