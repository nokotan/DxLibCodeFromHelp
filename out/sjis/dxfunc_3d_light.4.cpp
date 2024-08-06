#include "DxLib.h"

int main()
{
    int ModelHandle ;
    float OutAngle, InAngle, Range, Atten0, Atten1, Atten2 ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // モデルの読み込み
    ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;

    // 描画先を裏画面にする
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // 各パラメータを初期化
    OutAngle = 90.0f ;
    InAngle = 45.0f ;
    Range = 2000.0f ;
    Atten0 = 0.0f ;
    Atten1 = 0.0006f ;
    Atten2 = 0.0f ;

    // ＥＳＣキーが押されるかウインドウが閉じられるまでループ
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // ＡＺキーで OutAngle の値を変更
        if( CheckHitKey( KEY_INPUT_A ) == 1 )
        {
            OutAngle += 1.0f ;
        }
        if( CheckHitKey( KEY_INPUT_Z ) == 1 )
        {
            OutAngle -= 1.0f ;
        }

        // ＳＸキーで InAngle の値を変更
        if( CheckHitKey( KEY_INPUT_S ) == 1 )
        {
            InAngle += 1.0f ;
        }
        if( CheckHitKey( KEY_INPUT_X ) == 1 )
        {
            InAngle -= 1.0f ;
        }

        // ＤＣキーでライトの影響範囲を変更
        if( CheckHitKey( KEY_INPUT_D ) == 1 )
        {
            Range += 20.0f ;
        }
        if( CheckHitKey( KEY_INPUT_C ) == 1 )
        {
            Range -= 20.0f ;
        }

        // ＦＶキーでライトの距離減衰パラメータ０の値を変更
        if( CheckHitKey( KEY_INPUT_F ) == 1 )
        {
            Atten0 += 0.001f ;
        }
        if( CheckHitKey( KEY_INPUT_V ) == 1 )
        {
            Atten0 -= 0.001f ;
        }

        // ＧＢキーでライトの距離減衰パラメータ１の値を変更
        if( CheckHitKey( KEY_INPUT_G ) == 1 )
        {
            Atten1 += 0.00001f ;
        }
        if( CheckHitKey( KEY_INPUT_B ) == 1 )
        {
            Atten1 -= 0.00001f ;
        }

        // ＨＮキーでライトの距離減衰パラメータ２の値を変更
        if( CheckHitKey( KEY_INPUT_H ) == 1 )
        {
            Atten2 += 0.0000001f ;
        }
        if( CheckHitKey( KEY_INPUT_N ) == 1 )
        {
            Atten2 -= 0.0000001f ;
        }

        // 角度の値を補正
        if( OutAngle < 0.0f ) OutAngle = 0.0f ;
        if( OutAngle > 180.0f ) OutAngle = 180.0f ;
        if( InAngle < 0.0f ) InAngle = 0.0f ;
        if( InAngle > OutAngle ) InAngle = OutAngle ;

        // 影響距離の値を補正
        if( Range < 0.0f ) Range = 0.0f ;

        // 距離減衰パラメータの値を補正
        if( Atten0 < 0.0f ) Atten0 = 0.0f ;
        if( Atten1 < 0.0f ) Atten1 = 0.0f ;
        if( Atten2 < 0.0f ) Atten2 = 0.0f ;

        // Ｙ軸のマイナス方向のスポットライトを設定
        ChangeLightTypeSpot(
            VGet( 320.0f, 1000.0f, 200.0f ),
            VGet( 0.0f, -1.0f, 0.0f  ),
            OutAngle * DX_PI_F / 180.0f,
            InAngle * DX_PI_F / 180.0f,
            Range,
            Atten0,
            Atten1,
            Atten2 ) ;

        // モデルをカメラの映る位置に移動
        MV1SetPosition( ModelHandle, VGet( 320.0f, 240.0f, 200.0f ) ) ;

        // モデルを描画
        MV1DrawModel( ModelHandle ) ;

        // パラメータの内容を画面に表示
        DrawFormatString( 0, 0,  GetColor( 255,255,255 ), "Key:A.Z  OutAngle( 度 ) %f", OutAngle ) ;
        DrawFormatString( 0, 16, GetColor( 255,255,255 ), "Key:S.X  InAngle( 度 )  %f", InAngle ) ;
        DrawFormatString( 0, 32, GetColor( 255,255,255 ), "Key:D.C  Range          %f", Range ) ;
        DrawFormatString( 0, 48, GetColor( 255,255,255 ), "Key:F.V  Atten0         %f", Atten0 ) ;
        DrawFormatString( 0, 64, GetColor( 255,255,255 ), "Key:G.B  Atten1         %f", Atten1 ) ;
        DrawFormatString( 0, 80, GetColor( 255,255,255 ), "Key:H.N  Atten2         %f / 100.0f", Atten2 * 100.0f ) ;

        // 裏画面の内容を表画面に反映する
        ScreenFlip() ;
    }

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
