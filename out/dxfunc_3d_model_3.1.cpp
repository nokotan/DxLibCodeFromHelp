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
    MV1SetPosition( ModelHandle, VGet( 320.0f, -300.0f, 600.0f ) ) ;

    // �P�Ԃ̃��b�V���̕\����Ԃ��u��\���v�ɂ���
    MV1SetMeshVisible( ModelHandle, 1, FALSE ) ;

    // �R�c���f���̕`��
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
