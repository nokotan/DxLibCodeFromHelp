#include "DxLib.h"

int main()
{
    int Handle ;
    int BlendHandle ;
    int AlphaHandle ;

    // 画面モードを32bitカラーにする
    SetGraphMode( 640, 480, 32 ) ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
        return -1 ;

    // 画像を読み込む
    Handle = LoadGraph( "Src1.bmp" ) ;

    // ブレンドする画像を読み込む
    BlendHandle = LoadGraph( "Src2.tga" ) ;

    // アルファチャンネル付きの描画可能画像のグラフィックハンドルを作成する
    AlphaHandle = MakeScreen( 256, 256, TRUE ) ;

    // 描画先を作成したアルファチャンネル付きの描画可能画像にする
    SetDrawScreen( AlphaHandle ) ;

    // 読み込んだ画像を描画する
    DrawGraph( 0, 0, Handle, FALSE ) ;

    // 描画先を表画面に戻す
    SetDrawScreen( DX_SCREEN_FRONT ) ;

    // 描画可能画像とブレンドする画像を合成する
    GraphBlend( AlphaHandle, BlendHandle, 255, DX_GRAPH_BLEND_RGBA_SELECT_MIX,
        DX_RGBA_SELECT_SRC_G,    // 出力結果の赤成分は AlphaHandle の緑成分
        DX_RGBA_SELECT_SRC_R,    // 出力結果の緑成分は AlphaHandle の赤成分
        DX_RGBA_SELECT_SRC_B,    // 出力結果の青成分は AlphaHandle の青成分
        DX_RGBA_SELECT_BLEND_R    // 出力結果のアルファ成分は BlendHandle の赤成分
    ) ;

    // アルファ成分で半透明になることを確かめるために画面全体にグレーの矩形を描画する
    DrawBox( 0, 0, 640, 480, GetColor( 128, 128, 128 ), TRUE ) ;

    // 描画可能画像を画面に描画
    DrawGraph( 0, 0, AlphaHandle, TRUE ) ;

    // 読み込んだ画像のグラフィックハンドルを削除
    DeleteGraph( Handle ) ;
    DeleteGraph( BlendHandle ) ;

    // MakeScreen で作成したグラフィックハンドルの削除
    DeleteGraph( AlphaHandle ) ;

    // キー入力待ち
    WaitKey() ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    return 0 ;
}
