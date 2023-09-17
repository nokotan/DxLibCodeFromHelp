#include "DxLib.h"

int main()
{
    int ModelHandle ;
    int PosX, PosZ, PosY ;

    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 )
    {
        // エラーが発生したら直ちに終了
        return -1 ;
    }

    // 次に読み込むモデルの物理演算モードをリアルタイム物理演算にする
    MV1SetLoadModelUsePhysicsMode( DX_LOADMODEL_PHYSICS_REALTIME ) ;

    // ３Ｄモデルの読み込み
    ModelHandle = MV1LoadModel( "Test.pmd" ) ;

    // 描画先を裏画面に変更
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // カメラに映る範囲( カメラからの距離の範囲 )を設定
    SetCameraNearFar( 10.0f, 1000.0f ) ;

    // カメラの位置と向きを設定
    SetCameraPositionAndTarget_UpVecY( VGet( 0.0f, 19.0f, -22.5f ), VGet( 0.0f, 10.0f, 0.0f ) ) ;

    // 座標をリセット
    PosX = 0 ;
    PosY = 0 ;
    PosZ = 0 ;

    // ウインドウが閉じられるまでループ
    while( ProcessMessage() == 0 )
    {
        // 画面をクリア
        ClearDrawScreen() ;

        // キーボードの上下左右でモデルの座標を変更
        // ( シフトキーを押しながら上下キーでモデルを上下に移動 )
        if( CheckHitKey( KEY_INPUT_LSHIFT ) )
        {
            if( CheckHitKey( KEY_INPUT_DOWN  ) ) PosY -- ;
            if( CheckHitKey( KEY_INPUT_UP    ) ) PosY ++ ;
        }
        else
        {
            if( CheckHitKey( KEY_INPUT_LEFT  ) ) PosX -- ;
            if( CheckHitKey( KEY_INPUT_RIGHT ) ) PosX ++ ;
            if( CheckHitKey( KEY_INPUT_DOWN  ) ) PosZ -- ;
            if( CheckHitKey( KEY_INPUT_UP    ) ) PosZ ++ ;
        }

        // モデルの座標をセット
        MV1SetPosition( ModelHandle, VGet( PosX * 0.5f, PosY * 0.5f, PosZ * 0.5f ) ) ;

        // 物理演算を６０分の１秒経過したという想定で実行
        MV1PhysicsCalculation( ModelHandle, 1000.0f / 60.0f ) ;

        // ３Ｄモデルの描画
        MV1DrawModel( ModelHandle ) ;

        // 裏画面の内容を表画面に反映
        ScreenFlip() ;
    }

    // モデルハンドルの削除
    MV1DeleteModel( ModelHandle ) ;

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}
