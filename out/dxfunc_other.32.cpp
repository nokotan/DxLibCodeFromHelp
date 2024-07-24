#include "DxLib.h"

int main()
{
    int SoundHandle ;

    // ＤＸライブラリ初期化処理
    if( DxLib_Init() == -1 ) return -1;

    // 再生形式をファイルからストリーム再生する、に設定
    SetCreateSoundDataType( DX_SOUNDDATATYPE_FILE ) ;

    // BGM.wav を読み込み、ハンドルを取得する
    SoundHandle = LoadSoundMem( "BGM.wav" ) ;

    // 再生
    PlaySoundMem( SoundHandle, DX_PLAYTYPE_LOOP ) ;

    // 何かキーが押されるまで待つ
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 ){}

    // サウンドハンドルの削除
    DeleteSoundMem( SoundHandle ) ;

    // ＤＸライブラリ使用の終了処理
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
