#include "DxLib.h"

int main()
{
    unsigned int Cr ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[������������I��
    }

    // �D�F�̒l���擾
    Cr = GetColor( 128 , 128 , 128 ) ;

    // ���̕`��
    DrawLine( 120 , 150 , 300 , 240 , Cr );

    WaitKey() ;        // �L�[�̓��͑҂�(�wWaitKey�x���g�p)

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
