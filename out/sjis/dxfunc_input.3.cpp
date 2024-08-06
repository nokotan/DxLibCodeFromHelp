#include "DxLib.h"

int main()
{
	XINPUT_STATE input ;
	int i ;
	int Color ;

	// �c�w���C�u�����̏�����
	if( DxLib_Init() < 0 ) return -1 ;

	// �`���𗠉�ʂɂ���
	SetDrawScreen( DX_SCREEN_BACK ) ;

	// ���C�����[�v(�����L�[�������ꂽ�烋�[�v�𔲂���)
	while( ProcessMessage() == 0 )
	{
		// ��ʂ̃N���A
		ClearDrawScreen() ;

		// ���͏�Ԃ��擾
		GetJoypadXInputState( DX_INPUT_PAD1, &input ) ;

		// ��ʂ� XINPUT_STATE �̒��g��`��
		Color = GetColor( 255,255,255 ) ;
		DrawFormatString( 0, 0, Color, "LeftTrigger:%d RightTrigger:%d",
						input.LeftTrigger, input.RightTrigger ) ;
		DrawFormatString( 0, 16, Color, "ThumbLX:%d ThumbLY:%d",
						input.ThumbLX, input.ThumbLY ) ;
		DrawFormatString( 0, 32, Color, "ThumbRX:%d ThumbRY:%d",
						input.ThumbRX, input.ThumbRY ) ;
		DrawString( 0, 64, "Button", Color ) ;
		for( i = 0 ; i < 16 ; i ++ )
		{
			DrawFormatString( 64 + i % 8 * 64, 64 + i / 8 * 16, Color,
								"%2d:%d", i, input.Buttons[ i ] ) ;
		}

		// ����ʂ̓��e��\��ʂɔ��f
		ScreenFlip() ;
	}

	// �c�w���C�u�����̌�n��
	DxLib_End() ;

	// �\�t�g�̏I��
	return 0;
}