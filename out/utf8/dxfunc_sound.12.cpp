#include "DxLib.h"

int main()
{
    int SoundHandle ;
    int Freq , Add ;

    // ＤＸライブラリ初期化処理
    if( DxLib_Init() == -1 ) return -1;

    // 音をロードする
    SoundHandle = LoadSoundMem( "test.wav" ) ; 

    // 再生周波数と再生周波数の推移値を設定する
    Freq = 22050 ;
    Add = -10 ;

    // ロードした音のループ再生を開始する
    PlaySoundMem( SoundHandle , DX_PLAYTYPE_LOOP ) ;

    // ＥＳＣキーが押されるか、システムがエラーを起こすまでループする
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 ) 
    {
        // 再生周波数の設定値を変化させる
        Freq += Add ;
        if( Freq > 100000 ){ Freq = 100000 ; Add = -10 ; }
        if( Freq < 1000 ){ Freq = 1000  ; Add = 10 ; }

        // 再生周波数を設定する
        SetFrequencySoundMem( Freq , SoundHandle ) ; 

        // 少し待つ
        WaitTimer( 10 ) ;
    }

    // サウンドハンドルの削除
    DeleteSoundMem( SoundHandle ) ;

    // ＤＸライブラリ使用の終了処理
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
