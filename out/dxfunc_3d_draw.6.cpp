#include "DxLib.h"

int main()
{
    int GrHandle ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �摜�̓ǂݍ���
    GrHandle = LoadGraph( "Test1.bmp" ) ;

    // �R�c��ԏ�ɉ摜��`��
    DrawModiBillboard3D( VGet( 320.0f, 240.0f, 100.0f ),
        -100.0f,  200.0f,
         100.0f,  200.0f,
         100.0f, -200.0f,
        -100.0f, -200.0f, GrHandle, TRUE ) ;

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( GrHandle ) ;

    // �L�[���͑҂�������
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
