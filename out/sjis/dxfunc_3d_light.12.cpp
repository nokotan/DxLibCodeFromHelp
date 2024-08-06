#include "DxLib.h"

int main()
{
    int ModelHandle, LightHandle ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // ���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;

    // ���ʂ��킩��Ղ��悤�ɕW�����C�g�𖳌���
    SetLightEnable( FALSE ) ;

    // �w���Ƀ}�C�i�X�����̃f�B���N�V���i���^�C�v�̃��C�g�̍쐬
    LightHandle = CreateDirLightHandle( VGet( -1.0f, 0.0f, 0.0f ) ) ;

    // ���f�����J�����̉f��ʒu�Ɉړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, 240.0f, 600.0f ) ) ;

    // ���f����`��
    MV1DrawModel( ModelHandle ) ;

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // ���C�g�n���h���̍폜
    DeleteLightHandle( LightHandle ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
