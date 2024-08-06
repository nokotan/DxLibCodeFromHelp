#include "DxLib.h"

int main()
{
    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �f�t�H���g�̐ݒ�łR�c��ԏ�ɋ���`�悷��
    DrawSphere3D( VGet( 160.0f, 200.0f, 0.0f ), 80.0f, 32, GetColor( 128,0,0 ), GetColor( 255,255,255 ), TRUE ) ;

    // �y�o�b�t�@��L���ɂ���
    SetUseZBuffer3D( TRUE ) ;

    // �y�o�b�t�@�ւ̏������݂�L���ɂ���
    SetWriteZBuffer3D( TRUE ) ;

    // �y�o�b�t�@��L���ɂ�����Ԃōēx�R�c��ԏ�ɋ���`�悷��
    DrawSphere3D( VGet( 480.0f, 200.0f, 0.0f ), 80.0f, 32, GetColor( 128,0,0 ), GetColor( 255,255,255 ), TRUE ) ;

    // �L�[���͑҂�������
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
