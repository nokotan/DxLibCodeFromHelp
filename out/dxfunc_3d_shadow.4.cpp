#include "DxLib.h"

int main()
{
	int StageModelHandle ;
	int CharaModelHandle ;
	int ShadowMapHandle ;
	float Adjust ;

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
	StageModelHandle = MV1LoadModel( "Plane.mqo" ) ;

	// �V���h�E�}�b�v�n���h���̍쐬
	ShadowMapHandle = MakeShadowMap( 1024, 1024 ) ;

	// �J�����̈ʒu�ƌ�����ݒ�
	SetCameraPositionAndTarget_UpVecY( VGet( 0.0f, 800.0f, -800.0f ), VGet( 0.000f, 500.000f, 0.000f ) );

	// �`�悷�鉜�s�������͈̔͂�ݒ�
	SetCameraNearFar( 40.000f, 2000.000f );

	// ���C�g�̕�����ݒ�
	SetLightDirection( VGet( 0.5f, -0.5f, 0.5f ) );

	// �V���h�E�}�b�v���z�肷�郉�C�g�̕������Z�b�g
	SetShadowMapLightDirection( ShadowMapHandle, VGet( 0.5f, -0.5f, 0.5f ) ) ;

	// �V���h�E�}�b�v�ɕ`�悷��͈͂�ݒ�
	SetShadowMapDrawArea( ShadowMapHandle, VGet( -1000.0f, -1.0f, -1000.0f ), VGet( 1000.0f, 1000.0f, 1000.0f ) ) ;

	// �␳�l��������
	Adjust = 0.002f ;

	// ���C�����[�v
	while( ProcessMessage() == 0 )
	{
		// ��ʂ��N���A
		ClearDrawScreen() ;


		// �㉺�L�[�ŕ␳�l��ύX
		if( CheckHitKey( KEY_INPUT_UP ) == 1 )
		{
			Adjust += 0.001f ;
		}

		if( CheckHitKey( KEY_INPUT_DOWN ) == 1 )
		{
			Adjust -= 0.001f ;
		}
		SetShadowMapAdjustDepth( ShadowMapHandle, Adjust ) ;


		// �V���h�E�}�b�v�ւ̕`��̏���
		ShadowMap_DrawSetup( ShadowMapHandle ) ;

		// �V���h�E�}�b�v�փX�e�[�W���f���̕`��
		MV1DrawModel( StageModelHandle ) ;

		// �V���h�E�}�b�v�փL�����N�^�[���f���̕`��
		MV1DrawModel( CharaModelHandle ) ;

		// �V���h�E�}�b�v�ւ̕`����I��
		ShadowMap_DrawEnd() ;


		// �`��Ɏg�p����V���h�E�}�b�v��ݒ�
		SetUseShadowMap( 0, ShadowMapHandle ) ;

		// �X�e�[�W���f���̕`��
		MV1DrawModel( StageModelHandle ) ;

		// �L�����N�^�[���f���̕`��
		MV1DrawModel( CharaModelHandle ) ;

		// �`��Ɏg�p����V���h�E�}�b�v�̐ݒ������
		SetUseShadowMap( 0, -1 ) ;


		// ���݂̕␳�l����ʂɕ`��
		DrawFormatString( 0, 0, GetColor( 255,255,255 ), "Adjust Depth:%f", Adjust ) ;


		// ����ʂ̓��e��\��ʂɔ��f
		ScreenFlip() ;
	}

	// �V���h�E�}�b�v�̍폜
	DeleteShadowMap( ShadowMapHandle ) ;

	// �X�e�[�W���f���̍폜
	MV1DeleteModel( StageModelHandle ) ;

	// �L�����N�^�[���f���̍폜
	MV1DeleteModel( CharaModelHandle ) ;

	// �c�w���C�u�����̌�n��
	DxLib_End() ;

	// �\�t�g�̏I��
	return 0 ;
}
