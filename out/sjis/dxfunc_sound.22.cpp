#include "DxLib.h"

int main()
{
	int SoundHandle ;
	VECTOR ListenerPos ;
	VECTOR ListenerDir ;

	// �P���[�g���ɑ�������l��ݒ肷��
	Set3DSoundOneMetre( 16.0f ) ;

	// �c�w���C�u�����̏�����
	if( DxLib_Init() < 0 ) return -1;

	// �`���𗠉�ʂɂ���
	SetDrawScreen( DX_SCREEN_BACK );

	// ���X�i�[�̈ʒu��������
	ListenerPos = VGet( 320.0f, 0.0f, 240.0f ) ;

	// ���X�i�[�̌�����������
	ListenerDir.x = 0.0f ;
	ListenerDir.y = 0.0f ;
	ListenerDir.z = 1.0f ;

	// ���X�i�[�̈ʒu�ƌ�����ݒ�
	Set3DSoundListenerPosAndFrontPos_UpVecY( ListenerPos, VAdd( ListenerPos, ListenerDir ) ) ;

	// �����R�c�T�E���h�Ƃ��ēǂݍ���
	SetCreate3DSoundFlag( TRUE ) ;
	SoundHandle = LoadSoundMem( "Test.wav" ) ;
	SetCreate3DSoundFlag( FALSE ) ;

	// �����������鋗����ݒ肷��
	Set3DRadiusSoundMem( 256.0f, SoundHandle ) ;

	// ����炷�ʒu��ݒ肷��
	Set3DPositionSoundMem( VGet( 320.0f, 0.0f, 300.0f ), SoundHandle ) ;

	// ���o�[�u�G�t�F�N�g�p�����[�^���v���Z�b�g�u�u���v���g�p���Đݒ�
	Set3DPresetReverbParamSoundMem( DX_REVERB_PRESET_AUDITORIUM, SoundHandle ) ;

	// �����Đ����J�n
	PlaySoundMem( SoundHandle, DX_PLAYTYPE_LOOP ) ;

	// �����L�[���������܂ő҂�
	WaitKey() ;

	// �T�E���h�n���h���̍폜
	DeleteSoundMem( SoundHandle ) ;

	// �c�w���C�u�����̌�n��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}
