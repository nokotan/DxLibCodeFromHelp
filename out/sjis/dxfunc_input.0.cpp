#include "DxLib.h"

int main()
{
    int Cr , PadInput ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // ���F�̒l���擾
    Cr = GetColor( 255 , 255 , 255 ) ;

    // ������̕`��
    DrawString( 150 , 240 - 32 , "�p�b�h��START�{�^���������Ă�������" , Cr );

    // �p�b�h�P��9�{�^���̓��͑҂�
    PadInput = GetJoypadInputState( DX_INPUT_KEY_PAD1 ) ;
    while( ( PadInput & PAD_INPUT_9 ) == 0 )
    {
        // ���b�Z�[�W����
        if( ProcessMessage() == -1 )
        {
             break ;    // �G���[�����������烋�[�v�𔲂���
        }

        // �p�b�h�P�̓��͂��擾
        PadInput = GetJoypadInputState( DX_INPUT_KEY_PAD1 ) ;
    }

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
