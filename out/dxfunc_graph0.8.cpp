#include "DxLib.h"

int main()
{
    unsigned int Cr ;

    // �c�w���C�u����������
    if( DxLib_Init() == -1 ) return -1;

    // ���F�̒l���擾
    Cr = GetColor( 255 , 255 , 0 ) ;

    // �O�p�`��`��
    DrawTriangle( 320, 100, 160, 420, 480, 420, Cr, TRUE ) ;

    // �L�[�̓��͑҂�((7-3)�wWaitKey�x���g�p)
    WaitKey() ;

    // �c�w���C�u�����g�p�̏I������
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
