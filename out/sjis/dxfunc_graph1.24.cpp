#include "DxLib.h"

int main()
{
    int Handle ;

    // ��ʃ��[�h��32bit�J���[�ɂ���
    SetGraphMode( 640, 480, 32 ) ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
        return -1 ;

    // �摜��ǂݍ���
    Handle = LoadGraph( "Src1.bmp" ) ;

    // �K�E�X�t�B���^�[���{��
    GraphFilter( Handle, DX_GRAPH_FILTER_GAUSS, 16, 1400 ) ;

    // �摜����ʂɕ`��
    DrawGraph( 0, 0, Handle, FALSE ) ;

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( Handle ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    return 0 ;
}
