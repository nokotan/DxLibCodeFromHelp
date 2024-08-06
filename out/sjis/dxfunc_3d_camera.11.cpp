#include "DxLib.h"

int main()
{
    VECTOR Position ;
    float XAdd ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �`���𗠉�ʂɂ���
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // ��щ��_�̍��W��������
    Position = VGet( 320, 240, 0.0f ) ;

    // ��щ��_�̂w���̈ړ����x���Z�b�g
    XAdd = 8.0f ;

    // �d�r�b�L�[��������邩�E�C���h�E��������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // ��ʂ�������
        ClearDrawScreen() ;

        // �_�̍��W���X�V
        Position.x += XAdd ;

        // ������ʓ�����傫���O�ꂽ������𔽓]����
        if( Position.x < -100.0f || Position.x > 740.0f )
        {
            XAdd = -XAdd ;
        }

        // ��ʓ��ɍ��W�������Ă��Ȃ����ǂ�����`�悷��
        if( CheckCameraViewClip( Position ) == TRUE )
        {
            DrawString( 0, 0, "Screen Out:Yes", GetColor( 255,255,255 ) ) ;
        }
        else
        {
            DrawString( 0, 0, "Screen Out:No", GetColor( 255,255,255 ) ) ;
        }

        // �_��`�悷��
        DrawPixel3D( Position, GetColor( 255,255,255 ) ) ;

        // ����ʂ̓��e��\��ʂɔ��f
        ScreenFlip() ;
    }

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
