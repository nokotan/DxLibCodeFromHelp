#include "DxLib.h"

int main()
{
    // �c�w���C�u��������������
    if( DxLib_Init() == -1 )
         return -1;    // �G���[���N�����璼���ɏI��

    // �U���J�n
    StartJoypadVibration( DX_INPUT_PAD1, 1000, 2000, -1 ) ;

    // �Q�b�Ԍo�߂���܂ő҂�
    WaitTimer( 2000 ) ;

    // �c�w���C�u�����g�p�̏I������
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
