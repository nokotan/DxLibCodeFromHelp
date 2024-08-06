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
    ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;

    // �����ŕ`�悳��Ă���Ƃ������Ƃ�������悤�ɉ�ʑS�̂�Ԃœh��Ԃ�
    DrawBox( 0, 0, 640, 480, GetColor( 255,0,0 ), TRUE ) ;

    // ��ʂɉf��ʒu�ɂR�c���f�����ړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, 100.0f, 600.0f ) ) ;

    // �R�c���f���̂O�Ԗڂ̃��b�V���̕s�����x��50%�ɂ���
    MV1SetMeshOpacityRate( ModelHandle, 0, 0.5f ) ;

    // �R�c���f���̕`��
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
