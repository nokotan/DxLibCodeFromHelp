#include "DxLib.h"

int main()
{
    int SoundHandle ;
    int Freq , Add ;

    // �c�w���C�u��������������
    if( DxLib_Init() == -1 ) return -1;

    // �������[�h����
    SoundHandle = LoadSoundMem( "test.wav" ) ; 

    // �Đ����g���ƍĐ����g���̐��ڒl��ݒ肷��
    Freq = 22050 ;
    Add = -10 ;

    // ���[�h�������̃��[�v�Đ����J�n����
    PlaySoundMem( SoundHandle , DX_PLAYTYPE_LOOP ) ;

    // �d�r�b�L�[��������邩�A�V�X�e�����G���[���N�����܂Ń��[�v����
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 ) 
    {
        // �Đ����g���̐ݒ�l��ω�������
        Freq += Add ;
        if( Freq > 100000 ){ Freq = 100000 ; Add = -10 ; }
        if( Freq < 1000 ){ Freq = 1000  ; Add = 10 ; }

        // �Đ����g����ݒ肷��
        SetFrequencySoundMem( Freq , SoundHandle ) ; 

        // �����҂�
        WaitTimer( 10 ) ;
    }

    // �T�E���h�n���h���̍폜
    DeleteSoundMem( SoundHandle ) ;

    // �c�w���C�u�����g�p�̏I������
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
