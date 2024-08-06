#include "DxLib.h"

int main()
{
    int ModelHandle ;
    float Rotate ;
    MATRIX Matrix ;

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

    // �J�����̉�]�l��������
    Rotate = 0.0f ;

    // �d�r�b�L�[��������邩�E�C���h�E��������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // ���E�L�[�ŃJ�����̉�]�l��ύX
        if( CheckHitKey( KEY_INPUT_LEFT ) == 1 )
        {
            Rotate -= DX_PI_F / 60.0f ;
        }
        if( CheckHitKey( KEY_INPUT_RIGHT ) == 1 )
        {
            Rotate += DX_PI_F / 60.0f ;
        }

        // ��]�l���g�p���Ăx���̉�]�s����쐬
        Matrix = MGetRotY( Rotate ) ;

        // ��]�s����r���[�s��Ƃ��ăZ�b�g
        SetCameraViewMatrix( Matrix ) ;

        // ���f�����J�������͂ނ悤�ɂS�`��
        MV1SetPosition( ModelHandle, VGet( 0.0f, 0.0f, 800.0f ) ) ;
        MV1DrawModel( ModelHandle ) ;

        MV1SetPosition( ModelHandle, VGet( 0.0f, 0.0f, -800.0f ) ) ;
        MV1DrawModel( ModelHandle ) ;

        MV1SetPosition( ModelHandle, VGet( 800.0f, 0.0f, 0.0f ) ) ;
        MV1DrawModel( ModelHandle ) ;

        MV1SetPosition( ModelHandle, VGet( -800.0f, 0.0f, 0.0f ) ) ;
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
