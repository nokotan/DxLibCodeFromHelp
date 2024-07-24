#include "DxLib.h"
#include <math.h>

#define MOVE_SPEED		4.0f
#define ANGLE_SPEED		0.1f

int main()
{
	int SoundHandle ;
	VECTOR EmitterPos ;
	VECTOR ListenerVel ;
	VECTOR ListenerPos ;
	VECTOR ListenerBackPos ;
	VECTOR ListenerDir ;
	float ListenerAngle ;

	// �P���[�g���ɑ�������l��ݒ肷��
	Set3DSoundOneMetre( 16.0f ) ;

	// �c�w���C�u�����̏�����
	if( DxLib_Init() < 0 ) return -1;

	// �`���𗠉�ʂɂ���
	SetDrawScreen( DX_SCREEN_BACK );

	// ���X�i�[�̈ʒu��������
	ListenerPos = VGet( 320.0f, 0.0f, 40.0f ) ;

	// ���X�i�[�̌�����������
	ListenerAngle = DX_PI_F / 2.0f ;
	ListenerDir.x = cos( ListenerAngle ) ;
	ListenerDir.y = 0.0f ;
	ListenerDir.z = sin( ListenerAngle ) ;

	// ���X�i�[�̈ʒu�ƌ�����ݒ�
	Set3DSoundListenerPosAndFrontPos_UpVecY( ListenerPos, VAdd( ListenerPos, ListenerDir ) ) ;

	// �����R�c�T�E���h�Ƃ��ēǂݍ���
	SetCreate3DSoundFlag( TRUE ) ;
	SoundHandle = LoadSoundMem( "Test.wav" ) ;
	SetCreate3DSoundFlag( FALSE ) ;

	// �����������鋗����ݒ肷��
	Set3DRadiusSoundMem( 256.0f, SoundHandle ) ;

	// ���̍Đ��ʒu��������
	EmitterPos = VGet( 320.0f, 0.0f, 240.0f ) ;

	// ���̍Đ��ʒu��ݒ�
	Set3DPositionSoundMem( EmitterPos, SoundHandle ) ;

	// ���̍Đ����J�n
	PlaySoundMem( SoundHandle, DX_PLAYTYPE_LOOP ) ;

	// ���C�����[�v
	while( ProcessMessage() == 0 )
	{
		// ��ʂ̃N���A
		ClearDrawScreen();

		// �ړ��O�̃��X�i�[�̈ʒu��ۑ�
		ListenerBackPos = ListenerPos ;

		// �����L�[�Ń��X�i�[�̈ʒu���ړ�
		if( CheckHitKey( KEY_INPUT_LEFT ) == 1 )
		{
			ListenerPos.x -= MOVE_SPEED ;
		}

		if( CheckHitKey( KEY_INPUT_RIGHT ) == 1 )
		{
			ListenerPos.x += MOVE_SPEED ;
		}

		if( CheckHitKey( KEY_INPUT_UP ) == 1 )
		{
			ListenerPos.z += MOVE_SPEED ;
		}

		if( CheckHitKey( KEY_INPUT_DOWN ) == 1 )
		{
			ListenerPos.z -= MOVE_SPEED ;
		}

		// �y�w�L�[�Ō�����ύX
		if( CheckHitKey( KEY_INPUT_Z ) == 1 )
		{
			ListenerAngle += ANGLE_SPEED ;
			if( ListenerAngle > DX_PI_F )
			{
				ListenerAngle -= DX_TWO_PI_F ;
			}
		}

		if( CheckHitKey( KEY_INPUT_X ) == 1 )
		{
			ListenerAngle -= ANGLE_SPEED ;
			if( ListenerAngle < -DX_PI_F )
			{
				ListenerAngle += DX_TWO_PI_F ;
			}
		}

		// ���̃t���[���̃��X�i�[�̈ړ���������ړ����x���Z�o
		// ( �U�O���̂P�b�o�߂��Ă���O��̌v�Z�ł� )
		ListenerVel = VScale( VSub( ListenerPos, ListenerBackPos ), 60.0f ) ;

		// ���X�i�[�̈ړ����x��ݒ�
		Set3DSoundListenerVelocity( ListenerVel ) ;

		// ���X�i�[�̈ʒu�ƌ�����ݒ�
		ListenerDir.x = cos( ListenerAngle ) ;
		ListenerDir.y = 0.0f ;
		ListenerDir.z = sin( ListenerAngle ) ;
		Set3DSoundListenerPosAndFrontPos_UpVecY( ListenerPos, VAdd( ListenerPos, ListenerDir ) ) ;

		// ���X�i�[�̈ʒu��`��
		DrawBox(
			( int )( ListenerPos.x - 8 ), ( int )( 480.0f - ( ListenerPos.z + 8 ) ),
			( int )( ListenerPos.x + 8 ), ( int )( 480.0f - ( ListenerPos.z - 8 ) ),
			GetColor( 255,0,0 ),   TRUE ) ; 

		// ���X�i�[�̌�����`��
		DrawLine(
			( int )           ListenerPos.x,
			( int )( 480.0f - ListenerPos.z ),
			( int )(            ListenerPos.x + ListenerDir.x * 40.0f ),
			( int )( 480.0f - ( ListenerPos.z + ListenerDir.z * 40.0f ) ),
			GetColor( 255,255,255 ) ) ; 

		// ���̍Đ��ʒu��`��
		DrawBox(
			( int )( EmitterPos.x - 8 ), ( int )( 480.0f - ( EmitterPos.z + 8 ) ),
			( int )( EmitterPos.x + 8 ), ( int )( 480.0f - ( EmitterPos.z - 8 ) ),
			GetColor( 255,0,255 ), TRUE ) ; 

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
