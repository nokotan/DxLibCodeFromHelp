#include "DxLib.h"

int main()
{
    unsigned int Cr ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[������������I��
    }

    // �`��\�̈�Z�b�g
    SetDrawArea( 0 , 0 , 320 , 480 ) ;

    // �F�̒l���擾
    Cr = GetColor( 0 , 0 , 255 ) ;

    // ���l�p�`�̕`��
    DrawBox( 0 , 0 , 640 , 480 , Cr , TRUE ) ;

    // �L�[�҂�(�wWaitKey�x���g�p)
    WaitKey() ;

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
