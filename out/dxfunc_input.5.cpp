#include "DxLib.h"

int main()
{
    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // �}�E�X��\����Ԃɂ���
    SetMouseDispFlag( TRUE ) ;

    // �L�[���͂�҂�(�wWaitKey�x���g�p)
    WaitKey() ;

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
