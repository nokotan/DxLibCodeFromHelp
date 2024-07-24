#include "DxLib.h"

#define CHARA_POS_SPACE         (1500.0f)
#define CHARA_NUM               (4)
#define CHARA_POS_DISTANCE      ( ( CHARA_NUM - 1 ) * CHARA_POS_SPACE )

int StageModelHandle ;
int CharaModelHandle ;
int ShadowMapHandle ;

// �L�����N�^�[��`�悷��
void CharaDraw( void )
{
	int i ;
	int j ;
	VECTOR Position ;

	// �L�����N�^�[���P�U�̕`��
	for( i = 0 ; i < CHARA_NUM ; i ++ )
	{
		for( j = 0 ; j < CHARA_NUM ; j ++ )
		{
			// �`��ʒu��ݒ�
			Position.x = -CHARA_POS_DISTANCE / 2.0f + CHARA_POS_SPACE * j ;
			Position.y = 0.0f ;
			Position.z = -CHARA_POS_DISTANCE / 2.0f + CHARA_POS_SPACE * i ;
			MV1SetPosition( CharaModelHandle, Position ) ;

			// �R�c���f����`��
			MV1DrawModel( CharaModelHandle ) ;
		}
	}
}

int main()
{
	float DrawAreaSize ;
	VECTOR DrawAreaMinPos ;
	VECTOR DrawAreaMaxPos ;

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
	SetCameraPositionAndTarget_UpVecY( VGet( 0.0f, 3600.0f, -3400.0f ), VGet( 0.000f, 500.000f, -500.000f ) );

	// �`�悷�鉜�s�������͈̔͂�ݒ�
	SetCameraNearFar( 200.000f, 10000.000f );

	// ���C�g�̕�����ݒ�
	SetLightDirection( VGet( 0.5f, -0.5f, 0.5f ) );

	// �V���h�E�}�b�v���z�肷�郉�C�g�̕������Z�b�g
	SetShadowMapLightDirection( ShadowMapHandle, VGet( 0.5f, -0.5f, 0.5f ) ) ;

	// �`�悷��T�C�Y��������
	DrawAreaSize = 1000.0f ;

	// ���C�����[�v
	while( ProcessMessage() == 0 )
	{
		// ��ʂ��N���A
		ClearDrawScreen() ;


		// �㉺�L�[�ŕ`�悷��T�C�Y��ύX
		if( CheckHitKey( KEY_INPUT_UP ) == 1 )
		{
			DrawAreaSize += 10.0f ;
		}

		if( CheckHitKey( KEY_INPUT_DOWN ) == 1 )
		{
			DrawAreaSize -= 10.0f ;
			if( DrawAreaSize < 1.0f )
			{
				DrawAreaSize = 1.0f ;
			}
		}

		// �V���h�E�}�b�v�ɕ`�悷��͈͂�ݒ�
		DrawAreaMinPos = VGet( -DrawAreaSize,   -1.0f, -DrawAreaSize ) ;
		DrawAreaMaxPos = VGet(  DrawAreaSize, 1000.0f,  DrawAreaSize ) ;
		SetShadowMapDrawArea( ShadowMapHandle, DrawAreaMinPos, DrawAreaMaxPos ) ;

		// �V���h�E�}�b�v�ւ̕`��̏���
		ShadowMap_DrawSetup( ShadowMapHandle ) ;

		// �V���h�E�}�b�v�փX�e�[�W���f���̕`��
		MV1DrawModel( StageModelHandle ) ;

		// �V���h�E�}�b�v�փL�����N�^�[���f���̕`��
		CharaDraw() ;

		// �V���h�E�}�b�v�ւ̕`����I��
		ShadowMap_DrawEnd() ;


		// �`��Ɏg�p����V���h�E�}�b�v��ݒ�
		SetUseShadowMap( 0, ShadowMapHandle ) ;

		// �X�e�[�W���f���̕`��
		MV1DrawModel( StageModelHandle ) ;

		// �L�����N�^�[���f���̕`��
		CharaDraw() ;

		// �`��Ɏg�p����V���h�E�}�b�v�̐ݒ������
		SetUseShadowMap( 0, -1 ) ;


		// ��ʂɌ��݂̃T�C�Y�Ɣ͈͂�`��
		DrawFormatString( 0,  0, GetColor( 255,255,255 ), "AreaSize:%.1f", DrawAreaSize ) ;
		DrawFormatString( 0, 16, GetColor( 255,255,255 ), "MinPos( %.1f, %.1f, %.1f )",
			DrawAreaMinPos.x, DrawAreaMinPos.y, DrawAreaMinPos.z ) ;
		DrawFormatString( 0, 32, GetColor( 255,255,255 ), "MaxPos( %.1f, %.1f, %.1f )",
			DrawAreaMaxPos.x, DrawAreaMaxPos.y, DrawAreaMaxPos.z ) ;

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
