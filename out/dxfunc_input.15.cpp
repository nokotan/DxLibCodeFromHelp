#include "DxLib.h"

int main()
{
    char String[ 2 ] ;
    char InputChar ;

    // ��ʃ��[�h�̐ݒ�
    SetGraphMode( 640 , 480 , 16 ) ;

    // �c�w���C�u��������������
    if( DxLib_Init() == -1 )
    {
        // �G���[���N�����璼���ɏI��
        return -1;
    }
    
    // ���͂���镶���𐏎���ʒ����ɕ`�悵�܂�
    {
        String[ 1 ] = 0 ;

        // �d�r�b�L�[��������邩�A���炩�̓����G���[����������܂Ń��[�v����
        while( !ProcessMessage() && ( CheckHitKey( KEY_INPUT_ESCAPE ) == 0 ) )
        {
            // �������̓o�b�t�@���當�����擾����
            InputChar = GetInputChar( TRUE ) ;

            // ����R�[�h�ȊO�̕������͂��������ꍇ�̂ݕ\���������s��
            if( InputChar != 0 && InputChar >= CTRL_CODE_CMP )
            {
                // ��ʂ̏���
                ClearDrawScreen() ;

                // �����̕ۑ�
                String[ 0 ] = InputChar ;

                // �`��
                DrawString( 312 , 232 , String , GetColor( 255 , 255 , 255 )  ) ;
            }
        }
    }

    // �c�w���C�u�����g�p�̏I������
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
