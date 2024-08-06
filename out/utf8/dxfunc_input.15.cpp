#include "DxLib.h"

int main()
{
    char String[ 2 ] ;
    char InputChar ;

    // 画面モードの設定
    SetGraphMode( 640 , 480 , 16 ) ;

    // ＤＸライブラリ初期化処理
    if( DxLib_Init() == -1 )
    {
        // エラーが起きたら直ちに終了
        return -1;
    }
    
    // 入力される文字を随時画面中央に描画します
    {
        String[ 1 ] = 0 ;

        // ＥＳＣキーが押されるか、何らかの内部エラーが発生するまでループする
        while( !ProcessMessage() && ( CheckHitKey( KEY_INPUT_ESCAPE ) == 0 ) )
        {
            // 文字入力バッファから文字を取得する
            InputChar = GetInputChar( TRUE ) ;

            // 操作コード以外の文字入力があった場合のみ表示処理を行う
            if( InputChar != 0 && InputChar >= CTRL_CODE_CMP )
            {
                // 画面の消去
                ClearDrawScreen() ;

                // 文字の保存
                String[ 0 ] = InputChar ;

                // 描画
                DrawString( 312 , 232 , String , GetColor( 255 , 255 , 255 )  ) ;
            }
        }
    }

    // ＤＸライブラリ使用の終了処理
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
