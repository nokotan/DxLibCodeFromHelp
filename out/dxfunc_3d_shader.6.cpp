#include "DxLib.h"

int main()
{
    int texhandle, pshandle ;
    VERTEX2DSHADER Vert[ 6 ] ;
    int r, g, b ;
    int radd, gadd, badd ;
    FLOAT4 f4 ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 ) return -1;

    // �e�N�X�`����ǂݍ���
    texhandle = LoadGraph( "Tex1.bmp" ) ;

    // �s�N�Z���V�F�[�_�[��ǂݍ���
    pshandle = LoadPixelShader( "SetPSConstFTestPS.pso" ) ;

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

    Vert[ 4 ].pos = VGet(   0.0f, 256.0f, 0.0f ) ;
    Vert[ 4 ].rhw = 1.0f ;
    Vert[ 4 ].dif = GetColorU8( 255,255,255,255 ) ;
    Vert[ 4 ].spc = GetColorU8(   0,  0,  0,  0 ) ;
    Vert[ 4 ].u   = 0.0f ;
    Vert[ 4 ].v   = 1.0f ;
    Vert[ 4 ].su  = 0.0f ;
    Vert[ 4 ].sv  = 1.0f ;

    Vert[ 5 ].pos = VGet( 256.0f,   0.0f, 0.0f ) ;
    Vert[ 5 ].rhw = 1.0f ;
    Vert[ 5 ].dif = GetColorU8( 255,255,255,255 ) ;
    Vert[ 5 ].spc = GetColorU8(   0,  0,  0,  0 ) ;
    Vert[ 5 ].u   = 1.0f ;
    Vert[ 5 ].v   = 0.0f ;
    Vert[ 5 ].su  = 1.0f ;
    Vert[ 5 ].sv  = 0.0f ;

    // �`���𗠉�ʂɂ���
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // r, g, b �̒l��ω������鏀��
    r = 0 ;
    g = 128 ;
    b = 255 ;
    radd = 10 ;
    gadd = 7 ;
    badd = 3 ;

    // ESC�L�[���������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // ��ʂ�������
        ClearDrawScreen() ;

        // r, g, b �̒l��ω�������
        r += radd ;
        if( r >= 255 )
        {
            r = 255 ;
            radd = -radd ;
        }
        else
        if( r <= 0 )
        {
            r = 0 ;
            radd = -radd ;
        }

        g += gadd ;
        if( g >= 255 )
        {
            g = 255 ;
            gadd = -gadd ;
        }
        else
        if( g <= 0 )
        {
            g = 0 ;
            gadd = -gadd ;
        }

        b += badd ;
        if( b >= 255 )
        {
            b = 255 ;
            badd = -badd ;
        }
        else
        if( b <= 0 )
        {
            b = 0 ;
            badd = -badd ;
        }

        // r, g, b �̒l���s�N�Z���V�F�[�_�[�� FLOAT4�^�萔�O�ԂɃZ�b�g
        // �萔�ɂ���Ƃ��͒l�� 0.0f �` 1.0f �ɂ���
        f4.x = r / 255.0f ;
        f4.y = g / 255.0f ;
        f4.z = b / 255.0f ;
        f4.w = 1.0f ;
        SetPSConstF( 0, f4 ) ;

        // �g�p����e�N�X�`�����O�ԂɃZ�b�g
        SetUseTextureToShader( 0, texhandle ) ;

        // �g�p����s�N�Z���V�F�[�_�[���Z�b�g
        SetUsePixelShader( pshandle ) ;

        // �V�F�[�_�[���g�p�����Q�c�̂Q�|���S���̕`��
        DrawPolygon2DToShader( Vert, 2 ) ;

        // ����ʂ̓��e��\��ʂɔ��f������
        ScreenFlip() ;
    }

    // �ǂݍ��񂾃s�N�Z���V�F�[�_�[�̍폜
    DeleteShader( pshandle ) ;

    // �g�p�����萔�𖳌�������
    ResetPSConstF( 0, 1 ) ;

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( texhandle ) ;

    // �c�w���C�u�����̌�n��
    DxLib_End();

    // �\�t�g�̏I��
    return 0;
}
