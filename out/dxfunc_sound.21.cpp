#include "DxLib.h"

int main()
{
	SOUND3D_REVERB_PARAM ReverbParam ;
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

	// ���o�[�u�G�t�F�N�g�p�����[�^��ݒ�
	ReverbParam.WetDryMix           = 100.0f ;
	ReverbParam.ReflectionsDelay    = 20 ;
	ReverbParam.ReverbDelay         = 29 ;
	ReverbParam.RearDelay           = 5 ;
	ReverbParam.PositionLeft        = 6 ;
	ReverbParam.PositionRight       = 6 ;
	ReverbParam.PositionMatrixLeft  = 27 ;
	ReverbParam.PositionMatrixRight = 27 ;
	ReverbParam.EarlyDiffusion      = 15 ;
	ReverbParam.LateDiffusion       = 15 ;
	ReverbParam.LowEQGain           = 8 ;
	ReverbParam.LowEQCutoff         = 4 ;
	ReverbParam.HighEQGain          = 8 ;
	ReverbParam.HighEQCutoff        = 6 ;
	ReverbParam.RoomFilterFreq      = 5000.0f ;
	ReverbParam.RoomFilterMain      = -10.0f ;
	ReverbParam.RoomFilterHF        = -5.0f ;
	ReverbParam.ReflectionsGain     = -12.3f ;
	ReverbParam.ReverbGain          = -0.02f ;
	ReverbParam.DecayTime           = 3.9200001f ;
	ReverbParam.Density             = 100.0f ;
	ReverbParam.RoomSize            = 100.0f ;
	Set3DReverbParamSoundMem( &ReverbParam, SoundHandle ) ;

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
