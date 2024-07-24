#include "DxLib.h"

int main()
{
    int SHandle[ 5 ] ;
    int i ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // test.wav�̃������ւ̓ǂݍ��݃T�E���h�n���h����SHandle�ɕۑ����܂�
    for( i = 0 ; i < 5 ; i ++ )
    {
        SHandle[ i ] = LoadSoundMem( "test.wav" ) ;
    }

    // �ǂ݂��񂾉����O�D�P�b�����Ƀo�b�N�O���E���h�Đ����܂�(�wPlaySoundMem�x�֐��g�p)
    for( i = 0 ; i < 10 ; i ++ )
    {
        // ���̍Đ�
        PlaySoundMem( SHandle[ i ] , DX_PLAYTYPE_BACK ) ;

        // �O�D�T�b�҂�(�wWaitTimer�x�g�p)
        WaitTimer( 100 ) ;
    }

    // �������ׂč폜���܂�
    InitSoundMem() ;

    // �L�[���͂�����܂ő҂��܂�(�wWaitKey�x�g�p)
    WaitKey() ;

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
