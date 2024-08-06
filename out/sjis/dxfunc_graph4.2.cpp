#include "DxLib.h"

int main()
{
    int MaskHandle[ 16 ] ;
    int i ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // �`����ʂ𗠉�ʂɂ��܂�
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // �}�X�N��ʂ��쐬���܂�
    CreateMaskScreen() ;

    // �}�X�N�f�[�^�����[�h���܂�
    LoadDivMask( "testMask2.bmp", 16, 8, 2, 8, 16, MaskHandle ) ;

    // �}�X�N����ʑS�̂Ƀ^�C����ɕ`�悵�A�j���[�V���������܂�
    for( i = 0 ; i < 16 ; i ++ )
    {
        // ��ʏ�����
        ClearDrawScreen() ;

        // ��ʑS�̂Ƀ^�C����`��
        DrawFillMask( 0 , 0 , 640 , 480 , MaskHandle[ i ] ) ;

        // ��ʂ����ς��ɐ��l�p��`���܂�
        DrawBox( 0 , 0 , 640 , 480 , GetColor( 0 , 0 , 255 ) , TRUE ) ;

        // ���ԑ҂�
        WaitTimer( 100 ) ;

        // ����ʂ̓��e��\��ʂɔ��f������
        ScreenFlip() ;
    }

    // �Ō�̎��ԑ҂�
    WaitTimer( 1000 ) ;

    // �}�X�N�f�[�^���폜���܂�
    for( i = 0 ; i < 16 ; i ++ )
    {
        DeleteMask( MaskHandle[ i ] ) ;
    }

    // �}�X�N��ʂ��폜���܂�
    DeleteMaskScreen() ;

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
