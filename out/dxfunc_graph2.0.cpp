#include "DxLib.h"

int main()
{
    unsigned int Cr ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // ���F�̒l���擾
    Cr = GetColor( 255 , 255 , 255 ) ;

    // ������̕`��
    DrawString( 250 , 240 - 32 , "Hello C World!" , Cr );

    WaitKey() ;        // �L�[�̓��͑҂�(�wWaitKey�x���g�p)

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
