#include "DxLib.h"

int main()
{
    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // test.wav�̃o�b�N�O���E���h�Đ�
    PlaySoundFile( "test.wav" , DX_PLAYTYPE_BACK ) ;

    // �Ȃ�I���܂ł����Ń��[�v
    while( CheckSoundFile() == 1 )
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
