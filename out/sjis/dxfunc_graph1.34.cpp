#include "DxLib.h"

int main()
{
    int Handle ;
    int BlendHandle ;
    int AlphaHandle ;

    // ��ʃ��[�h��32bit�J���[�ɂ���
    SetGraphMode( 640, 480, 32 ) ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
        return -1 ;

    // �摜��ǂݍ���
    Handle = LoadGraph( "Src1.bmp" ) ;

    // �u�����h����摜��ǂݍ���
    BlendHandle = LoadGraph( "Src2.tga" ) ;

    // �A���t�@�`�����l���t���̕`��\�摜�̃O���t�B�b�N�n���h�����쐬����
    AlphaHandle = MakeScreen( 256, 256, TRUE ) ;

    // �`�����쐬�����A���t�@�`�����l���t���̕`��\�摜�ɂ���
    SetDrawScreen( AlphaHandle ) ;

    // �ǂݍ��񂾉摜��`�悷��
    DrawGraph( 0, 0, Handle, FALSE ) ;

    // �`����\��ʂɖ߂�
    SetDrawScreen( DX_SCREEN_FRONT ) ;

    // �`��\�摜�ƃu�����h����摜����������
    GraphBlend( AlphaHandle, BlendHandle, 255, DX_GRAPH_BLEND_RGBA_SELECT_MIX,
        DX_RGBA_SELECT_SRC_G,    // �o�͌��ʂ̐Ԑ����� AlphaHandle �̗ΐ���
        DX_RGBA_SELECT_SRC_R,    // �o�͌��ʂ̗ΐ����� AlphaHandle �̐Ԑ���
        DX_RGBA_SELECT_SRC_B,    // �o�͌��ʂ̐����� AlphaHandle �̐���
        DX_RGBA_SELECT_BLEND_R    // �o�͌��ʂ̃A���t�@������ BlendHandle �̐Ԑ���
    ) ;

    // �A���t�@�����Ŕ������ɂȂ邱�Ƃ��m���߂邽�߂ɉ�ʑS�̂ɃO���[�̋�`��`�悷��
    DrawBox( 0, 0, 640, 480, GetColor( 128, 128, 128 ), TRUE ) ;

    // �`��\�摜����ʂɕ`��
    DrawGraph( 0, 0, AlphaHandle, TRUE ) ;

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( Handle ) ;
    DeleteGraph( BlendHandle ) ;

    // MakeScreen �ō쐬�����O���t�B�b�N�n���h���̍폜
    DeleteGraph( AlphaHandle ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    return 0 ;
}
