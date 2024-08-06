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

    // ���ʂ̐ݒ�
    ChangeVolumeSoundMem( 255 * 80 / 100, SHandle ) ;

    // ���̍Đ�
    PlaySoundMem( SHandle , DX_PLAYTYPE_BACK ) ;

    // �L�[���͂�����܂ő҂��܂�(�wWaitKey�x�g�p)
    WaitKey() ;

    // �T�E���h�n���h���̍폜
    DeleteSoundMem( SHandle ) ;

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
