#include "DxLib.h"

int main()
{
    MATERIALPARAM Material ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �y�o�b�t�@��L���ɂ���
    SetUseZBuffer3D( TRUE ) ;

    // �y�o�b�t�@�ւ̏������݂�L���ɂ���
    SetWriteZBuffer3D( TRUE ) ;

    // �f�t�H���g�̐ݒ�łR�c��ԏ�ɋ���`�悷��
    DrawSphere3D( VGet( 160.0f, 200.0f, 0.0f ), 80.0f, 32, GetColor( 255,0,0 ), GetColor( 255,255,255 ), TRUE ) ;

    // ���_�f�[�^�̃f�B�t���[�Y�J���[���g�p���Ȃ��悤�ɂ���
    SetMaterialUseVertDifColor( FALSE ) ;

    // �}�e���A���̃f�B�t���[�Y�J���[�����F�ɂ���
    Material.Diffuse  = GetColorF( 1.0f, 1.0f, 0.0f, 1.0f ) ;
    Material.Specular = GetColorF( 0.0f, 0.0f, 0.0f, 0.0f ) ;
    Material.Ambient  = GetColorF( 0.0f, 0.0f, 0.0f, 0.0f ) ;
    Material.Emissive = GetColorF( 0.0f, 0.0f, 0.0f, 0.0f ) ;
    Material.Power    = 20.0f ;
    SetMaterialParam( Material ) ;

    // �ēx�R�c��ԏ�ɋ���`�悷��( ���� DifColor �̒l�͖�������܂� )
    DrawSphere3D( VGet( 480.0f, 200.0f, 0.0f ), 80.0f, 32, GetColor( 255,0,0 ), GetColor( 255,255,255 ), TRUE ) ;

    // �L�[���͑҂�������
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
