#include "DxLib.h"

int main()
{
    unsigned int Cr ;

    if( DxLib_Init() == -1 )                // �c�w���C�u��������������
    {
         return -1;                // �G���[���N�����璼���ɏI��
    }

    Cr = GetColor(   0 ,   0 , 255 ) ;            // �F�̒l���擾

    // �ȉ~��`��
    DrawOval( 320 , 240 , 150 , 100 ,  Cr , TRUE ) ;

    WaitKey() ;                    // �L�[�̓��͑҂�((7-3)�wWaitKey�x���g�p)

    DxLib_End() ;                    // �c�w���C�u�����g�p�̏I������

    return 0 ;                    // �\�t�g�̏I��
}
