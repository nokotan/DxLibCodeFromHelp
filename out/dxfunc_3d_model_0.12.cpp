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

    // �`���𗠉�ʂɕύX
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // ��ʂɉf��ʒu�ɂR�c���f�����ړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, -300.0f, 600.0f ) ) ;

    // �����L�[��������邩�E�C���h�E��������܂Ń��[�v����
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // ��ʂ��N���A����
        ClearDrawScreen() ;

        // �R�c���f�����J�E���^����b�̎��͕`�悵�āA�����\�̂Ƃ��͕`�悵�Ȃ��悤�ɂ���
        if( GetNowCount() % 2000 < 1000 )
        {
            MV1SetVisible( ModelHandle, TRUE ) ;
        }
        else
        {
            MV1SetVisible( ModelHandle, FALSE ) ;
        }

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
