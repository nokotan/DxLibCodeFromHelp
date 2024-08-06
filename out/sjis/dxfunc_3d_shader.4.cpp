#include "DxLib.h"

int main()
{
    VERTEX3DSHADER Vertex[ 6 ] ;
    int vshandle ;
    int pshandle ;
    int texhandle ;
    float angle ;
    FLOAT4 pos ;
    MATRIX mtx ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �Q�|���S�����̒��_�̃f�[�^���Z�b�g�A�b�v
    Vertex[ 0 ].pos  = VGet( -128.0f,  128.0f,  0.0f ) ;
    Vertex[ 0 ].norm = VGet(   0.0f,   0.0f, -1.0f ) ;
    Vertex[ 0 ].dif  = GetColorU8( 255,  0,255,255 ) ;
    Vertex[ 0 ].spc  = GetColorU8(   0,  0,  0,  0 ) ;
    Vertex[ 0 ].u    = 0.0f ;
    Vertex[ 0 ].v    = 0.0f ;
    Vertex[ 0 ].su   = 0.0f ;
    Vertex[ 0 ].sv   = 0.0f ;

    Vertex[ 1 ].pos  = VGet(  128.0f,  128.0f,  0.0f ) ;
    Vertex[ 1 ].norm = VGet(   0.0f,   0.0f, -1.0f ) ;
    Vertex[ 1 ].dif  = GetColorU8(   0,  0,255,255 ) ;
    Vertex[ 1 ].spc  = GetColorU8(   0,  0,  0,  0 ) ;
    Vertex[ 1 ].u    = 1.0f ;
    Vertex[ 1 ].v    = 0.0f ;
    Vertex[ 1 ].su   = 0.0f ;
    Vertex[ 1 ].sv   = 0.0f ;

    Vertex[ 2 ].pos  = VGet( -128.0f, -128.0f,  0.0f ) ;
    Vertex[ 2 ].norm = VGet(   0.0f,   0.0f, -1.0f ) ;
    Vertex[ 2 ].dif  = GetColorU8( 255,255,  0,255 ) ;
    Vertex[ 2 ].spc  = GetColorU8(   0,  0,  0,  0 ) ;
    Vertex[ 2 ].u    = 0.0f ;
    Vertex[ 2 ].v    = 1.0f ;
    Vertex[ 2 ].su   = 0.0f ;
    Vertex[ 2 ].sv   = 0.0f ;


    Vertex[ 3 ].pos  = VGet( -128.0f, -128.0f,  0.0f ) ;
    Vertex[ 3 ].norm = VGet(   0.0f,   0.0f, -1.0f ) ;
    Vertex[ 3 ].dif  = GetColorU8( 255,255,  0,255 ) ;
    Vertex[ 3 ].spc  = GetColorU8(   0,  0,  0,  0 ) ;
    Vertex[ 3 ].u    = 0.0f ;
    Vertex[ 3 ].v    = 1.0f ;
    Vertex[ 3 ].su   = 0.0f ;
    Vertex[ 3 ].sv   = 0.0f ;

    Vertex[ 4 ].pos  = VGet(  128.0f,  128.0f,  0.0f ) ;
    Vertex[ 4 ].norm = VGet(   0.0f,   0.0f, -1.0f ) ;
    Vertex[ 4 ].dif  = GetColorU8(   0,  0,255,255 ) ;
    Vertex[ 4 ].spc  = GetColorU8(   0,  0,  0,  0 ) ;
    Vertex[ 4 ].u    = 1.0f ;
    Vertex[ 4 ].v    = 0.0f ;
    Vertex[ 4 ].su   = 0.0f ;
    Vertex[ 4 ].sv   = 0.0f ;

    Vertex[ 5 ].pos  = VGet(  128.0f, -128.0f,  0.0f ) ;
    Vertex[ 5 ].norm = VGet(   0.0f,   0.0f, -1.0f ) ;
    Vertex[ 5 ].dif  = GetColorU8( 255,  0,  0,255 ) ;
    Vertex[ 5 ].spc  = GetColorU8(   0,  0,  0,  0 ) ;
    Vertex[ 5 ].u    = 1.0f ;
    Vertex[ 5 ].v    = 1.0f ;
    Vertex[ 5 ].su   = 0.0f ;
    Vertex[ 5 ].sv   = 0.0f ;

    // ���_�V�F�[�_�[��ǂݍ���
    vshandle = LoadVertexShader( "SetVSConstFMtxTestVS.vso" ) ;

    // �s�N�Z���V�F�[�_�[��ǂݍ���
    pshandle = LoadPixelShader( "SetVSConstFMtxTestPS.pso" ) ;

    // �`��Ɏg�p����摜�̓ǂݍ���
    texhandle = LoadGraph( "Tex1.bmp" ) ;

    // �`���𗠉�ʂɂ���
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // ��]�p�x�̒l��������
    angle = 0.0f ;

    // ���_�V�F�[�_�[ FLOAT4�^�萔�O�Ԃɕ\�����W���Z�b�g
    pos.x = 320.0f ;
    pos.y = 240.0f ;
    pos.z = 0.0f ;
    pos.w = 0.0f ;
    SetVSConstF( 0, pos ) ;

    // ESC�L�[���������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // ��ʂ�������
        ClearDrawScreen() ;

        // ��]�p�x��ω�������
        angle += 0.05f ;

        // ��]�p�x����Z����]�s����쐬
        mtx = MGetRotZ( angle ) ;

        // ��]�s��𒸓_�V�F�[�_�[ FLOAT4�^�萔�P�O�`�P�R�ԂɃZ�b�g
        SetVSConstFMtx( 10, mtx ) ;

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

    // �g�p����float4�^�萔�O�Ԃ̐ݒ�𖳌�������
    ResetVSConstF( 0, 1 ) ;

    // �g�p����float4�^�萔�P�O�`�P�R�Ԃ̐ݒ�𖳌�������
    ResetVSConstF( 10, 4 ) ;

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
