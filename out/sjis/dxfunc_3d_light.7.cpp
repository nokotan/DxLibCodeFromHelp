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

    // �X�y�L�����J���[�̕ω����킩��₷���悤�ɕW�����C�g�̃f�B�t���[�Y�J���[��^�����ɂ���
    SetLightDifColor( GetColorF( 0.0f, 0.0f, 0.0f, 0.0f ) ) ;

    // �W�����C�g�̃X�y�L�����J���[�����F�ɂ���
    SetLightSpcColor( GetColorF( 1.0f, 1.0f, 0.0f, 0.0f ) ) ;

    // ���f�����J�����̉f��ʒu�Ɉړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, 240.0f, 300.0f ) ) ;

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
