#include "DxLib.h"

int GraphHandle1, GraphHandle2;

// �t�@�C���̕����֐�
void ReloadFunction( void )
{
    // �t�@�C������ǂݍ��񂾉摜�𕜌�����
    ReloadFileGraphAll();

    // MakeScreen �ō쐬�����O���t�B�b�N�n���h����`��Ώۂɂ���
    SetDrawScreen( GraphHandle1 );

    // ���e���N���A
    ClearDrawScreen();

    // ���S�Ɏl�p�`��`�悷��
    DrawBox( 64, 64, 256 - 64, 256 - 64, GetColor( 255,255,255 ), TRUE );

    // �`���𗠉�ʂɖ߂�
    SetDrawScreen( DX_SCREEN_BACK );
}

int main()
{
    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 ) return -1;

    // �摜�����֐���o�^
    SetRestoreGraphCallback( ReloadFunction );

    // 256x256 �̕`��Ώۂɂł���O���t�B�b�N�n���h�����쐬����
    GraphHandle1 = MakeScreen( 256, 256 ) ;

    // MakeScreen �ō쐬�����O���t�B�b�N�n���h����`��Ώۂɂ���
    SetDrawScreen( GraphHandle1 );

    // ���e���N���A
    ClearDrawScreen();

    // ���S�Ɏl�p�`��`�悷��
    DrawBox( 64, 64, 256 - 64, 256 - 64, GetColor( 255,255,255 ), TRUE );

    // �t�@�C������摜�𒼐ړǂݍ���
    GraphHandle2 = LoadGraph( "Test2.bmp" );

    // �`���𗠉�ʂɂ���
    SetDrawScreen( DX_SCREEN_BACK );

    // ���C�����[�v(�d�r�b�L�[�������ꂽ�烋�[�v�𔲂���)
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // ��ʂ̃N���A
        ClearDrawScreen();

        // �摜�̕`��
        DrawGraph(   0, 0, GraphHandle1, FALSE );
        DrawGraph( 300, 0, GraphHandle2, FALSE );

        // ����ʂ̓��e��\��ʂɔ��f
        ScreenFlip();
    }

    // �O���t�B�b�N�n���h�����폜
    DeleteGraph( GraphHandle1 ) ;
    DeleteGraph( GraphHandle2 ) ;

    // �c�w���C�u�����̌�n��
    DxLib_End();

    // �\�t�g�̏I��
    return 0;
}
