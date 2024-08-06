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

    // �ǂ݂��񂾉������[�v�Đ����܂�(�wPlaySoundMem�x�֐��g�p)
    PlaySoundMem( SHandle , DX_PLAYTYPE_LOOP ) ;

    // �T�b�҂wWaitTimer�x�g�p
    WaitTimer( 5000 ) ;

    // ����Ȃ��Ȃ����̂ŉ����폜���܂�
    DeleteSoundMem( SHandle ) ;

    // �L�[���͂�����܂ő҂��܂�(�wWaitKey�x�g�p)
    WaitKey() ;

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}