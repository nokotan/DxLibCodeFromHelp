#include "DxLib.h"

int main()
{
    int ModelHandle ;
    float OpacityRate ;

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

    // �s�����x��������
    OpacityRate = 1.0f ;

    // ESC�L�[��������邩�E�C���h�E��������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // ��ʂ̃N���A
        ClearDrawScreen() ;

        // ��L�[�������ꂽ��s�����x���グ��
        if( CheckHitKey( KEY_INPUT_UP ) )
        {
            OpacityRate += 0.05f ;
            if( OpacityRate > 1.0f )
            {
                OpacityRate = 1.0f ;
            }
        }

        // ���L�[�������ꂽ��s�����x��������
        if( CheckHitKey( KEY_INPUT_DOWN ) )
        {
            OpacityRate -= 0.05f ;
            if( OpacityRate < 0.0f )
            {
                OpacityRate = 0.0f ;
            }
        }

        // �R�c���f���̕s�����x��ݒ肷��
        MV1SetOpacityRate( ModelHandle, OpacityRate ) ;

        // �R�c���f���̕`��
        MV1DrawModel( ModelHandle ) ;

        // ���݂̕s�����x�ƁAMV1GetSemiTransState �̖߂�l��`�悷��
        DrawFormatString( 0, 0, GetColor( 255,255,255 ),
            "ESC Key:Exit OpacityRate:%f SemiTransState:%d",
            OpacityRate, MV1GetSemiTransState( ModelHandle ) ) ;

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
