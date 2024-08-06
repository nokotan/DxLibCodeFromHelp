#include "DxLib.h"

int main()
{
    int ModelHandle, MaterialNum, i ;
    COLOR_F Color ;
    char *Name ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // ���f���Ɋ܂܂��}�e���A���̐����擾����
    MaterialNum = MV1GetMaterialNum( ModelHandle ) ;

    // �}�e���A���̏�����Â`�悷��
    for( i = 0 ; i < MaterialNum ; i ++ )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // �}�e���A���̖��O��`��
        DrawFormatString( 0, 0, GetColor( 255,255,255 ),  "Name            %s", MV1GetMaterialName( ModelHandle, i ) ) ;

        // �}�e���A���̃f�B�t���[�Y�J���[��`��
        Color = MV1GetMaterialDifColor( ModelHandle, i ) ;
        DrawFormatString( 0, 16, GetColor( 255,255,255 ), "Diffuse  Color  R:%f  G:%f  B:%f  A:%f", Color.r, Color.g, Color.b, Color.a ) ;

        // �}�e���A���̃X�y�L�����J���[��`��
        Color = MV1GetMaterialSpcColor( ModelHandle, i ) ;
        DrawFormatString( 0, 32, GetColor( 255,255,255 ), "Specular Color  R:%f  G:%f  B:%f  A:%f", Color.r, Color.g, Color.b, Color.a ) ;

        // �}�e���A���̃G�~�b�V�u�J���[��`��
        Color = MV1GetMaterialEmiColor( ModelHandle, i ) ;
        DrawFormatString( 0, 48, GetColor( 255,255,255 ), "Emissive Color  R:%f  G:%f  B:%f  A:%f", Color.r, Color.g, Color.b, Color.a ) ;

        // �}�e���A���̃A���r�G���g�J���[��`��
        Color = MV1GetMaterialAmbColor( ModelHandle, i ) ;
        DrawFormatString( 0, 64, GetColor( 255,255,255 ), "Ambient  Color  R:%f  G:%f  B:%f  A:%f", Color.r, Color.g, Color.b, Color.a ) ;

        // �}�e���A���̃X�y�L�����̋����`��
        DrawFormatString( 0, 80, GetColor( 255,255,255 ), "Specular Power  %f", MV1GetMaterialSpcPower( ModelHandle, i ) ) ;

        // �`��u�����h���[�h�̕`��
        switch( MV1GetMaterialDrawBlendMode( ModelHandle, i ) )
        {
        case DX_BLENDMODE_NOBLEND : Name = "DX_BLENDMODE_NOBLEND" ; break ;
        case DX_BLENDMODE_ALPHA   : Name = "DX_BLENDMODE_ALPHA"   ; break ;
        case DX_BLENDMODE_ADD     : Name = "DX_BLENDMODE_ADD"     ; break ;
        case DX_BLENDMODE_SUB     : Name = "DX_BLENDMODE_SUB"     ; break ;
        case DX_BLENDMODE_INVSRC  : Name = "DX_BLENDMODE_INVSRC"  ; break ;
        case DX_BLENDMODE_MULA    : Name = "DX_BLENDMODE_MULA"    ; break ;
        }
        DrawFormatString( 0, 96, GetColor( 255,255,255 ), "Draw Blend Mode   %s", Name ) ;

        // �`��u�����h�p�����[�^�̕`��
        DrawFormatString( 0, 112, GetColor( 255,255,255 ), "Draw Blend Param  %d", MV1GetMaterialDrawBlendParam( ModelHandle, i ) ) ;

        // �L�[���͑҂�
        WaitKey() ;
    }

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
