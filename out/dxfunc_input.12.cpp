#include "DxLib.h"

int main()
{
    int Cr ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // ���F�̒l���擾
    Cr = GetColor( 255 , 255 , 255 ) ;

    // ������̕`��
    DrawString( 200 , 240 - 32 , "�L�[�������Ă�������" , Cr );

    // �L�[�̓��͑҂�
    while( CheckHitKeyAll() == 0 )
    {
        // ���b�Z�[�W����
        if( ProcessMessage() == -1 )
        {
             break ;    // �G���[�����������烋�[�v�𔲂���
        }
    }

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
