#include "DxLib.h"

int main()
{
    int TestHandle , BackHandle ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // test1.bmp�̓ǂݍ���
    TestHandle = LoadGraph( "test1.bmp" ) ;

    // back.bmp�̓ǂݍ���
    BackHandle = LoadGraph( "back.bmp" ) ;


    // �`��u�����h���[�h���m�[�u�����h�ɂ���
    SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;

    // �w�i��`��
    DrawGraph( 0 , 0 , BackHandle , FALSE ) ;

    // ��ɍڂ���O���t�B�b�N��`��
    DrawGraph( 255 , 0 , TestHandle , TRUE ) ;

    // �L�[�҂�(�wWaitKey�x���g�p)
    WaitKey() ;


    // �w�i��`��
    DrawGraph( 0 , 0 , BackHandle , FALSE ) ;

    // �`��u�����h���[�h���A���t�@�u�����h�i�T�O���j�ɂ���
    SetDrawBlendMode( DX_BLENDMODE_ALPHA , 128 ) ;

    // ��ɍڂ���O���t�B�b�N��`��
    DrawGraph( 255 , 0 , TestHandle , TRUE ) ;

    // �L�[�҂�(�wWaitKey�x���g�p)
    WaitKey() ;


    // �`��u�����h���[�h���m�[�u�����h�ɂ���
    SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;

    // �w�i��`��
    DrawGraph( 0 , 0 , BackHandle , FALSE ) ;

    // �`��u�����h���[�h�����Z�u�����h�i�P�O�O���j�ɂ���
    SetDrawBlendMode( DX_BLENDMODE_ADD , 255 ) ;

    // ��ɍڂ���O���t�B�b�N��`��
    DrawGraph( 255 , 0 , TestHandle , TRUE ) ;

    // �L�[�҂�(�wWaitKey�x���g�p)
    WaitKey() ;



    // �`��u�����h���[�h���m�[�u�����h�ɂ���
    SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;

    // �w�i��`��
    DrawGraph( 0 , 0 , BackHandle , FALSE ) ;

    // �`��u�����h���[�h�����Z�u�����h�i�W�O���j�ɂ���
    SetDrawBlendMode( DX_BLENDMODE_SUB , 204 ) ;

    // ��ɍڂ���O���t�B�b�N��`��
    DrawGraph( 255 , 0 , TestHandle , TRUE ) ;

    // �L�[�҂�((7-3)�wWaitKey�x���g�p)
    WaitKey() ;



    // �`��u�����h���[�h���m�[�u�����h�ɂ���
    SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;

    // �w�i��`��
    DrawGraph( 0 , 0 , BackHandle , FALSE ) ;

    // �`��u�����h���[�h����Z�u�����h�ɂ���
    SetDrawBlendMode( DX_BLENDMODE_MUL , 0 ) ;

    // ��ɍڂ���O���t�B�b�N��`��
    DrawGraph( 255 , 0 , TestHandle , TRUE ) ;

    // �L�[�҂�((7-3)�wWaitKey�x���g�p)
    WaitKey() ;


    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( TestHandle ) ;
    DeleteGraph( BackHandle ) ;


    DxLib_End() ;    // �c�w���C�u�����g�p�̏I������

    return 0 ;    // �\�t�g�̏I��
}
