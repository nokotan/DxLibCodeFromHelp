#include "DxLib.h"

int main()
{
    unsigned int Cr ;

    if( DxLib_Init() == -1 )            // �c�w���C�u��������������
    {
         return -1;            // �G���[���N�����璼���ɏI��
    }

    Cr = GetColor(   0 ,   0 , 255 ) ;        // �F�̒l���擾

    DrawBoxAA( 0.0f , 0.0f , 640.0f , 480.0f , Cr , TRUE) ;    // �l�p�`��`��

    WaitKey() ;                // �L�[�̓��͑҂�(�wWaitKey�x���g�p)

    DxLib_End() ;                // �c�w���C�u�����g�p�̏I������

    return 0 ;                // �\�t�g�̏I��
}