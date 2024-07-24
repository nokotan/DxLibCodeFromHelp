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
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // ��ʂɉf��ʒu�ɂR�c���f�����ړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, 0.0f, 600.0f ) ) ;

    // �R�c���f���̂y������ʍ�������Ɍ�����
    // ( DxChara.x �͂y���̃}�C�i�X�����Ɍ����Ă���̂ŉE�������ɌX���܂� )
    MV1SetRotationZYAxis( ModelHandle, VGet( -0.5f, 0.5f, 0.0f ), VGet( 0.5f, 0.5f, 0.0f ), 0.0f ) ;

    // �R�c���f����`��
    MV1DrawModel( ModelHandle ) ;

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // �L�[�̓��͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
