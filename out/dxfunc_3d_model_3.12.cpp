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
    ModelHandle = MV1LoadModel( "SimpleModelVertexColor.mqo" ) ;

    // ��ʂɉf��ʒu�ɂR�c���f�����ړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, 300.0f, 600.0f ) ) ;

    // �R�c���f���̕`��
    MV1DrawModel( ModelHandle ) ;

    // �L�[�̓��͑҂�
    WaitKey() ;

    // ��ʂ��N���A
    ClearDrawScreen() ;

    // �R�Ԗڂ̃��b�V���̒��_�f�B�t���[�Y�J���[���g�p����ݒ�ɕύX����
    MV1SetMeshUseVertDifColor( ModelHandle, 3, TRUE ) ;

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
