#include "DxLib.h"

int main()
{
    VECTOR Position ;
    VECTOR BoxPos1, BoxPos2 ;
    float XAdd ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �`���𗠉�ʂɂ���
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // �y�o�b�t�@���g�p����
    SetUseZBuffer3D( TRUE ) ;

    // �y�o�b�t�@�ւ̏������݂��s��
    SetWriteZBuffer3D( TRUE ) ; 

    // ��щ��{�b�N�X�̍��W��������
    Position = VGet( 320, 240, 0.0f ) ;

    // ��щ��{�b�N�X�̂w���̈ړ����x���Z�b�g
    XAdd = 8.0f ;

    // �d�r�b�L�[��������邩�E�C���h�E��������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // ��ʂ�������
        ClearDrawScreen() ;

        // �{�b�N�X�̍��W���X�V
        Position.x += XAdd ;

        // ������ʓ�����傫���O�ꂽ������𔽓]����
        if( Position.x < -200.0f || Position.x > 840.0f )
        {
            XAdd = -XAdd ;
        }

        // �{�b�N�X�������Q�_�̍��W������
        BoxPos1 = VSub( Position, VGet( 10.0f, 10.0f, 10.0f ) ) ;
        BoxPos2 = VAdd( Position, VGet( 10.0f, 10.0f, 10.0f ) ) ;

        // ��ʓ��Ƀ{�b�N�X�������Ă��Ȃ����ǂ�����`�悷��
        if( CheckCameraViewClip_Box( BoxPos1, BoxPos2 ) == TRUE )
        {
            DrawString( 0, 0, "Screen Out:Yes", GetColor( 255,255,255 ) ) ;
        }
        else
        {
            DrawString( 0, 0, "Screen Out:No", GetColor( 255,255,255 ) ) ;
        }

        // �{�b�N�X��`�悷��
        DrawCube3D( BoxPos1, BoxPos2, GetColor( 255,255,255 ), GetColor( 0,0,0 ), TRUE ) ;

        // ����ʂ̓��e��\��ʂɔ��f
        ScreenFlip() ;
    }

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
