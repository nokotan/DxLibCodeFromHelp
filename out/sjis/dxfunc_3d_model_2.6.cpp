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

    // ���f���̂Q�Ԗڂ̃t���[�������q�t���[���̒����� AnkleR �Ƃ������O�̃t���[���̔ԍ����������ĉ�ʂɕ`�悷��
    DrawFormatString( 0, 0, GetColor( 255,255,255 ), "%d", MV1SearchFrameChild( ModelHandle, 2, "AnkleR" ) ) ;

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // �L�[�̓��͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
