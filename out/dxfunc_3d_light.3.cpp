#include "DxLib.h"

int main()
{
    int ModelHandle ;
    float Range, Atten0, Atten1, Atten2 ;

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

    // �e�p�����[�^��������
    Range = 2000.0f ;
    Atten0 = 0.0f ;
    Atten1 = 0.0006f ;
    Atten2 = 0.0f ;

    // �d�r�b�L�[��������邩�E�C���h�E��������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // �c�b�L�[�Ń��C�g�̉e���͈͂�ύX
        if( CheckHitKey( KEY_INPUT_D ) == 1 )
        {
            Range += 20.0f ;
        }
        if( CheckHitKey( KEY_INPUT_C ) == 1 )
        {
            Range -= 20.0f ;
        }

        // �e�u�L�[�Ń��C�g�̋��������p�����[�^�O�̒l��ύX
        if( CheckHitKey( KEY_INPUT_F ) == 1 )
        {
            Atten0 += 0.001f ;
        }
        if( CheckHitKey( KEY_INPUT_V ) == 1 )
        {
            Atten0 -= 0.001f ;
        }

        // �f�a�L�[�Ń��C�g�̋��������p�����[�^�P�̒l��ύX
        if( CheckHitKey( KEY_INPUT_G ) == 1 )
        {
            Atten1 += 0.00001f ;
        }
        if( CheckHitKey( KEY_INPUT_B ) == 1 )
        {
            Atten1 -= 0.00001f ;
        }

        // �g�m�L�[�Ń��C�g�̋��������p�����[�^�Q�̒l��ύX
        if( CheckHitKey( KEY_INPUT_H ) == 1 )
        {
            Atten2 += 0.0000001f ;
        }
        if( CheckHitKey( KEY_INPUT_N ) == 1 )
        {
            Atten2 -= 0.0000001f ;
        }

        // �e�������̒l��␳
        if( Range < 0.0f ) Range = 0.0f ;

        // ���������p�����[�^�̒l��␳
        if( Atten0 < 0.0f ) Atten0 = 0.0f ;
        if( Atten1 < 0.0f ) Atten1 = 0.0f ;
        if( Atten2 < 0.0f ) Atten2 = 0.0f ;

        // ���f���̏��Ƀ|�C���g���C�g��ݒ�
        ChangeLightTypePoint(
            VGet( 320.0f, 1000.0f, 200.0f ),
            Range,
            Atten0,
            Atten1,
            Atten2 ) ;

        // ���f�����J�����̉f��ʒu�Ɉړ�
        MV1SetPosition( ModelHandle, VGet( 320.0f, 240.0f, 200.0f ) ) ;

        // ���f����`��
        MV1DrawModel( ModelHandle ) ;

        // �p�����[�^�̓��e����ʂɕ\��
        DrawFormatString( 0, 0, GetColor( 255,255,255 ),  "Key:D.C  Range  %f", Range ) ;
        DrawFormatString( 0, 16, GetColor( 255,255,255 ), "Key:F.V  Atten0 %f", Atten0 ) ;
        DrawFormatString( 0, 32, GetColor( 255,255,255 ), "Key:G.B  Atten1 %f", Atten1 ) ;
        DrawFormatString( 0, 48, GetColor( 255,255,255 ), "Key:H.N  Atten2 %f / 100.0f", Atten2 * 100.0f ) ;

        // ����ʂ̓��e��\��ʂɔ��f����
        ScreenFlip() ;
    }

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
