#include "DxLib.h"
#include <math.h>

int main()
{
    int ModelHandle ;
    float Roll ;

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

    // �J�����̎����̉�]�l��������
    Roll = 0.0f ;

    // �d�r�b�L�[��������邩�E�C���h�E��������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // ���E�L�[�ŃJ�����̉�]�l��ύX
        if( CheckHitKey( KEY_INPUT_LEFT ) == 1 )
        {
            Roll -= DX_PI_F / 60.0f ;
        }
        if( CheckHitKey( KEY_INPUT_RIGHT ) == 1 )
        {
            Roll += DX_PI_F / 60.0f ;
        }

        // �J�����̈ʒu�ƒ����_���Z�b�g
        // ���_�͂y���̃}�C�i�X800�̈ʒu
        // �����_�͌��_
        // ������� Roll �̒l����Z�o
        SetCameraPositionAndTargetAndUpVec( 
            VGet( 0.0f, 0.0f, -800.0f ),
            VGet( 0.0f, 0.0f, 0.0f ),
            VGet( sin( Roll ), cos( Roll ), 0.0f ) ) ;

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
