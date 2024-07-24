#include "DxLib.h"

int main()
{
    char StrBuf[ 128 ] , StrBuf2[ 32 ];
    int MouseX , MouseY ;
    int StringCr , BoxCr ;

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // マウスを表示状態にする
    SetMouseDispFlag( TRUE ) ;

    // 白色の値を取得
    StringCr = GetColor( 255 , 255 , 255 ) ;

    // 黒の値を取得
    BoxCr = GetColor( 0 , 0 , 0 ) ;

    // キーが押されるまでループ
    while( CheckHitKeyAll() == 0 )
    {
        // マウスの位置を取得
        GetMousePoint( &MouseX , &MouseY ) ;

        // 画面左上の領域に黒い四角を描き前に描いてあった文字列を消す
        DrawBox( 0 , 0 , 640 , 32 , BoxCr , TRUE ) ;

        // 座標文字列を描く
        DrawFormatString( 0 , 0 , StringCr , "座標Ｘ %d　　座標Ｙ %d" , MouseX , MouseY ) ;
                
        // メッセージ処理
        if( ProcessMessage() == -1 )
        {
            break ;    // エラーが起きたらループを抜ける
        }

        // 一定時間待つ
        WaitTimer( 100 ) ;
    }

    DxLib_End() ;        // ＤＸライブラリ使用の終了処理

    return 0 ;        // ソフトの終了
}
