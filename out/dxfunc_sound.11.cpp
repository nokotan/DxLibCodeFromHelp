#include "DxLib.h"

int main()
{
	int SoundHandle ;

	// �c�w���C�u�����̏�����
	if( DxLib_Init() == -1 )
	{
		return -1 ;
	}

	// ���̓ǂݍ���
	SoundHandle = LoadSoundMem( "Test.wav" ) ;

	// �u�ʏ퉹�ʂŉ����Đ��v�Ɓu�����ʂŉ����Đ��v�����݂ɍs��
	while( ProcessMessage() == 0 )
	{
		// �ʏ퉹�ʂŉ����Đ�����
		ChangeNextPlayVolumeSoundMem( 255, SoundHandle ) ;
		PlaySoundMem( SoundHandle, DX_PLAYTYPE_BACK ) ;

		// �O�D�P�T�b�҂�
		WaitTimer( 150 ) ;

		// �����ʂŉ����Đ�����
		ChangeNextPlayVolumeSoundMem( 128, SoundHandle ) ;
		PlaySoundMem( SoundHandle, DX_PLAYTYPE_BACK ) ;

		// �O�D�P�T�b�҂�
		WaitTimer( 150 ) ;
	}

	// �T�E���h�n���h���̍폜
	DeleteSoundMem( SoundHandle ) ;

	// �c�w���C�u�����̌�n��
	DxLib_End() ;

	// �\�t�g�̏I��
	return 0 ;
}
