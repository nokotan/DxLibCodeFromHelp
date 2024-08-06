#include "DxLib.h"

#define MIN_RADIUS		(100.0f)
#define MAX_RADIUS		(480.0f)

int main()
{
	int SoundHandle ;
	VECTOR EmitterPos ;
	VECTOR ListenerPos ;
	VECTOR ListenerDir ;
	float Radius ;
	float AddRadius ;

	// �P���[�g���ɑ�������l��ݒ肷��
	Set3DSoundOneMetre( 16.0f ) ;

	// �c�w���C�u�����̏�����
	if( DxLib_Init() < 0 ) return -1;

	// �`���𗠉�ʂɂ���
	SetDrawScreen( DX_SCREEN_BACK );

	// ���X�i�[�̈ʒu��������
	ListenerPos = VGet( 320.0f, 0.0f, 360.0f ) ;

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

	// ���̍Đ��ʒu��������
	EmitterPos = VGet( 320.0f, 0.0f, 120.0f ) ;

	// ���̍Đ��ʒu��ݒ�
	Set3DPositionSoundMem( EmitterPos, SoundHandle ) ;

	// �����������鋗����������
	Radius = MIN_RADIUS ;
	AddRadius = 4.0f ;
	Set3DRadiusSoundMem( Radius, SoundHandle ) ;

	// ���̍Đ����J�n
	PlaySoundMem( SoundHandle, DX_PLAYTYPE_LOOP ) ;

	// ���C�����[�v
	while( ProcessMessage() == 0 )
	{
		// ��ʂ̃N���A
		ClearDrawScreen();

		// �����������鋗����ύX
		Radius += AddRadius ;
		if( Radius > MAX_RADIUS || Radius < MIN_RADIUS )
		{
			AddRadius = -AddRadius ;
			Radius += AddRadius ;
		}
		Set3DRadiusSoundMem( Radius, SoundHandle ) ;

		// ���X�i�[�̈ʒu��`��
		DrawBox(
			( int )( ListenerPos.x - 8 ), ( int )( 480.0f - ( ListenerPos.z + 8 ) ),
			( int )( ListenerPos.x + 8 ), ( int )( 480.0f - ( ListenerPos.z - 8 ) ),
			GetColor( 255,0,0 ),   TRUE ) ; 

		// ���̍Đ��ʒu��`��
		DrawBox(
			( int )( EmitterPos.x - 8 ), ( int )( 480.0f - ( EmitterPos.z + 8 ) ),
			( int )( EmitterPos.x + 8 ), ( int )( 480.0f - ( EmitterPos.z - 8 ) ),
			GetColor( 255,0,255 ), TRUE ) ; 

		// ������������͈͂�`��
		DrawCircle( ( int )EmitterPos.x, ( int )EmitterPos.z, ( int )Radius, GetColor( 255,255,0 ), FALSE ) ;

		// ����ʂ̓��e��\��ʂɔ��f
		ScreenFlip() ;
	}

	// �T�E���h�n���h���̍폜
	DeleteSoundMem( SoundHandle ) ;

	// �c�w���C�u�����̌�n��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}
