#include "DxLib.h"

int main()
{
    int ModelHandle, i ;
    float Near, Far ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // ���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;

    // Near Far �l�̏�����
    Near = 100.0f ;
    Far = 2000.0f ;

    // �`���𗠉�ʂɂ���
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // �d�r�b�L�[��������邩�E�C���h�E��������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // �㉺�̃L�[���͂� Far �𑀍�
        if( CheckHitKey( KEY_INPUT_UP ) == 1 )
        {
            Far += 20.0f ;
        }
        if( CheckHitKey( KEY_INPUT_DOWN ) == 1 )
        {
            Far -= 20.0f ;
        }

        // ���E�̃L�[�� Near �𑀍�
        if( CheckHitKey( KEY_INPUT_LEFT ) == 1 )
        {
            Near -= 20.0f ;
        }
        if( CheckHitKey( KEY_INPUT_RIGHT ) == 1 )
        {
            Near += 20.0f ;
        }

        // Near �̒l�� 0.0f �ȉ��ɂȂ��Ă�����␳
        if( Near <= 0.0f ) Near = 10.0f ;

        // Far �̒l�� Near ��菬�����Ȃ��Ă�����␳
        if( Far <= Near ) Far = Near + 10.0f ;

        // Near, Far �N���b�v�̋�����ݒ�
        SetCameraNearFar( Near, Far ) ; 

        // ���f����������ς��ĂW�`��
        for( i = 0 ; i < 8 ; i ++ )
        {
            // ���f���̍��W��ݒ�
            MV1SetPosition( ModelHandle, VGet( 320.0f, 180.0f, 100.0f + i * 400.0f ) ) ;

            // ���f���̕`��
            MV1DrawModel( ModelHandle ) ;
        }

        // ��ʍ���� Near �̒l�� Far �̒l��`��
        DrawFormatString( 0, 0, GetColor( 255,255,255 ), "Near %f  Far %f", Near, Far ) ;

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
