#include "DxLib.h"

int main()
{
    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �o�b�N�J�����O�Ȃ��łR�c��ԏ�ɋ���`�悷��
    DrawSphere3D( VGet( 500.0f, 200.0f, 0.0f ), 80.0f, 8, GetColor( 255,0,0 ), GetColor( 255, 255, 255 ), TRUE ) ;

    // �o�b�N�J�����O��L���ɂ���
    SetUseBackCulling( TRUE ) ;

    // �o�b�N�J�����O����łR�c��ԏ�ɋ���`�悷��
    DrawSphere3D( VGet( 140.0f, 200.0f, 0.0f ), 80.0f, 8, GetColor( 255,0,0 ), GetColor( 255, 255, 255 ), TRUE ) ;

    // �L�[���͑҂�������
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
