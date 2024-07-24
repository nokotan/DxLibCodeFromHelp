#include "DxLib.h"

int main()
{
    int GrHandle[ 20 ] ;
    int i ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 ) return -1 ;

    // �񓯊��ǂݍ��ݐݒ�ɕύX
    SetUseASyncLoadFlag( TRUE ) ;

    // Test1.bmp �� 20��ǂݍ���
    for( i = 0 ; i < 20 ; i ++ )
    {
        GrHandle[ i ] = LoadGraph( "Test1.bmp" ) ;
    }

    // �����ǂݍ��ݐݒ�ɕύX
    SetUseASyncLoadFlag( FALSE ) ;

    // �`���𗠉�ʂɂ���
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // ���C�����[�v(�����L�[�������ꂽ�烋�[�v�𔲂���)
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {                                                       
        // ��ʂ̃N���A
        ClearDrawScreen() ;

        // �ǂݍ��݂��I����Ă�����摜��`�悷��
        for( i = 0 ; i < 20 ; i ++ )
        {
            if( CheckHandleASyncLoad( GrHandle[ i ] ) == FALSE )
            {
                DrawGraph( i * 32, 0, GrHandle[ i ], TRUE ) ;
            }
        }

        // �񓯊��ǂݍ��݂̐���`��
        DrawFormatString( 0, 0, GetColor( 255,255,255 ), "�񓯊��ǂݍ��݂̐� %d", GetASyncLoadNum() ) ;

        // ����ʂ̓��e��\��ʂɔ��f
        ScreenFlip();
    }

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜����
    for( i = 0 ; i < 20 ; i ++ )
    {
        DeleteGraph( GrHandle[ i ] ) ;
    }

    // �c�w���C�u�����̌�n��
    DxLib_End();

    // �\�t�g�̏I��
    return 0;
}
