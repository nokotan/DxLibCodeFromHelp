#include "DxLib.h"

int main()
{
    int MouseInput ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // �}�E�X��\����Ԃɂ���
    SetMouseDispFlag( TRUE ) ;

    // �}�E�X�̓��͂�҂�
    MouseInput = GetMouseInput() ;
    while( ( MouseInput & MOUSE_INPUT_RIGHT ) == 0 )
    {
        // ���b�Z�[�W����
        if( ProcessMessage() == -1 )
        {
            break ;    // �G���[���N�����烋�[�v���甲����
        }

        // �}�E�X�̓��͂𓾂�
        MouseInput = GetMouseInput() ;
    }

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
