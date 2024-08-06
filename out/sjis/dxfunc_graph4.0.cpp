#include "DxLib.h"

int main()
{
    int MaskHandle ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // �}�X�N��ʂ��쐬���܂�
    CreateMaskScreen() ;

    // �}�X�N�f�[�^�����[�h���܂�
    MaskHandle = LoadMask( "testMask.bmp" ) ;

    // ���[�h�����}�X�N�f�[�^����ʂ̍���ɕ`�悵�܂�
    DrawMask( 0 , 0 , MaskHandle , DX_MASKTRANS_NONE ) ;

    // ��ʂ����ς��ɐԂ��l�p��`���܂�
    DrawBox( 0 , 0 , 640 , 480 , GetColor( 255 , 0 , 0 ) , TRUE ) ;

    // �L�[�̓��͑҂������܂�
    WaitKey() ;

    // �}�X�N�f�[�^���폜���܂�
    DeleteMask( MaskHandle ) ;

    // �}�X�N��ʂ��폜���܂�
    DeleteMaskScreen() ;

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
