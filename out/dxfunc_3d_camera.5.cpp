#include "DxLib.h"

int main()
{
    int ModelHandle ;
    float Fov ;

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

    // ����p��������
    Fov = 60.0f ;

    // �d�r�b�L�[��������邩�E�C���h�E��������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // ���E�L�[�Ŏ���p�̒l��ύX
        if( CheckHitKey( KEY_INPUT_LEFT ) == 1 )
        {
            Fov -= 2.0f ;
        }
        if( CheckHitKey( KEY_INPUT_RIGHT ) == 1 )
        {
            Fov += 2.0f ;
        }

        // ����p�� 8.0f �ȉ��ɂȂ�����␳
        if( Fov < 8.0f ) Fov = 8.0f ;

        // ����p�� 170.0f �ȏ�ɂȂ�����␳
        if( Fov > 170.0f ) Fov = 170.0f ;

        // ���ߖ@�̃Z�b�g�A�b�v( ���W�A���l�ɕϊ����Ă��܂� )
        SetupCamera_Perspective( Fov * DX_PI_F / 180.0f ) ;

        // �J�����̑O���Ƀ��f�����R�`��
        MV1SetPosition( ModelHandle, VGet( -1400.0f + 320.0f, 240.0f, 0.0f ) ) ;
        MV1DrawModel( ModelHandle ) ;

        MV1SetPosition( ModelHandle, VGet(     0.0f + 320.0f, 240.0f, 0.0f ) ) ;
        MV1DrawModel( ModelHandle ) ;

        MV1SetPosition( ModelHandle, VGet(  1400.0f + 320.0f, 240.0f, 0.0f ) ) ;
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
