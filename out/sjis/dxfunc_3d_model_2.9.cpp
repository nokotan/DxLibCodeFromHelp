#include "DxLib.h"

int main()
{
    int ModelHandle, Time, UseMatrix ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // ���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;

    // ���f����������ʒu�Ɉړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, 240.0f, 800.0f ) ) ;

    // �s����g�p���邩�ǂ����̃t���O���P�ɂ���
    UseMatrix = 1 ;

    // ���݂̃^�C���J�E���g���L�^���Ă���
    Time = GetNowCount() ;

    // �����L�[���������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // �P�b�o���ɓƎ��̍s����g�p���邩�ǂ�����ύX����
        if( GetNowCount() - Time > 1000 )
        {
            // �t���O�ɂ���ď����𕪊�
            if( UseMatrix == 1 )
            {
                // �Q�Ԗڂ̃t���[���ɉ��ɓ����̃��[�J���s����Z�b�g����
                MV1SetFrameUserLocalMatrix( ModelHandle, 2, MGetTranslate( VGet( 0.0f, -300.0f, 0.0f ) ) ) ;

                // �t���O���O�ɂ���
                UseMatrix = 0 ;
            }
            else
            {
                // �Q�Ԗڂ̃t���[���ɐݒ肵���s��𖳌�������
                MV1ResetFrameUserLocalMatrix( ModelHandle, 2 ) ;

                // �t���O���P�ɂ���
                UseMatrix = 1 ;
            }

            // ���݂̃^�C���J�E���g���L�^���Ă���
            Time = GetNowCount() ;
        }

        // ���f����`��
        MV1DrawModel( ModelHandle ) ;
    }

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
