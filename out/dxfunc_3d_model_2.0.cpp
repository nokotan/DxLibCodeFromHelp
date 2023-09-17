#include "DxLib.h"

int main()
{
    int ModelHandle ;
    int i, TextureNum ;
    int Width, Height, GrHandle ;
    const char *String ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;

    // モデルに含まれるテクスチャの総数を取得する
    TextureNum = MV1GetTextureNum( ModelHandle ) ;

    // テクスチャの数だけ繰り返し
    for( i = 0 ; i < TextureNum ; i ++ )
    {
        // 画面をクリアする
        ClearDrawScreen() ;

        // テクスチャのグラフィックハンドルを取得する
        GrHandle = MV1GetTextureGraphHandle( ModelHandle, i ) ;

        // テクスチャの名前を描画する
        DrawFormatString( 0, 0, GetColor( 255,255,255 ),  "Name                  %s", MV1GetTextureName( ModelHandle, i ) ) ;

        // テクスチャの大きさを描画する
        GetGraphSize( GrHandle, &Width, &Height ) ;
        DrawFormatString( 0, 16, GetColor( 255,255,255 ), "Size                  %dx%d", Width, Height ) ;

        // テクスチャのＵ値のアドレスモードを描画する
        switch( MV1GetTextureAddressModeU( ModelHandle, i ) )
        {
        case DX_TEXADDRESS_WRAP   : String = "DX_TEXADDRESS_WRAP" ;   break ;
        case DX_TEXADDRESS_MIRROR : String = "DX_TEXADDRESS_MIRROR" ; break ;
        case DX_TEXADDRESS_CLAMP  : String = "DX_TEXADDRESS_CLAMP" ;  break ;
        }
        DrawFormatString( 0, 32, GetColor( 255,255,255 ), "Address Mode U        %s", String ) ;

        // テクスチャのＶ値のアドレスモードを描画する
        switch( MV1GetTextureAddressModeV( ModelHandle, i ) )
        {
        case DX_TEXADDRESS_WRAP   : String = "DX_TEXADDRESS_WRAP" ;   break ;
        case DX_TEXADDRESS_MIRROR : String = "DX_TEXADDRESS_MIRROR" ; break ;
        case DX_TEXADDRESS_CLAMP  : String = "DX_TEXADDRESS_CLAMP" ;  break ;
        }
        DrawFormatString( 0, 48, GetColor( 255,255,255 ), "Address Mode V        %s", String ) ;

        // テクスチャのフィルタリングモードを描画する
        switch( MV1GetTextureSampleFilterMode( ModelHandle, i ) )
        {
        case DX_DRAWMODE_NEAREST :     String = "DX_DRAWMODE_NEAREST" ;     break ;
        case DX_DRAWMODE_BILINEAR :    String = "DX_DRAWMODE_BILINEAR" ;    break ;
        case DX_DRAWMODE_ANISOTROPIC : String = "DX_DRAWMODE_ANISOTROPIC" ; break ;
        }
        DrawFormatString( 0, 64, GetColor( 255,255,255 ), "Sample Filter Mode    %s", String ) ;

        // テクスチャを描画する
        DrawGraph( 0, 80, GrHandle, TRUE ) ;

        // キー入力待ち
        WaitKey() ;
    }

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
