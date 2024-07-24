#include "DxLib.h"

int main()
{
    int SoundHandle ;

    // �c�w���C�u��������������
    if( DxLib_Init() == -1 ) return -1;

    // �Đ��`�����t�@�C������X�g���[���Đ�����A�ɐݒ�
    SetCreateSoundDataType( DX_SOUNDDATATYPE_FILE ) ;

    // BGM.wav ��ǂݍ��݁A�n���h�����擾����
    SoundHandle = LoadSoundMem( "BGM.wav" ) ;

    // �Đ�
    PlaySoundMem( SoundHandle, DX_PLAYTYPE_LOOP ) ;

    // �����L�[���������܂ő҂�
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 ){}

    // �T�E���h�n���h���̍폜
    DeleteSoundMem( SoundHandle ) ;

    // �c�w���C�u�����g�p�̏I������
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
