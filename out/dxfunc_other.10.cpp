-- 送信側プログラム
-----------------------------------
#include "DxLib.h"

int main()
{
    IPDATA Ip ;        // 送信用ＩＰアドレスデータ
    int NetUDPHandle ;        // ネットワークハンドル

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // ＵＤＰ通信用のソケットハンドルを作成
    NetUDPHandle = MakeUDPSocket( -1 ) ;

    // ＩＰアドレスを設定( ここにある４つのＩＰ値は仮です )
    Ip.d1 = 192 ;
    Ip.d2 = 168 ;
    Ip.d3 = 0 ;
    Ip.d4 = 14 ;

    // 文字列の送信
    NetWorkSendUDP( NetUDPHandle, Ip, 9850, "メッセージ！！", 15 ) ;

    // 送信したよと表示
    DrawString( 0, 0, "文字列を送信しました、何かキーを押すと終了します", GetColor( 255,255,255 ) ) ;

    // キー入力待ち
    WaitKey() ;

    // ＵＤＰソケットハンドルの削除
    DeleteUDPSocket( NetUDPHandle ) ; 

    DxLib_End() ;    // ＤＸライブラリ使用の終了処理

    return 0 ;    // ソフトの終了
}

-- 受信側プログラム
-----------------------------------
#include "DxLib.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
    char StrBuf[ 256 ] ;    // データバッファ
    int NetUDPHandle ;        // ネットワークハンドル

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }

    // ＵＤＰ通信用のソケットハンドルを作成
    NetUDPHandle = MakeUDPSocket( 9850 ) ;

    // 受信待ちだよと表示
    DrawString( 0, 0, "受信待ち", GetColor( 255,255,255 ) ) ;

    // 文字列の受信を待つ
    while( CheckNetWorkRecvUDP( NetUDPHandle ) == FALSE )
    {
        // ウインドウズメッセージ処理
        if( ProcessMessage() < 0 ) break ;
    }

    // 受信
    NetWorkRecvUDP( NetUDPHandle, NULL, NULL, StrBuf, 256, FALSE ) ;

    // 受信した文字列を画面に描画
    ClearDrawScreen() ;
    DrawString( 0, 0, StrBuf, GetColor( 255,255,255 ) ) ;

    // キー入力待ち
    WaitKey() ;

    // ＵＤＰソケットハンドルの削除
    DeleteUDPSocket( NetUDPHandle ) ; 

    DxLib_End() ;    // ＤＸライブラリ使用の終了処理

    return 0 ;    // ソフトの終了
}
