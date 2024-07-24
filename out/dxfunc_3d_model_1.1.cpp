#include "DxLib.h"

int main()
{
    int ModelHandle, AttachIndex, PlayAnim ;
    float TotalTime, PlayTime ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // �`���𗠉�ʂɕύX
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // ��ʂɉf��ʒu�ɂR�c���f�����ړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, -300.0f, 600.0f ) ) ;

    // �R�c���f���̂O�Ԗڂ̃A�j���[�V�������A�^�b�`����
    AttachIndex = MV1AttachAnim( ModelHandle, 0, -1, FALSE ) ;

    // �A�^�b�`�����A�j���[�V�����̑��Đ����Ԃ��擾����
    TotalTime = MV1GetAttachAnimTotalTime( ModelHandle, AttachIndex ) ;

    // �Đ����Ԃ̏�����
    PlayTime = 0.0f ;

    // �Đ����Ă���A�j���[�V�������O�Ԃɂ���
    PlayAnim = 0 ;

    // �A�j���[�V�����O�̍Đ����I��邩�A�����L�[��������邩�E�C���h�E��������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // �Đ����Ԃ�i�߂�
        PlayTime += 100.0f ;

        // �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB�����玟�̃A�j���[�V�����ɂ���
        if( PlayTime >= TotalTime )
        {
            // �Đ����Ă���A�j���[�V�������A���܂ł��O�Ԃ�������P�ԂɁA�P�Ԃ�������O�Ԃɂ���
            if( PlayAnim == 0 )
            {
                PlayAnim = 1 ;
            }
            else
            {
                PlayAnim = 0 ;
            }

            // ���܂ŃA�^�b�`���Ă����A�j���[�V�����̃f�^�b�`
            MV1DetachAnim( ModelHandle, AttachIndex ) ;

            // �R�c���f���� PlayAnim �Ԗڂ̃A�j���[�V�������A�^�b�`����
            AttachIndex = MV1AttachAnim( ModelHandle, PlayAnim, -1, FALSE ) ;

            // �A�^�b�`�����A�j���[�V�����̑��Đ����Ԃ��擾����
            TotalTime = MV1GetAttachAnimTotalTime( ModelHandle, AttachIndex ) ;

            // �Đ����Ԃ̏�����
            PlayTime = 0.0f ;
        }

        // �Đ����Ԃ��Z�b�g����
        MV1SetAttachAnimTime( ModelHandle, AttachIndex, PlayTime ) ;

        // �R�c���f���̕`��
        MV1DrawModel( ModelHandle ) ;

        // ����ʂ̓��e��\��ʂɔ��f
        ScreenFlip() ;
    }

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
