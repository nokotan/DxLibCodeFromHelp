#include "DxLib.h"

int main()
{
    int ModelHandle ;
    int i, TextureNum ;
    int Width, Height, GrHandle ;
    const char *String ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;

    // ���f���Ɋ܂܂��e�N�X�`���̑������擾����
    TextureNum = MV1GetTextureNum( ModelHandle ) ;

    // �e�N�X�`���̐������J��Ԃ�
    for( i = 0 ; i < TextureNum ; i ++ )
    {
        // ��ʂ��N���A����
        ClearDrawScreen() ;

        // �e�N�X�`���̃O���t�B�b�N�n���h�����擾����
        GrHandle = MV1GetTextureGraphHandle( ModelHandle, i ) ;

        // �e�N�X�`���̖��O��`�悷��
        DrawFormatString( 0, 0, GetColor( 255,255,255 ),  "Name                  %s", MV1GetTextureName( ModelHandle, i ) ) ;

        // �e�N�X�`���̑傫����`�悷��
        GetGraphSize( GrHandle, &Width, &Height ) ;
        DrawFormatString( 0, 16, GetColor( 255,255,255 ), "Size                  %dx%d", Width, Height ) ;

        // �e�N�X�`���̂t�l�̃A�h���X���[�h��`�悷��
        switch( MV1GetTextureAddressModeU( ModelHandle, i ) )
        {
        case DX_TEXADDRESS_WRAP   : String = "DX_TEXADDRESS_WRAP" ;   break ;
        case DX_TEXADDRESS_MIRROR : String = "DX_TEXADDRESS_MIRROR" ; break ;
        case DX_TEXADDRESS_CLAMP  : String = "DX_TEXADDRESS_CLAMP" ;  break ;
        }
        DrawFormatString( 0, 32, GetColor( 255,255,255 ), "Address Mode U        %s", String ) ;

        // �e�N�X�`���̂u�l�̃A�h���X���[�h��`�悷��
        switch( MV1GetTextureAddressModeV( ModelHandle, i ) )
        {
        case DX_TEXADDRESS_WRAP   : String = "DX_TEXADDRESS_WRAP" ;   break ;
        case DX_TEXADDRESS_MIRROR : String = "DX_TEXADDRESS_MIRROR" ; break ;
        case DX_TEXADDRESS_CLAMP  : String = "DX_TEXADDRESS_CLAMP" ;  break ;
        }
        DrawFormatString( 0, 48, GetColor( 255,255,255 ), "Address Mode V        %s", String ) ;

        // �e�N�X�`���̃t�B���^�����O���[�h��`�悷��
        switch( MV1GetTextureSampleFilterMode( ModelHandle, i ) )
        {
        case DX_DRAWMODE_NEAREST :     String = "DX_DRAWMODE_NEAREST" ;     break ;
        case DX_DRAWMODE_BILINEAR :    String = "DX_DRAWMODE_BILINEAR" ;    break ;
        case DX_DRAWMODE_ANISOTROPIC : String = "DX_DRAWMODE_ANISOTROPIC" ; break ;
        }
        DrawFormatString( 0, 64, GetColor( 255,255,255 ), "Sample Filter Mode    %s", String ) ;

        // �e�N�X�`����`�悷��
        DrawGraph( 0, 80, GrHandle, TRUE ) ;

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
