#include "DxLib.h"

int main()
{
    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // test.mid�̃o�b�N�O���E���h���t
    PlayMusic( "test.mid" , DX_PLAYTYPE_BACK ) ;

    // ���t�I���܂ł����Ń��[�v
    while( CheckMusic() == 1 )
    {
        // ���b�Z�[�W����
        if( ProcessMessage() == -1 )
        {
            break ;    // �G���[���N�����烋�[�v�𔲂���
        }
    }

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
