#include "DxLib.h"

int main()
{
	int ModelHandle ;

	// �E�B���h�E���[�h�ŋN��
	ChangeWindowMode( TRUE ) ;

	// ��ʉ𑜓x��ݒ�
	SetGraphMode( 1920, 1080, 32 ) ;

	// Live2D Cubism Core DLL �̓ǂݍ���( 64bit �A�v���̏ꍇ�� 32bit �A�v���̏ꍇ�œǂݍ��� dll ��ύX )
#ifdef _WIN64
	Live2D_SetCubism4CoreDLLPath( "D:/CubismSdkForNative-4-beta.1/Core/dll/windows/x86_64/Live2DCubismCore.dll" ) ;
#else
	Live2D_SetCubism4CoreDLLPath( "D:/CubismSdkForNative-4-beta.1/Core/dll/windows/x86/Live2DCubismCore.dll" ) ;
#endif

	// �c�w���C�u��������������
	if( DxLib_Init() == -1 )
	{
		 return -1 ;
	}

	// Live2D���f���̓ǂݍ���
	ModelHandle = Live2D_LoadModel( "D:/Cubism4SDKforNative-beta12-1/Samples/Res/Hiyori/Hiyori.model3.json" ) ;

	// �`���𗠉�ʂɕύX
	SetDrawScreen( DX_SCREEN_BACK ) ;

	// ���C�����[�v
	while( ProcessMessage() == 0 )
	{
		// ��ʂ̏�����
		ClearDrawScreen() ;

		// ���[�V�����Đ����I�����Ă�����A�C�h�����O���[�V�����������_���ōĐ�
		if( Live2D_Model_IsMotionFinished( ModelHandle ) == TRUE )
		{
			Live2D_Model_StartMotion( ModelHandle, "Idle", GetRand( 8 ) ) ;
		}

		// ���f���̏�Ԃ�60����1�b���i�߂�
		Live2D_Model_Update( ModelHandle, 1 / 60.0f ) ;

		// Live2D�`��̊J�n
		Live2D_RenderBegin() ;

		// ���f���̕`��
		Live2D_Model_Draw( ModelHandle ) ;

		// Live2D�`��̏I��
		Live2D_RenderEnd() ;

		// ����ʂ̓��e��\��ʂɔ��f
		ScreenFlip() ;
	}

	// Live2D ���f���̍폜
	Live2D_DeleteModel( ModelHandle ) ;

	// �c�w���C�u�����g�p�̏I������
	DxLib_End() ;

	// �\�t�g�̏I��
	return 0 ;
}
