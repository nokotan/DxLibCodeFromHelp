#include "DxLib.h"

int main()
{
    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �R�c��ԏ�ɎO�p�`��`�悷��
    DrawTriangle3D(
        VGet(100.0f,100.0f,  0.0f),
        VGet(500.0f,400.0f,  0.0f),
        VGet(600.0f,100.0f,100.0f), GetColor( 255,255,255 ), FALSE ) ;

    // �L�[���͑҂�������
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
