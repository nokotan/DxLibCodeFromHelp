#include "DxLib.h"

int main()
{
    int ModelHandle ;
    int Screen ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �`��\�ȃO���t�B�b�N�̃A���`�G�C���A�X�ݒ���s��
    SetCreateDrawValidGraphMultiSample( 4, 2 ) ;

    // �`��\�ȃO���t�B�b�N�̍쐬
    Screen = MakeScreen( 640, 480, FALSE ) ;

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // ��ʂɉf��ʒu�ɂR�c���f�����ړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, -300.0f, 600.0f ) ) ;

    // �`����`��\���O���t�B�b�N�ɐݒ�
    SetDrawScreen( Screen ) ;

    // ��ʂ�������
    ClearDrawScreen() ;

    // �R�c���f���̕`��
    MV1DrawModel( ModelHandle ) ;

    // �`���𗠉�ʂɕύX
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // �`��\�ȃO���t�B�b�N��`��
    DrawGraph( 0, 0, Screen, FALSE ) ;

    // ����ʂ̓��e��\��ʂɔ��f
    ScreenFlip() ;

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // MakeScreen �ō쐬�����O���t�B�b�N�n���h���̍폜
    DeleteGraph( Screen ) ;

    // �L�[�̓��͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
