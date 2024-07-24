#include "DxLib.h"

int main()
{
	int ClickX, ClickY, Button, LogType ;
	int DrawFlag, DrawX, DrawY, DrawColor ;

	// �c�w���C�u�����̏�����
	if( DxLib_Init() < 0 ) return -1 ;

	// �`���𗠉�ʂɂ���
	SetDrawScreen( DX_SCREEN_BACK ) ;

	// �`����̏�����
	DrawFlag = FALSE ;
	DrawX = 0 ;
	DrawY = 0 ;
	DrawColor = 0 ;

	// ���C�����[�v(�����L�[�������ꂽ�烋�[�v�𔲂���)
	while( ProcessMessage() == 0 )
	{
		// ��ʂ̃N���A
		ClearDrawScreen() ;

		// �}�E�X�̃{�^���������ꂽ�藣���ꂽ�肵�����ǂ����̏����擾����
		if( GetMouseInputLog2( &Button, &ClickX, &ClickY, &LogType, TRUE ) == 0 )
		{
			// ���{�^���������ꂽ�藣���ꂽ�肵�Ă�����`�悷�邩�ǂ����̃t���O�𗧂ĂāA���W���ۑ�����
			if( ( Button & MOUSE_INPUT_LEFT ) != 0 )
			{
				DrawFlag = TRUE ;
				DrawX = ClickX ;
				DrawY = ClickY ;

				// �l�p�`�̐F�������ꂽ�ꍇ�͔��ɁA�����ꂽ�ꍇ�͎��ɂ���
				DrawColor = LogType == MOUSE_INPUT_LOG_DOWN ? GetColor( 255,255,255 ) : GetColor( 255,0,255 ) ;
			}
		}

		// �`�悷�邩�ǂ����̃t���O�������Ă�����A�}�E�X�̍��{�^���������ꂽ�藣���ꂽ�肵�����W�ɏ������l�p�`��`�悷��
		if( DrawFlag == TRUE )
		{
			DrawBox( DrawX - 8, DrawY - 8, DrawX + 8, DrawY + 8, DrawColor, TRUE ) ;
		}

		// ����ʂ̓��e��\��ʂɔ��f
		ScreenFlip() ;

		// �O�D�T�b�҂�
		WaitTimer( 500 ) ;
	}

	// �c�w���C�u�����̌�n��
	DxLib_End() ;

	// �\�t�g�̏I��
	return 0 ;
}
