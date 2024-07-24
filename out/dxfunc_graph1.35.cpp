#include "DxLib.h"

int main()
{
    int Handle ;
    int BlendHandle ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
        return -1 ;

    // �摜��ǂݍ���
    Handle = LoadGraph( "Src1.bmp" ) ;

    // �u�����h����摜��ǂݍ���
    BlendHandle = LoadGraph( "Src2.tga" ) ;

    // Handle �� BlendHandle �ŃI�[�o�[���C�������s��
    GraphBlend( Handle, BlendHandle, 255, DX_GRAPH_BLEND_OVERLAY ) ;

    // ������̉摜����ʂɕ`��
    DrawGraph( 0, 0, Handle, FALSE ) ;

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( Handle ) ;
    DeleteGraph( BlendHandle ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    return 0 ;
}
