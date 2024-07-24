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

	// ���E���݂ɉ���炷
	while( ProcessMessage() == 0 )
	{
		// �����̃X�s�[�J�[���特��炷
		ChangeNextPlayPanSoundMem( -255, SoundHandle ) ;
		PlaySoundMem( SoundHandle, DX_PLAYTYPE_BACK ) ;

		// �O�D�P�T�b�҂�
		WaitTimer( 150 ) ;

		// �E���̃X�s�[�J�[���特��炷
		ChangeNextPlayPanSoundMem( 255, SoundHandle ) ;
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
