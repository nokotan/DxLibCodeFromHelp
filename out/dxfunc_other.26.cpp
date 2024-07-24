#include "DxLib.h"

int main()
{
    char NameBuffer[10][64] ;
    int FontNum ;

    // ＤＸライブラリ初期化処理
    if( DxLib_Init() == -1 ) return -1 ;


    // フォントを最大１０個列挙
    FontNum = EnumFontName( &NameBuffer[0][0] , 10 ) ;

    // ４個以下しかフォント名が列挙されなかったら次の処理は行わない
    if( FontNum >= 4 )
    {
        // ４個目に列挙されたフォント名を持つフォントに変更
        ChangeFont( NameBuffer[3] ) ;

        // 変更したフォントで文字を描画し、その後フォント名も描画
        DrawString( 100, 100, "４個目のフォントはなんだろう" , GetColor( 255, 255, 255 ) ) ;
        DrawString( 100, 130, NameBuffer[3] , GetColor( 255, 255, 255 ) ) ;
    }

    // キー入力を待つ
    WaitKey() ;

    // ＤＸライブラリ使用の終了処理
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
