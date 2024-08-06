#include "DxLib.h"

int main()
{
    int SHandle ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // test.wavのメモリへの読み込みサウンドハンドルをSHandleに保存します
    SHandle = LoadSoundMem( "test.wav" ) ;

    // 音量の設定
    ChangeVolumeSoundMem( 255 * 80 / 100, SHandle ) ;

    // 音の再生
    PlaySoundMem( SHandle , DX_PLAYTYPE_BACK ) ;

    // キー入力があるまで待ちます(『WaitKey』使用)
    WaitKey() ;

    // サウンドハンドルの削除
    DeleteSoundMem( SHandle ) ;

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
