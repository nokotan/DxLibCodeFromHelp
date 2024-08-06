#include "DxLib.h"

int main()
{
    int ModelHandle, MaterialNum, i ;
    COLOR_F Color ;
    char *Name ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // モデルに含まれるマテリアルの数を取得する
    MaterialNum = MV1GetMaterialNum( ModelHandle ) ;

    // マテリアルの情報を一つづつ描画する
    for( i = 0 ; i < MaterialNum ; i ++ )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // マテリアルの名前を描画
        DrawFormatString( 0, 0, GetColor( 255,255,255 ),  "Name            %s", MV1GetMaterialName( ModelHandle, i ) ) ;

        // マテリアルのディフューズカラーを描画
        Color = MV1GetMaterialDifColor( ModelHandle, i ) ;
        DrawFormatString( 0, 16, GetColor( 255,255,255 ), "Diffuse  Color  R:%f  G:%f  B:%f  A:%f", Color.r, Color.g, Color.b, Color.a ) ;

        // マテリアルのスペキュラカラーを描画
        Color = MV1GetMaterialSpcColor( ModelHandle, i ) ;
        DrawFormatString( 0, 32, GetColor( 255,255,255 ), "Specular Color  R:%f  G:%f  B:%f  A:%f", Color.r, Color.g, Color.b, Color.a ) ;

        // マテリアルのエミッシブカラーを描画
        Color = MV1GetMaterialEmiColor( ModelHandle, i ) ;
        DrawFormatString( 0, 48, GetColor( 255,255,255 ), "Emissive Color  R:%f  G:%f  B:%f  A:%f", Color.r, Color.g, Color.b, Color.a ) ;

        // マテリアルのアンビエントカラーを描画
        Color = MV1GetMaterialAmbColor( ModelHandle, i ) ;
        DrawFormatString( 0, 64, GetColor( 255,255,255 ), "Ambient  Color  R:%f  G:%f  B:%f  A:%f", Color.r, Color.g, Color.b, Color.a ) ;

        // マテリアルのスペキュラの強さ描画
        DrawFormatString( 0, 80, GetColor( 255,255,255 ), "Specular Power  %f", MV1GetMaterialSpcPower( ModelHandle, i ) ) ;

        // 描画ブレンドモードの描画
        switch( MV1GetMaterialDrawBlendMode( ModelHandle, i ) )
        {
        case DX_BLENDMODE_NOBLEND : Name = "DX_BLENDMODE_NOBLEND" ; break ;
        case DX_BLENDMODE_ALPHA   : Name = "DX_BLENDMODE_ALPHA"   ; break ;
        case DX_BLENDMODE_ADD     : Name = "DX_BLENDMODE_ADD"     ; break ;
        case DX_BLENDMODE_SUB     : Name = "DX_BLENDMODE_SUB"     ; break ;
        case DX_BLENDMODE_INVSRC  : Name = "DX_BLENDMODE_INVSRC"  ; break ;
        case DX_BLENDMODE_MULA    : Name = "DX_BLENDMODE_MULA"    ; break ;
        }
        DrawFormatString( 0, 96, GetColor( 255,255,255 ), "Draw Blend Mode   %s", Name ) ;

        // 描画ブレンドパラメータの描画
        DrawFormatString( 0, 112, GetColor( 255,255,255 ), "Draw Blend Param  %d", MV1GetMaterialDrawBlendParam( ModelHandle, i ) ) ;

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
