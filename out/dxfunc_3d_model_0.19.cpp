#include "DxLib.h"

int main()
{
    int ModelHandle ;
    int PosX, PosZ, PosY ;

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

    // ���W�����Z�b�g
    PosX = 0 ;
    PosY = 0 ;
    PosZ = 0 ;

    // �E�C���h�E��������܂Ń��[�v
    while( ProcessMessage() == 0 )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // �L�[�{�[�h�̏㉺���E�Ń��f���̍��W��ύX
        // ( �V�t�g�L�[�������Ȃ���㉺�L�[�Ń��f�����㉺�Ɉړ� )
        if( CheckHitKey( KEY_INPUT_LSHIFT ) )
        {
            if( CheckHitKey( KEY_INPUT_DOWN  ) ) PosY -- ;
            if( CheckHitKey( KEY_INPUT_UP    ) ) PosY ++ ;
        }
        else
        {
            if( CheckHitKey( KEY_INPUT_LEFT  ) ) PosX -- ;
            if( CheckHitKey( KEY_INPUT_RIGHT ) ) PosX ++ ;
            if( CheckHitKey( KEY_INPUT_DOWN  ) ) PosZ -- ;
            if( CheckHitKey( KEY_INPUT_UP    ) ) PosZ ++ ;
        }

        // ���f���̍��W���Z�b�g
        MV1SetPosition( ModelHandle, VGet( PosX * 0.5f, PosY * 0.5f, PosZ * 0.5f ) ) ;

        // �������Z���U�O���̂P�b�o�߂����Ƃ����z��Ŏ��s
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
