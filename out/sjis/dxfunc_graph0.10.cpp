#include "DxLib.h"

int main()
{
    unsigned int Cr ;

    if( DxLib_Init() == -1 )        // �c�w���C�u��������������
    {
         return -1;        // �G���[���N�����璼���ɏI��
    }

    Cr = GetColor(   0 , 255 , 0 ) ;    // �ΐF�̒l���擾

    // �_��`��
    DrawPixel( 320 , 240 , Cr ) ;

    WaitKey() ;            // �L�[�̓��͑҂�(�wWaitKey�x���g�p)

    DxLib_End() ;            // �c�w���C�u�����g�p�̏I������

    return 0 ;            // �\�t�g�̏I��
}
