#include "DxLib.h"
#include <stdlib.h>

int main()
{
    int Count ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // �}�E�X��\����Ԃɂ���
    SetMouseDispFlag( TRUE ) ;

    // ���݂̃J�E���^�l�𓾂�wGetNowCount�x�֐��g�p
    Count = GetNowCount() ;

    // �L�[���������܂Ń��[�v
    while( CheckHitKeyAll() == 0 )
    {
        // �O��̃J�E���^�Q�Ƃ���P�b�����Ă��邩����
        if( GetNowCount() - Count > 1000 )
        {
            // �o���Ă�����}�E�X�̈ʒu����ʍ���Ɉړ�

            // �}�E�X�̈ʒu���Z�b�g
            SetMousePoint( 0 , 0 ) ;

            // ���݂̃J�E���^�l�𓾂�
            Count = GetNowCount() ;
        }

        // ���b�Z�[�W����
        if( ProcessMessage() == -1 )
        {
            break ;    // �G���[���N�����烋�[�v�𔲂���
        }
    }

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
