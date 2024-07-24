#include "DxLib.h"

int main()
{
    int texhandle, pshandle ;
    VERTEX2DSHADER Vert[ 4 ] ;
    unsigned short Index[ 6 ] ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 ) return -1;

    // �e�N�X�`����ǂݍ���
    texhandle = LoadGraph( "Tex1.bmp" ) ;

    // �s�N�Z���V�F�[�_�[��ǂݍ���
    pshandle = LoadPixelShader( "PixelShaderTestPS.pso" ) ;

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
    Vert[ 1 ].su  = 1.0f ;
    Vert[ 1 ].sv  = 0.0f ;

    Vert[ 2 ].pos = VGet(   0.0f, 256.0f, 0.0f ) ;
    Vert[ 2 ].rhw = 1.0f ;
    Vert[ 2 ].dif = GetColorU8( 255,255,255,255 ) ;
    Vert[ 2 ].spc = GetColorU8(   0,  0,  0,  0 ) ;
    Vert[ 2 ].u   = 0.0f ;
    Vert[ 2 ].v   = 1.0f ;
    Vert[ 2 ].su  = 0.0f ;
    Vert[ 2 ].sv  = 1.0f ;

    Vert[ 3 ].pos = VGet( 256.0f, 256.0f, 0.0f ) ;
    Vert[ 3 ].rhw = 1.0f ;
    Vert[ 3 ].dif = GetColorU8( 255,255,255,255 ) ;
    Vert[ 3 ].spc = GetColorU8(   0,  0,  0,  0 ) ;
    Vert[ 3 ].u   = 1.0f ;
    Vert[ 3 ].v   = 1.0f ;
    Vert[ 3 ].su  = 1.0f ;
    Vert[ 3 ].sv  = 1.0f ;

    // �Q�|���S�����̒��_�ԍ��z��̃Z�b�g�A�b�v
    Index[ 0 ] = 0 ;
    Index[ 1 ] = 1 ;
    Index[ 2 ] = 2 ;
    Index[ 3 ] = 2 ;
    Index[ 4 ] = 1 ;
    Index[ 5 ] = 3 ;

    // �g�p����e�N�X�`�����O�ԂɃZ�b�g
    SetUseTextureToShader( 0, texhandle ) ;

    // �g�p����s�N�Z���V�F�[�_�[���Z�b�g
    SetUsePixelShader( pshandle ) ;

    // �V�F�[�_�[���g�p�����Q�c�̂Q�|���S���̕`��
    DrawPolygonIndexed2DToShader( Vert, 4, Index, 2 ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �ǂݍ��񂾃s�N�Z���V�F�[�_�[�̍폜
    DeleteShader( pshandle ) ;

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( texhandle ) ;

    // �c�w���C�u�����̌�n��
    DxLib_End();

    // �\�t�g�̏I��
    return 0;
}
