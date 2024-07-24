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

    // �R�c��ԏ�ɉ~����`�悷��
    DrawCone3D( VGet( 320.0f, 400.0f, 0.0f ), VGet( 320.0f, 100.0f, 0.0f ), 80.0f, 16, GetColor( 0,0,255 ), GetColor( 255,255,255 ), TRUE ) ;

    // �L�[���͑҂�������
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
