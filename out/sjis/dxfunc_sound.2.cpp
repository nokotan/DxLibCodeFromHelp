#include "DxLib.h"

int main()
{
    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // test.wav�̃��[�v�Đ�
    PlaySoundFile( "test.wav" , DX_PLAYTYPE_LOOP ) ;

    // �T�b�҂wWaitTimer�x�g�p
    WaitTimer( 5000 ) ;

    // �Đ����~�߂܂�
    StopSoundFile() ;

    // �L�[���͂�����܂ő҂��܂�(�wWaitKey�x�g�p)
    WaitKey() ;

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
