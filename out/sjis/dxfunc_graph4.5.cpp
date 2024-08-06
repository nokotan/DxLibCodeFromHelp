#include "DxLib.h"

int main()
{
    int MaskHandle ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;        // �G���[���N�����璼���ɏI��
    }

    // �}�X�N��ʂ��쐬���܂�
    CreateMaskScreen() ;

    // �}�X�N�f�[�^�����[�h���܂�
    MaskHandle = LoadMask( "testMask.bmp" ) ;

    // ��ʑS�̂Ƀ}�X�N���^�C����ɕ��ׂĕ`�悵�܂�
    DrawFillMask( 0 , 0 , 640 , 480 , MaskHandle ) ;

    // ��ʂ����ς��ɗ΂̎l�p��`��
    DrawBox( 0 , 0 , 640 , 480 , GetColor( 0 , 255 , 0 ) , TRUE ) ;
    ScreenFlip() ;

    // �L�[���͑҂�
    WaitKey() ;


    // �}�X�N��ʂ𖳌��ɂ��܂�
    SetUseMaskScreenFlag( FALSE );

    // ������x��ʂ����ς��ɗ΂̎l�p��`���܂�
    ClearDrawScreen() ;    // ��ʏ�����
    DrawBox( 0 , 0 , 640 , 480 , GetColor( 0 , 255 , 0 ) , TRUE ) ;
    ScreenFlip() ;

    // �L�[���͑҂�
    WaitKey() ;


    // �}�X�N��ʂ�L���ɂ��܂�
    SetUseMaskScreenFlag( TRUE ) ;

    // �Ăш�x��ʂ����ς��ɗ΂̎l�p��`���܂�
    ClearDrawScreen() ;    // ��ʏ�����
    DrawBox( 0 , 0 , 640 , 480 , GetColor( 0 , 255 , 0 ) , TRUE ) ;
    ScreenFlip() ;

    // �L�[���͑҂�
    WaitKey() ;


    // �}�X�N���폜���܂�
    DeleteMask( MaskHandle ) ;

    // �}�X�N��ʂ��폜���܂�
    DeleteMaskScreen() ;

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
