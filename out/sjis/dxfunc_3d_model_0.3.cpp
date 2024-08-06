#include "DxLib.h"

int main()
{
    int ModelHandle, AttachIndex ;
    float TotalTime, PlayTime ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // ���ɓǂݍ��ރ��f���̕������Z���[�h�����A���^�C���������Z�ɂ���
    MV1SetLoadModelUsePhysicsMode( DX_LOADMODEL_PHYSICS_REALTIME ) ;

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "Test.pmd" ) ;

    // �`���𗠉�ʂɕύX
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // �J�����ɉf��͈�( �J��������̋����͈̔� )��ݒ�
    SetCameraNearFar( 10.0f, 1000.0f ) ;

    // �J�����̈ʒu�ƌ�����ݒ�
    SetCameraPositionAndTarget_UpVecY( VGet( 0.0f, 19.0f, -22.5f ), VGet( 0.0f, 10.0f, 0.0f ) ) ;

    // �R�c���f���̂O�Ԗڂ̃A�j���[�V�������A�^�b�`����
    AttachIndex = MV1AttachAnim( ModelHandle, 0, -1, FALSE ) ;

    // �A�^�b�`�����A�j���[�V�����̑��Đ����Ԃ��擾����
    TotalTime = MV1GetAttachAnimTotalTime( ModelHandle, AttachIndex ) ;

    // �������Z�̏�Ԃ����Z�b�g
    MV1PhysicsResetState( ModelHandle ) ;

    // �Đ����Ԃ̏�����
    PlayTime = 0.0f ;

    // �����L�[��������邩�E�C���h�E��������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // �Đ����Ԃ�i�߂�
        PlayTime += 0.5f ;

        // �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ��O�ɖ߂�
        if( PlayTime >= TotalTime )
        {
            PlayTime = 0.0f ;

            // �Đ����Ԃ��Z�b�g����
            MV1SetAttachAnimTime( ModelHandle, AttachIndex, PlayTime ) ;

            // ���[�V���������[�v�����Ƃ��Ɉʒu���ړ����邱�Ƃ�����̂ŕ������Z�̏�Ԃ����Z�b�g
            MV1PhysicsResetState( ModelHandle ) ;
        }
        else
        {
            // �Đ����Ԃ��Z�b�g����
            MV1SetAttachAnimTime( ModelHandle, AttachIndex, PlayTime ) ;
        }

        // �������Z���U�O���̂P�b�o�߂����Ƃ����ݒ�Ŏ��s
        MV1PhysicsCalculation( ModelHandle, 1000.0f / 60.0f ) ;

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
