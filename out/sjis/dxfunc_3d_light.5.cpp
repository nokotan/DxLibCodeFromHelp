#include "DxLib.h"

int main()
{
    int ModelHandle ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // ���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;

    // ���f�����J�����̉f��ʒu�Ɉړ�
    MV1SetPosition( ModelHandle, VGet( 0.0f, 240.0f, 600.0f ) ) ;

    // ���f����`��
    MV1DrawModel( ModelHandle ) ;

    // �W�����C�g�𖳌��ɂ���
    SetLightEnable( FALSE ) ;

    // ���f���̈ʒu��ύX
    MV1SetPosition( ModelHandle, VGet( 700.0f, 240.0f, 600.0f ) ) ;

    // ���f����`��
    MV1DrawModel( ModelHandle ) ;

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
