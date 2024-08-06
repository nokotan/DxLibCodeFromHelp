#include "DxLib.h"

int main()
{
    int MaskHandle ;
    unsigned char MaskData[ 16 ][ 16 ] ;
    int i , j ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // �`���𗠉�ʂɂ��܂�
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // �}�X�N��ʂ��쐬���܂�
    CreateMaskScreen() ;

    // ��̃}�X�N���쐬���܂�
    MaskHandle = MakeMask( 16 , 16 ) ;

    // �}�X�N�f�[�^�𔒂Ŗ��߂܂�
    for( i = 0 ; i < 16 ; i ++ )
        for( j = 0 ; j < 16 ; j ++ )
            MaskData[ i ][ j ] = 0xff ;

    // ���[�v
    for( i = 0 ; i < 16 ; i ++ )
    {
        // ��ʂ�������
        ClearDrawScreen() ;

        // �}�X�N�̃f�[�^���ꕔ�ύX
        for( j = 0 ; j < 16 ; j ++ )
            MaskData[ i ][ j ] = 0 ;

        // �}�X�N�Ƀf�[�^���Z�b�g
        SetDataToMask( 16 , 16 , MaskData , MaskHandle ) ;

        // �}�X�N��ʂ��Z�b�g�����}�X�N�f�[�^�Ŗ��߂܂�
        DrawFillMask( 0 , 0 , 640 , 480 , MaskHandle ) ;

        // ���̎l�p����ʑS�̂ɕ`�悵�܂�
        DrawBox( 0 , 0 , 640 , 480 , GetColor( 255 , 255 , 255 ) , TRUE ) ;

        // ����ʂ̓��e��\��ʂɔ��f�����܂�
        ScreenFlip() ;

        // ���ԑ҂�
        WaitTimer( 100 ) ;
    }

    // �}�X�N���폜���܂�
    DeleteMask( MaskHandle ) ;

    // �}�X�N��ʂ��폜���܂�
    DeleteMaskScreen() ;

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
