#include "DxLib.h"

int main()
{
    int GHandle ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // test1.bmp�̓ǂݍ���
    GHandle = LoadGraph( "test1.bmp" ) ;

    // �`�惂�[�h���l�A���X�g�l�C�o�[�@�ɂ���
    SetDrawMode( DX_DRAWMODE_NEAREST ) ;

    // �ǂ݂��񂾃O���t�B�b�N����ʍ���Ɋg��`��
    DrawExtendGraph( 0 , 0 , 130 * 2 , 480 * 2 , GHandle , FALSE ) ;

    // �`�惂�[�h���o�C���j�A�@�ɂ���
    SetDrawMode( DX_DRAWMODE_BILINEAR ) ;

    // �ǂ݂��񂾃O���t�B�b�N���قǂׂ̗ɕ`��
    DrawExtendGraph( 260 , 0 , 260 + 130 * 2 , 480 * 2 , GHandle , FALSE ) ;

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( GHandle ) ;

    WaitKey() ;        // ���ʂ����邽�߂ɃL�[�҂�(�wWaitKey�x���g�p)

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
