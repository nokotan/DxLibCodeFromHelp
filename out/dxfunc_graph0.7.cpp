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
    DrawOvalAA( 320.0f , 240.0f , 150.0f , 100.0f ,  Cr , TRUE ) ;

    WaitKey() ;                    // �L�[�̓��͑҂�((7-3)�wWaitKey�x���g�p)

    DxLib_End() ;                    // �c�w���C�u�����g�p�̏I������

    return 0 ;                    // �\�t�g�̏I��
}
