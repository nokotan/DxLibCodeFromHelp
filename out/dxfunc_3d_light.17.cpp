#include "DxLib.h"

int main()
{
    int LightHandle[ 3 ], ModelHandle ;

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

    // �f�B���N�V���i���^�C�v�̃��C�g�n���h�����R�쐬
    LightHandle[ 0 ] = CreateDirLightHandle( VGet( 1.0f, 0.0f, 0.0f ) ) ;
    LightHandle[ 1 ] = CreateDirLightHandle( VGet( 0.0f, 1.0f, 0.0f ) ) ;
    LightHandle[ 2 ] = CreateDirLightHandle( VGet( 0.0f, 0.0f, 1.0f ) ) ;

    // �e���C�g���T�O���̊m���Ŗ����ɂ���
    if( GetRand( 99 ) >= 50 )
    {
        SetLightEnableHandle( LightHandle[ 0 ], FALSE ) ;
    }

    if( GetRand( 99 ) >= 50 )
    {
        SetLightEnableHandle( LightHandle[ 1 ], FALSE ) ;
    }

    if( GetRand( 99 ) >= 50 )
    {
        SetLightEnableHandle( LightHandle[ 2 ], FALSE ) ;
    }

    // ��ʂɉf��ʒu�ɂR�c���f�����ړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, 240.0f, 600.0f ) ) ;

    // �R�c���f���̕`��
    MV1DrawModel( ModelHandle ) ;

    // ���C�g�n���h���̍폜
    DeleteLightHandle( LightHandle[ 0 ] ) ;
    DeleteLightHandle( LightHandle[ 1 ] ) ;
    DeleteLightHandle( LightHandle[ 2 ] ) ;

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
