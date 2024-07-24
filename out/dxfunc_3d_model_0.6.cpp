#include "DxLib.h"

#define CHARA_SPACE			(300.0f)
#define CHARA_X				(250.0f)

int CharaModelHandle ;

// �L�����N�^�[���f���̕`��
void Chara_Draw( float x )
{
	int i ;

	// ��O����Q�̕`��
	for( i = 0 ; i < 2 ; i ++ )
	{
		// �擪�̃L�����𔼓����ɂ���
		MV1SetOpacityRate( CharaModelHandle, i == 0 ? 0.5f : 1.0f ) ;

		// ���W��ݒ�
		MV1SetPosition( CharaModelHandle, VGet( x, 0.0f, i * CHARA_SPACE ) ) ;

		// ���f����`��
		MV1DrawModel( CharaModelHandle ) ;
	}
}

int main()
{
	// �c�w���C�u�����̏�����
	if( DxLib_Init() < 0 )
	{
		// �G���[������������I��
		return -1 ;
	}

	// �`���𗠉�ʂɕύX
	SetDrawScreen( DX_SCREEN_BACK ) ;

	// �L�����N�^�[���f���̓ǂݍ���
	CharaModelHandle = MV1LoadModel( "DxChara.x" ) ;

	// �J�����̈ʒu�ƌ�����ݒ�
	SetCameraPositionAndTarget_UpVecY( VGet( 0.0f, 400.0f, -700.0f ), VGet( 0.0f, 400.0f, 0.0f ) );

	// �`�悷�鉜�s�������͈̔͂�ݒ�
	SetCameraNearFar( 20.0f, 5000.0f );

	// �w�i�̐F���D�F�ɕύX
	SetBackgroundColor( 128,128,128 ) ;

	// ��ʂ��N���A
	ClearDrawScreen() ;

	// ���C�����[�v
	while( ProcessMessage() == 0 )
	{
		// ��ʂ��N���A
		ClearDrawScreen() ;

		// �ʏ�̐ݒ�ŉ�ʍ����ɃL�����N�^�[��`��
		MV1SetSemiTransDrawMode( DX_SEMITRANSDRAWMODE_ALWAYS ) ;
		Chara_Draw( -CHARA_X ) ;

		// ��ʉE���ɐ�ɔ������v�f�̖����R�c���f���̂ݕ`�悷��ݒ�ŃL�����N�^�[��`�悵����A
		// �������v�f�̂���R�c���f���̂ݕ`�悷��ݒ�ŃL�����N�^�[��`�悷��
		MV1SetSemiTransDrawMode( DX_SEMITRANSDRAWMODE_NOT_SEMITRANS_ONLY ) ;
		Chara_Draw( CHARA_X ) ;

		MV1SetSemiTransDrawMode( DX_SEMITRANSDRAWMODE_SEMITRANS_ONLY ) ;
		Chara_Draw( CHARA_X ) ;

		// ����ʂ̓��e��\��ʂɔ��f
		ScreenFlip() ;
	}

	// ���f���n���h���̍폜
	MV1DeleteModel( CharaModelHandle ) ;

	// �c�w���C�u�����̌�n��
	DxLib_End() ;

	// �\�t�g�̏I��
	return 0 ;
}
