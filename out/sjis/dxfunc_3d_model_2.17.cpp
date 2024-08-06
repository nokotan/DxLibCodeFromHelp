#include "DxLib.h"

int main()
{
    int ModelHandle ;
    int WaitCounter, ViewPattern ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "TexAddrTransfTest.mqo" ) ;

    // �`���𗠉�ʂɕύX
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // ��ʂɉf��ʒu�ɂR�c���f�����ړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, 240.0f, 600.0f ) ) ;

    // �`�悷��p�^�[���ƁA�`��p�^�[����ύX����Ԋu���J�E���g����ϐ��̏�����
    ViewPattern = 0 ;
    WaitCounter = 0 ;

    // �d�r�b�L�[��������邩�E�C���h�E��������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // �`�悷��p�^�[����ύX���鏈��
        WaitCounter ++ ;
        if( WaitCounter == 60 )
        {
            WaitCounter = 0 ;

            // �U�O�t���[���o�߂�����`��p�^�[����ύX
            ViewPattern ++ ;
            if( ViewPattern == 4 )
            {
                ViewPattern = 0 ;
            }
        }

        // �`�悷��p�^�[���ɉ����ăe�N�X�`�����W�̂t�l�����炷�l��ύX
        MV1SetFrameTextureAddressTransform( ModelHandle, 0, 0.25f * ViewPattern, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f ) ;

        // ���f���̕`��
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
