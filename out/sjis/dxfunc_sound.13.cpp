#include "DxLib.h"

int main()
{
    int SoundHandle ;

    // �c�w���C�u��������������
    if( DxLib_Init() == -1 ) return -1;

    // �������[�h����
    SoundHandle = LoadSoundMem( "testMusic.wav" ) ;

    // ���[�v�ʒu�����̐擪����Q�O�b��ɃZ�b�g����
    SetLoopPosSoundMem( 20000, SoundHandle ) ;

    // �������[�v�Đ�����
    PlaySoundMem( SoundHandle, DX_PLAYTYPE_LOOP ) ;

    // �L�[�̓��͑҂�
    WaitKey() ;

    // �T�E���h�n���h���̍폜
    DeleteSoundMem( SoundHandle ) ;

    // �c�w���C�u�����g�p�̏I������
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
