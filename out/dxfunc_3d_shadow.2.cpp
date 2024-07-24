#include "DxLib.h"
#include <math.h>

int main()
{
	int StageModelHandle ;
	int CharaModelHandle ;
	int StageShadowMapHandle ;
	int CharaShadowMapHandle ;
	float Angle ;
	VECTOR CharaPosition ;

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

	// �X�e�[�W���f���̓ǂݍ���
	StageModelHandle = MV1LoadModel( "SimplePillarStage.mqo" ) ;

	// �X�e�[�W���f���p�̃V���h�E�}�b�v�n���h���̍쐬
	StageShadowMapHandle = MakeShadowMap( 2048, 2048 ) ;

	// �L�����N�^�[���f���p�̃V���h�E�}�b�v�n���h���̍쐬
	CharaShadowMapHandle = MakeShadowMap( 2048, 2048 ) ;

	// �J�����̈ʒu�ƌ�����ݒ�
	SetCameraPositionAndTarget_UpVecY( VGet( 0.0f, 1500.0f, -1500.0f ), VGet( 0.0f, 800.0f, -800.0f ) );

	// �`�悷�鉜�s�������͈̔͂�ݒ�
	SetCameraNearFar( 160.000f, 80000.000f );

	// �V���h�E�}�b�v�ɕ`�悷��͈͂�ݒ�
	SetShadowMapDrawArea( StageShadowMapHandle, VGet( -4000.0f, -1.0f, -4000.0f ), VGet( 4000.0f, 4000.0f, 4000.0f ) ) ;
	SetShadowMapDrawArea( CharaShadowMapHandle, VGet( -4000.0f, -1.0f, -4000.0f ), VGet( 4000.0f, 4000.0f, 4000.0f ) ) ;

	// ���C�g�̕�����ݒ�
	SetLightDirection( VGet( 0.5f, -0.5f, 0.5f ) );

	// �V���h�E�}�b�v���z�肷�郉�C�g�̕������Z�b�g
	SetShadowMapLightDirection( StageShadowMapHandle, VGet( 0.5f, -0.5f, 0.5f ) ) ;
	SetShadowMapLightDirection( CharaShadowMapHandle, VGet( 0.5f, -0.5f, 0.5f ) ) ;

	// �X�e�[�W���f���p�̃V���h�E�}�b�v�ւ̕`��̏���
	ShadowMap_DrawSetup( StageShadowMapHandle ) ;

	// �X�e�[�W���f���p�̃V���h�E�}�b�v�փX�e�[�W���f���̕`��
	MV1DrawModel( StageModelHandle ) ;

	// �X�e�[�W���f���p�̃V���h�E�}�b�v�ւ̕`����I��
	ShadowMap_DrawEnd() ;

	// �L�����N�^�[�̈ʒu�ƂȂ�p�x��������
	Angle = 0.0f ;

	// ���C�����[�v
	while( ProcessMessage() == 0 )
	{
		// ��ʂ��N���A
		ClearDrawScreen() ;


		// �L�����N�^�[�̈ʒu�ƂȂ�p�x��ύX
		Angle += 0.0125f ;
		if( Angle > DX_PI_F * 2.0f )
		{
			Angle -= DX_PI_F * 2.0f ;
		}

		// �L�����N�^�[�̍��W���Z�o
		CharaPosition.x = sin( Angle ) * 1000.0f ;
		CharaPosition.z = cos( Angle ) * 1000.0f ;
		CharaPosition.y = 0.0f ;

		// �L�����N�^�[���f���̍��W��ύX
		MV1SetPosition( CharaModelHandle, CharaPosition ) ;


		// �L�����N�^�[���f���p�̃V���h�E�}�b�v�ւ̕`��̏���
		ShadowMap_DrawSetup( CharaShadowMapHandle ) ;

		// �L�����N�^�[���f���p�̃V���h�E�}�b�v�փL�����N�^�[���f���̕`��
		MV1DrawModel( CharaModelHandle ) ;

		// �L�����N�^�[���f���p�̃V���h�E�}�b�v�ւ̕`����I��
		ShadowMap_DrawEnd() ;


		// �`��ɃL�����N�^�[���f���p�̃V���h�E�}�b�v��
		// �X�e�[�W���f���p�̃V���h�E�}�b�v�̂ǂ�����g�p����
		SetUseShadowMap( 0, StageShadowMapHandle ) ;
		SetUseShadowMap( 1, CharaShadowMapHandle ) ;

		// �X�e�[�W���f���̕`��
		MV1DrawModel( StageModelHandle ) ;

		// �L�����N�^�[���f���̕`��
		MV1DrawModel( CharaModelHandle ) ;

		// �`��Ɏg�p����V���h�E�}�b�v�̐ݒ������
		SetUseShadowMap( 0, -1 ) ;
		SetUseShadowMap( 1, -1 ) ;


		// ����ʂ̓��e��\��ʂɔ��f
		ScreenFlip() ;
	}

	// �V���h�E�}�b�v�̍폜
	DeleteShadowMap( StageShadowMapHandle ) ;
	DeleteShadowMap( CharaShadowMapHandle ) ;

	// �X�e�[�W���f���̍폜
	MV1DeleteModel( StageModelHandle ) ;

	// �L�����N�^�[���f���̍폜
	MV1DeleteModel( CharaModelHandle ) ;

	// �c�w���C�u�����̌�n��
	DxLib_End() ;

	// �\�t�g�̏I��
	return 0 ;
}
