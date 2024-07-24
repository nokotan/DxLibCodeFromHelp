#include "DxLib.h"

int main()
{
    int texhandle, pshandle ;
    int screen0, screen1 ;
    VERTEX2DSHADER Vert[ 6 ] ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 ) return -1;

    // �e�N�X�`����ǂݍ���
    texhandle = LoadGraph( "Tex1.bmp" ) ;

    // �s�N�Z���V�F�[�_�[��ǂݍ���
    pshandle = LoadPixelShader( "SetRenderTargetTestPS.pso" ) ;

    // �Q�T�U�~�Q�T�U�̕`��\�ȃO���t�B�b�N�n���h�����쐬����
    screen0 = MakeScreen( 256, 256 ) ;
    screen1 = MakeScreen( 256, 256 ) ;

    // �Q�|���S�����̒��_�̃f�[�^���Z�b�g�A�b�v
    Vert[ 0 ].pos = VGet(   0.0f,   0.0f, 0.0f ) ;
    Vert[ 0 ].rhw = 1.0f ;
    Vert[ 0 ].dif = GetColorU8( 255,255,255,255 ) ;
    Vert[ 0 ].spc = GetColorU8(   0,  0,  0,  0 ) ;
    Vert[ 0 ].u   = 0.0f ;
    Vert[ 0 ].v   = 0.0f ;
    Vert[ 0 ].su  = 0.0f ;
    Vert[ 0 ].sv  = 0.0f ;

    Vert[ 1 ].pos = VGet( 256.0f,   0.0f, 0.0f ) ;
    Vert[ 1 ].rhw = 1.0f ;
    Vert[ 1 ].dif = GetColorU8( 255,255,255,255 ) ;
    Vert[ 1 ].spc = GetColorU8(   0,  0,  0,  0 ) ;
    Vert[ 1 ].u   = 1.0f ;
    Vert[ 1 ].v   = 0.0f ;
    Vert[ 1 ].su  = 0.0f ;
    Vert[ 1 ].sv  = 0.0f ;

    Vert[ 2 ].pos = VGet(   0.0f, 256.0f, 0.0f ) ;
    Vert[ 2 ].rhw = 1.0f ;
    Vert[ 2 ].dif = GetColorU8( 255,255,255,255 ) ;
    Vert[ 2 ].spc = GetColorU8(   0,  0,  0,  0 ) ;
    Vert[ 2 ].u   = 0.0f ;
    Vert[ 2 ].v   = 1.0f ;
    Vert[ 2 ].su  = 0.0f ;
    Vert[ 2 ].sv  = 0.0f ;

    Vert[ 3 ].pos = VGet( 256.0f, 256.0f, 0.0f ) ;
    Vert[ 3 ].rhw = 1.0f ;
    Vert[ 3 ].dif = GetColorU8( 255,255,255,255 ) ;
    Vert[ 3 ].spc = GetColorU8(   0,  0,  0,  0 ) ;
    Vert[ 3 ].u   = 1.0f ;
    Vert[ 3 ].v   = 1.0f ;
    Vert[ 3 ].su  = 0.0f ;
    Vert[ 3 ].sv  = 0.0f ;

    Vert[ 4 ].pos = VGet(   0.0f, 256.0f, 0.0f ) ;
    Vert[ 4 ].rhw = 1.0f ;
    Vert[ 4 ].dif = GetColorU8( 255,255,255,255 ) ;
    Vert[ 4 ].spc = GetColorU8(   0,  0,  0,  0 ) ;
    Vert[ 4 ].u   = 0.0f ;
    Vert[ 4 ].v   = 1.0f ;
    Vert[ 4 ].su  = 0.0f ;
    Vert[ 4 ].sv  = 0.0f ;

    Vert[ 5 ].pos = VGet( 256.0f,   0.0f, 0.0f ) ;
    Vert[ 5 ].rhw = 1.0f ;
    Vert[ 5 ].dif = GetColorU8( 255,255,255,255 ) ;
    Vert[ 5 ].spc = GetColorU8(   0,  0,  0,  0 ) ;
    Vert[ 5 ].u   = 1.0f ;
    Vert[ 5 ].v   = 0.0f ;
    Vert[ 5 ].su  = 0.0f ;
    Vert[ 5 ].sv  = 0.0f ;

    // �`���O��`��\�摜�̈�ڂɐݒ�
    SetRenderTargetToShader( 0, screen0 ) ;

    // �`���P��`��\�摜�̓�ڂɐݒ�
    SetRenderTargetToShader( 1, screen1 ) ;

    // �g�p����e�N�X�`�����O�ԂɃZ�b�g
    SetUseTextureToShader( 0, texhandle ) ;

    // �g�p����s�N�Z���V�F�[�_�[���Z�b�g
    SetUsePixelShader( pshandle ) ;

    // �V�F�[�_�[���g�p�����Q�c�̂Q�|���S���̕`��
    DrawPolygon2DToShader( Vert, 2 ) ;

    // �`����\��ʂɕύX
    SetDrawScreen( DX_SCREEN_FRONT ) ;

    // �`���P�̐ݒ�����Z�b�g
    SetRenderTargetToShader( 1, -1 ) ;

    // ��̕`��\�摜����ׂĕ`��
    DrawGraph(   0, 0, screen0, FALSE ) ;
    DrawGraph( 256, 0, screen1, FALSE ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �ǂݍ��񂾃s�N�Z���V�F�[�_�[�̍폜
    DeleteShader( pshandle ) ;

    // MakeScreen �ō쐬�����O���t�B�b�N�n���h���̍폜
    DeleteGraph( screen0 ) ;
    DeleteGraph( screen1 ) ;

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( texhandle ) ;

    // �c�w���C�u�����̌�n��
    DxLib_End();

    // �\�t�g�̏I��
    return 0;
}
