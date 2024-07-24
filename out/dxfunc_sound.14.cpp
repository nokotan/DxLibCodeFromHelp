#include "DxLib.h"

int main()
{
    int SHandle, DupSHandle ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // test.wav�̃������ւ̓ǂݍ��݃T�E���h�n���h����SHandle�ɕۑ����܂�
    SHandle = LoadSoundMem( "test.wav" ) ;

    // test.wav���g�p���� SHandle �Ƃ͕ʂ̃T�E���h�n���h�����쐬����
    DupSHandle = DuplicateSoundMem( SHandle ) ;

    // �ǂ݂��񂾉����m�[�}���Đ����܂�(�wPlaySoundMem�x�֐��g�p)
    PlaySoundMem( SHandle , DX_PLAYTYPE_NORMAL ) ;

    // SHandle ���畡������ DupSHandle ���m�[�}���Đ����܂�
    PlaySoundMem( DupSHandle , DX_PLAYTYPE_NORMAL ) ;

    // �T�E���h�n���h���̍폜
    DeleteSoundMem( SHandle ) ;
    DeleteSoundMem( DupSHandle ) ;

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
