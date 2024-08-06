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

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "FilterTest.mqo" ) ;

    // ���f������ʂɉf��ʒu�Ɉړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, 240.0f, 400.0f ) ) ;

    // �e�N�X�`���O�Ԃ̃t�B���^�����O���[�h�� DX_DRAWMODE_NEAREST �ɕύX
    MV1SetTextureSampleFilterMode( ModelHandle, 0, DX_DRAWMODE_NEAREST ) ;

    // ���f����`�悷��
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
