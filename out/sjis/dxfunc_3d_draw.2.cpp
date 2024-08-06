#include "DxLib.h"

int main()
{
    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �y�o�b�t�@��L���ɂ���
    SetUseZBuffer3D( TRUE ) ;

    // �y�o�b�t�@�ւ̏������݂�L���ɂ���
    SetWriteZBuffer3D( TRUE ) ;

    // �R�c��ԏ�ɋ���`�悷��
    DrawSphere3D( VGet( 320.0f, 200.0f, 0.0f ), 80.0f, 32, GetColor( 255,0,0 ), GetColor( 255, 255, 255 ), TRUE ) ;

    // �L�[���͑҂�������
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
