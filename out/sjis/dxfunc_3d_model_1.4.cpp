#include "DxLib.h"

int main()
{
    int ModelHandle, AttachIndex1, AttachIndex2 ;
    float Rate ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // ��ʂ��؂�ւ��̂�������Ƒ҂�
    WaitTimer( 1000 ) ;

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // ��ʂɉf��ʒu�ɂR�c���f�����ړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, -300.0f, 600.0f ) ) ;

    // �R�c���f���̗����Ă���A�j���[�V����( �S�Ԗڂ̃A�j���[�V���� )���A�^�b�`����
    AttachIndex1 = MV1AttachAnim( ModelHandle, 4, -1, FALSE ) ;

    // �R�c���f���̎��O�ɏo���Ă���A�j���[�V����( �T�Ԗڂ̃A�j���[�V���� )���A�^�b�`����
    AttachIndex2 = MV1AttachAnim( ModelHandle, 5, -1, FALSE ) ;

    // �`���𗠉�ʂɕύX
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // �S�Ԗڂ̃A�j���[�V��������T�Ԗڂ̃A�j���[�V�����ɏ��X�Ɉڍs����
    for( Rate = 0.0f ; Rate < 1.0f ; Rate += 0.01f )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // �����Ă���A�j���[�V�����̃u�����h�����Z�b�g
        MV1SetAttachAnimBlendRate( ModelHandle, AttachIndex1, 1.0f - Rate ) ;

        // ���O�ɏo���Ă���A�j���[�V�����̃u�����h�����Z�b�g
        MV1SetAttachAnimBlendRate( ModelHandle, AttachIndex2, Rate ) ;

        // ���f���̕`��
        MV1DrawModel( ModelHandle ) ;

        // ����ʂ̓��e��\��ʂɔ��f����
        ScreenFlip() ;
    }

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
