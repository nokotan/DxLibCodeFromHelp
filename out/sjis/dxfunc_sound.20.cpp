#include "DxLib.h"

int main()
{
	int SoundHandle ;
	VECTOR EmitterPos[ 2 ] ;
	VECTOR ListenerPos ;
	VECTOR ListenerDir ;
	int PositionNumber ;
	int FrameCounter ;
	int i ;

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

	// ���̍Đ��ʒu��������
	EmitterPos[ 0 ] = VGet( 220.0f, 0.0f, 300.0f ) ;
	EmitterPos[ 1 ] = VGet( 420.0f, 0.0f, 300.0f ) ;

	// �炷���̔ԍ���������
	PositionNumber = 0 ;

	// �t���[���J�E���^�[��������
	FrameCounter = 0 ;

	// ���C�����[�v
	while( ProcessMessage() == 0 )
	{
		// ��ʂ̃N���A
		ClearDrawScreen();

		// �t���[���J�E���^�[���C���N�������g
		FrameCounter ++ ;

		// �P�T�t���[���o�߂����特��炷
		if( FrameCounter >= 15 )
		{
			// �t���[���J�E���^�[��������
			FrameCounter = 0 ;

			// ���ɖ炷���̈ʒu��ݒ肷��
			SetNextPlay3DPositionSoundMem( EmitterPos[ PositionNumber ], SoundHandle ) ;

			// �����Đ�
			PlaySoundMem( SoundHandle, DX_PLAYTYPE_BACK ) ;

			// ����炷�ʒu�̍��W�ԍ���ύX
			PositionNumber = ( PositionNumber + 1 ) % 2 ;
		}

		// ���X�i�[�̈ʒu��`��
		DrawBox(
			( int )( ListenerPos.x - 8 ), ( int )( 480.0f - ( ListenerPos.z + 8 ) ),
			( int )( ListenerPos.x + 8 ), ( int )( 480.0f - ( ListenerPos.z - 8 ) ),
			GetColor( 255,0,0 ),   TRUE ) ; 

		// ���̍Đ��ʒu��`��
		for( i = 0 ; i < 2 ; i ++ )
		{
			DrawBox(
				( int )( EmitterPos[ i ].x - 8 ), ( int )( 480.0f - ( EmitterPos[ i ].z + 8 ) ),
				( int )( EmitterPos[ i ].x + 8 ), ( int )( 480.0f - ( EmitterPos[ i ].z - 8 ) ),
				GetColor( 255,0,255 ), TRUE ) ; 
		}

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
