#include "DxLib.h"

int main()
{
    int SrcHandle ;
    int DestHandle ;
    int BlendHandle ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
        return -1 ;

    // �摜��ǂݍ���
    SrcHandle = LoadGraph( "Src1.bmp" ) ;

    // �u�����h����摜��ǂݍ���
    BlendHandle = LoadGraph( "Src2.tga" ) ;

    // �o�͐�̃O���t�B�b�N�n���h�����쐬����
    DestHandle = MakeScreen( 128, 128, FALSE ) ;

    // Handle �� BlendHandle �ŕ����Ă��������s��
    GraphBlendRectBlt( SrcHandle, BlendHandle, DestHandle, 128, 128, 256, 256, 64, 64, 0, 0, 255, DX_GRAPH_BLEND_DODGE ) ;

    // ������̉摜����ʂɕ`��
    DrawGraph( 0, 0, DestHandle, FALSE ) ;

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( SrcHandle ) ;
    DeleteGraph( BlendHandle ) ;

    // MakeScreen �ō쐬�����O���t�B�b�N�n���h���̍폜
    DeleteGraph( DestHandle ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    return 0 ;
}
