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

    // �h�b�g����c�ɂQ�{�ɕύX
    SetCameraDotAspect( 0.5f ) ;

    // ���f�����J�����̉f��ʒu�Ɉړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, 240.0f, 0.0f ) ) ;

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