#include "DxLib.h"

int main()
{
    int LightHandle, ModelHandle ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;

    // ���C�g�n���h���̃��C�g�̌��ʂ��킩��Ղ��悤�ɕW�����C�g�𖳌���
    SetLightEnable( FALSE ) ;

    // �f�B���N�V���i���^�C�v�̃��C�g�n���h�����쐬
    LightHandle = CreateDirLightHandle( VGet( 1.0f, -1.0f, 1.0f ) ) ;

    // ���C�g�n���h���̃f�B�t���[�Y�J���[��F�ɂ���
    SetLightDifColorHandle( LightHandle, GetColorF( 0.0f, 0.0f, 1.0f, 0.0f ) ) ;

    // ��ʂɉf��ʒu�ɂR�c���f�����ړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, 240.0f, 600.0f ) ) ;

    // �R�c���f���̕`��
    MV1DrawModel( ModelHandle ) ;

    // ���C�g�n���h���̍폜
    DeleteLightHandle( LightHandle ) ;

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
