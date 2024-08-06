#include "DxLib.h"

int main()
{
    char *TypeName ;
    COLOR_F Color ;
    VECTOR Vector ;
    float Range, Atten0, Atten1, Atten2 ;
    float InAngle, OutAngle ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // ��ʂɕW�����C�g�̃^�C�v��`��
    switch( GetLightType() )
    {
    case DX_LIGHTTYPE_DIRECTIONAL : TypeName = "Directional" ; break ;
    case DX_LIGHTTYPE_POINT :       TypeName = "Point" ;       break ;
    case DX_LIGHTTYPE_SPOT :        TypeName = "Spot" ;        break ;
    }
    DrawFormatString( 0, 0, GetColor( 255,255,255 ),   "LightType       %s", TypeName ) ;

    // ���C�g���L�����ǂ�����`��
    DrawFormatString( 0, 16, GetColor( 255,255,255 ),  "Enable          %d", GetLightEnable() ) ;

    // �f�B�t���[�Y�J���[��`��
    Color = GetLightDifColor() ;
    DrawFormatString( 0, 32, GetColor( 255,255,255 ),  "Diffuse Color   %f %f %f", Color.r, Color.g, Color.b ) ;

    // �X�y�L�����J���[��`��
    Color = GetLightSpcColor() ;
    DrawFormatString( 0, 48, GetColor( 255,255,255 ),  "Specular Color  %f %f %f", Color.r, Color.g, Color.b ) ;

    // �A���r�G���g�J���[��`��
    Color = GetLightAmbColor() ;
    DrawFormatString( 0, 64, GetColor( 255,255,255 ),  "Ambient Color   %f %f %f", Color.r, Color.g, Color.b ) ;

    // ������`��
    Vector = GetLightDirection() ;
    DrawFormatString( 0, 80, GetColor( 255,255,255 ),  "Direction       %f %f %f", Vector.x, Vector.y, Vector.z ) ;

    // �ʒu��`��
    Vector = GetLightPosition() ;
    DrawFormatString( 0, 96, GetColor( 255,255,255 ),  "Position        %f %f %f", Vector.x, Vector.y, Vector.z ) ;

    // �L�������Ƌ��������p�����[�^��`�悷��
    GetLightRangeAtten( &Range, &Atten0, &Atten1, &Atten2 ) ;
    DrawFormatString( 0, 112, GetColor( 255,255,255 ), "Range           %f", Range ) ;
    DrawFormatString( 0, 128, GetColor( 255,255,255 ), "Attenuation0    %f", Atten0 ) ;
    DrawFormatString( 0, 144, GetColor( 255,255,255 ), "Attenuation1    %f", Atten1 ) ;
    DrawFormatString( 0, 160, GetColor( 255,255,255 ), "Attenuation2    %f", Atten2 ) ;

    // �Ǝˊp�x�p�����[�^��`�悷��
    GetLightAngle( &OutAngle, &InAngle ) ;
    DrawFormatString( 0, 176, GetColor( 255,255,255 ), "In  Angle       %f", InAngle ) ;
    DrawFormatString( 0, 192, GetColor( 255,255,255 ), "Out Angle       %f", OutAngle ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
