#include "DxLib.h"

int main()
{
    VERTEX3DSHADER Vertex[ 6 ] ;
    int vshandle ;
    int pshandle ;
    int texhandle ;
    int x ;
    int xadd ;
    float color ;
    float coloradd ;
    FLOAT4 f4 ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �Q�|���S�����̒��_�̃f�[�^���Z�b�g�A�b�v
    Vertex[ 0 ].pos  = VGet( 220.0f, 340.0f,  0.0f ) ;
    Vertex[ 0 ].norm = VGet(   0.0f,   0.0f, -1.0f ) ;
    Vertex[ 0 ].dif  = GetColorU8( 255,  0,255,255 ) ;
    Vertex[ 0 ].spc  = GetColorU8(   0,  0,  0,  0 ) ;
    Vertex[ 0 ].u    = 0.0f ;
    Vertex[ 0 ].v    = 0.0f ;
    Vertex[ 0 ].su   = 0.0f ;
    Vertex[ 0 ].sv   = 0.0f ;

    Vertex[ 1 ].pos  = VGet( 420.0f, 340.0f,  0.0f ) ;
    Vertex[ 1 ].norm = VGet(   0.0f,   0.0f, -1.0f ) ;
    Vertex[ 1 ].dif  = GetColorU8(   0,  0,255,255 ) ;
    Vertex[ 1 ].spc  = GetColorU8(   0,  0,  0,  0 ) ;
    Vertex[ 1 ].u    = 1.0f ;
    Vertex[ 1 ].v    = 0.0f ;
    Vertex[ 1 ].su   = 0.0f ;
    Vertex[ 1 ].sv   = 0.0f ;

    Vertex[ 2 ].pos  = VGet( 220.0f, 140.0f,  0.0f ) ;
    Vertex[ 2 ].norm = VGet(   0.0f,   0.0f, -1.0f ) ;
    Vertex[ 2 ].dif  = GetColorU8( 255,255,  0,255 ) ;
    Vertex[ 2 ].spc  = GetColorU8(   0,  0,  0,  0 ) ;
    Vertex[ 2 ].u    = 0.0f ;
    Vertex[ 2 ].v    = 1.0f ;
    Vertex[ 2 ].su   = 0.0f ;
    Vertex[ 2 ].sv   = 0.0f ;


    Vertex[ 3 ].pos  = VGet( 220.0f, 140.0f,  0.0f ) ;
    Vertex[ 3 ].norm = VGet(   0.0f,   0.0f, -1.0f ) ;
    Vertex[ 3 ].dif  = GetColorU8( 255,255,  0,255 ) ;
    Vertex[ 3 ].spc  = GetColorU8(   0,  0,  0,  0 ) ;
    Vertex[ 3 ].u    = 0.0f ;
    Vertex[ 3 ].v    = 1.0f ;
    Vertex[ 3 ].su   = 0.0f ;
    Vertex[ 3 ].sv   = 0.0f ;

    Vertex[ 4 ].pos  = VGet( 420.0f, 340.0f,  0.0f ) ;
    Vertex[ 4 ].norm = VGet(   0.0f,   0.0f, -1.0f ) ;
    Vertex[ 4 ].dif  = GetColorU8(   0,  0,255,255 ) ;
    Vertex[ 4 ].spc  = GetColorU8(   0,  0,  0,  0 ) ;
    Vertex[ 4 ].u    = 1.0f ;
    Vertex[ 4 ].v    = 0.0f ;
    Vertex[ 4 ].su   = 0.0f ;
    Vertex[ 4 ].sv   = 0.0f ;

    Vertex[ 5 ].pos  = VGet( 420.0f, 140.0f,  0.0f ) ;
    Vertex[ 5 ].norm = VGet(   0.0f,   0.0f, -1.0f ) ;
    Vertex[ 5 ].dif  = GetColorU8( 255,  0,  0,255 ) ;
    Vertex[ 5 ].spc  = GetColorU8(   0,  0,  0,  0 ) ;
    Vertex[ 5 ].u    = 1.0f ;
    Vertex[ 5 ].v    = 1.0f ;
    Vertex[ 5 ].su   = 0.0f ;
    Vertex[ 5 ].sv   = 0.0f ;

    // ���_�V�F�[�_�[��ǂݍ���
    vshandle = LoadVertexShader( "VertexShaderTestVS.vso" ) ;

    // �s�N�Z���V�F�[�_�[��ǂݍ���
    pshandle = LoadPixelShader( "VertexShaderTestPS.pso" ) ;

    // �`��Ɏg�p����摜�̓ǂݍ���
    texhandle = LoadGraph( "Tex1.bmp" ) ;

    // �`���𗠉�ʂɂ���
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // �\�����W���ړ����鏈���̏�����
    x = 0 ;
    xadd = 8 ;

    // �F��ω������鏈���̏�����
    color = 0.0f ;
    coloradd = 1.0f / 60.0f ;

    // ESC�L�[���������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // ��ʂ�������
        ClearDrawScreen() ;

        // ���W���ړ�������
        x += xadd ;
        if( x > 200 || x < -200 )
        {
            xadd = -xadd ;
        }

        // �F�̒l��ω�������
        color += coloradd ;
        if( color <= 0.0f || color >= 1.0f )
        {
            coloradd = -coloradd ;
        }

        // ���W�l�𒸓_�V�F�[�_�[ float4�^�萔�O�ԂɃZ�b�g
        f4.x = ( float )x ;
        f4.y = 0.0f ;
        f4.z = 0.0f ;
        f4.w = 0.0f ;
        SetVSConstF( 0, f4 ) ;

        // �F�̒l���s�N�Z���V�F�[�_�[ float4�^�萔�O�ԂɃZ�b�g
        f4.x = color ;
        f4.y = color ;
        f4.z = color ;
        f4.w = 1.0f ;
        SetPSConstF( 0, f4 ) ;

        // �g�p���钸�_�V�F�[�_�[�̃Z�b�g
        SetUseVertexShader( vshandle ) ;

        // �g�p����s�N�Z���V�F�[�_�[���Z�b�g
        SetUsePixelShader( pshandle ) ;

        // �g�p����e�N�X�`�����O�ԂɃZ�b�g
        SetUseTextureToShader( 0, texhandle ) ;

        // �V�F�[�_�[���g�p�����Q�|���S���̕`��
        DrawPolygon3DToShader( Vertex, 2 ) ;

        // ����ʂ̓��e��\��ʂɔ��f������
        ScreenFlip() ;
    }

    // �g�p�������_�V�F�[�_�[�� float4�^�萔�̐ݒ�𖳌�������
    ResetVSConstF( 0, 2 ) ;

    // �g�p�����s�N�Z���V�F�[�_�[�� float4�^�萔�̐ݒ�𖳌�������
    ResetPSConstF( 0, 1 ) ;

    // �ǂݍ��񂾒��_�V�F�[�_�[�̍폜
    DeleteShader( vshandle ) ;

    // �ǂݍ��񂾃s�N�Z���V�F�[�_�[�̍폜
    DeleteShader( pshandle ) ;

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( texhandle ) ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
