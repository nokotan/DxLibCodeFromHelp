#include "DxLib.h"

int main()
{
    int SHandle ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // test.wav�̃������ւ̓ǂݍ��݃T�E���h�n���h����SHandle�ɕۑ����܂�
    SHandle = LoadSoundMem( "test.wav" ) ;

    // �ǂ݂��񂾉����o�b�N�O���E���h�Đ����܂�(�wPlaySoundMem�x�֐��g�p)
    PlaySoundMem( SHandle , DX_PLAYTYPE_BACK ) ;

    // �Ȃ�I���܂ł����Ń��[�v
    while( CheckSoundMem( SHandle ) == 1 )
    {
        // ���b�Z�[�W����
        if( ProcessMessage() == -1 )
        {
            break ;    // �G���[���N�����烋�[�v�𔲂���
        }
    }

    // �T�E���h�n���h���̍폜
    DeleteSoundMem( SHandle ) ;

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
