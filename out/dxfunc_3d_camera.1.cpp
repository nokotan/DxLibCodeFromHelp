#include "DxLib.h"

int main()
{
    int ModelHandle ;
    VECTOR CameraPos ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // ���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;

    // �`���𗠉�ʂɂ���
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // �J�����̍��W��������
    CameraPos.x = 0.0f ;
    CameraPos.y = 0.0f ;
    CameraPos.z = -800.0f ;

    // �d�r�b�L�[��������邩�E�C���h�E��������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // �����L�[�ŃJ�����̍��W���ړ�
        if( CheckHitKey( KEY_INPUT_UP ) == 1 )
        {
            CameraPos.y += 20.0f ;
        }
        if( CheckHitKey( KEY_INPUT_DOWN ) == 1 )
        {
            CameraPos.y -= 20.0f ;
        }
        if( CheckHitKey( KEY_INPUT_LEFT ) == 1 )
        {
            CameraPos.x -= 20.0f ;
        }
        if( CheckHitKey( KEY_INPUT_RIGHT ) == 1 )
        {
            CameraPos.x += 20.0f ;
        }

        // �J�����̈ʒu�ƒ����_���Z�b�g�A�����_�͌��_
        SetCameraPositionAndTarget_UpVecY( CameraPos, VGet( 0.0f, 0.0f, 0.0f ) ) ;

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
