#include "DxLib.h"

int main()
{
	int FontHandle ;
	int ScreenHandle ;

	// �c�w���C�u��������������
	if( DxLib_Init() == -1 )
		 return -1;

	// �`��Ώۂɂł��郿�`�����l���t���̃O���t�B�b�N�n���h�����쐬����
	ScreenHandle = MakeScreen( 256, 64, TRUE ) ;

	// ��Z�ς݃��p�̃t�H���g�n���h�����쐬����
	SetFontCacheUsePremulAlphaFlag( TRUE ) ;
	FontHandle = CreateFontToHandle( "�l�r �S�V�b�N", 32, 4, DX_FONTTYPE_ANTIALIASING_8X8 ) ;

	// �`�����쐬�����O���t�B�b�N�n���h���ɂ���
	SetDrawScreen( ScreenHandle ) ;

	// �O���t�B�b�N�n���h���ɏ�Z�ς݃��p�̃��u�����h���[�h�œ����x50%�ŕ�����`�悷��
	SetDrawBlendMode( DX_BLENDMODE_PMA_ALPHA, 128 ) ;
	DrawStringToHandle( 0, 0, "�e�X�g������", GetColor( 255,255,255 ), FontHandle ) ;

	// �`���𗠉�ʂɕύX����
	SetDrawScreen( DX_SCREEN_BACK ) ;

	// ���ʂ�������₷���悤�ɗ���ʂ�΂œh��Ԃ�
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 255 ) ;
	DrawBox( 0, 0, 640, 480, GetColor( 0,200,0 ), TRUE ) ;

	// ����ʂɕ������`�悵���O���t�B�b�N�n���h������Z�ς݃��p�̃��u�����h���[�h�ŕ`�悷��
	SetDrawBlendMode( DX_BLENDMODE_PMA_ALPHA, 255 ) ;
	DrawGraph( 100, 100, ScreenHandle, TRUE ) ;

	// ����ʂ̓��e��\��ʂɔ��f������
	ScreenFlip() ;

	// �쐬�����t�H���g�n���h�����폜����
	DeleteFontToHandle( FontHandle ) ;

	// MakeScreen �ō쐬�����O���t�B�b�N�n���h���̍폜
	DeleteGraph( ScreenHandle ) ;

	// �L�[���͑҂�
	WaitKey() ;

	// �c�w���C�u�����g�p�̏I������
	DxLib_End() ;

	// �\�t�g�̏I��
	return 0 ;
}
