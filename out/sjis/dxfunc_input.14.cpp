#include "DxLib.h"

#define PI    3.1415926535897932384626433832795f

int main()
{
    char KeyBuf[ 256 ] ;

    // ＤＸライブラリ初期化処理
    if( DxLib_Init() == -1 ) return -1;

    // メッセージの表示
    DrawString( 0 , 0 , " C と K と Y のキーを同時に押したら終了します ", GetColor( 255 , 255 , 255 ) ) ;

    // 無限ループ
    while( 1 )
    {
        // すべてのキーの状態を得る
        GetHitKeyStateAll( KeyBuf ) ;

        // ＣとＫとＹのキーが押されていたらループから抜ける
        if( KeyBuf[ KEY_INPUT_C ] == 1 &&
            KeyBuf[ KEY_INPUT_K ] == 1 &&
            KeyBuf[ KEY_INPUT_Y ] == 1 )
        {
            break ;
        }

        // Windows 依存のメッセージ処理を行う
        if( ProcessMessage() == -1 ) break ;
    }

    // ＤＸライブラリ使用の終了処理
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
