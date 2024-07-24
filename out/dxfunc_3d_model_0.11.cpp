#include "DxLib.h"

int main()
{
    int ModelHandle, SubModelHandle ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // ModelHandle �Ɠ������f�����g�p���郂�f���̍쐬
    SubModelHandle = MV1DuplicateModel( ModelHandle ) ;

    // ��ʂɉf��ʒu�ɂR�c���f�����ړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, 0.0f, 600.0f ) ) ;

    // �R�c���f���̊g�嗦���O�D�T�{�ɂ���
    MV1SetScale( ModelHandle, VGet( 0.5f, 0.5f, 0.5f ) ) ;

    // ModelHandle �ɐݒ肵�����W�ϊ��p�����[�^�̌��ʂ̍s��� SubModelHandle �̍��W�ϊ��s��Ƃ��Đݒ肷��
    MV1SetMatrix( SubModelHandle, MV1GetMatrix( ModelHandle ) ) ;

    // SubModelHandle �̕��̂R�c���f����`��
    MV1DrawModel( SubModelHandle ) ;

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;
    MV1DeleteModel( SubModelHandle ) ;

    // �L�[�̓��͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
