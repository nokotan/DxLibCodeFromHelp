#include "DxLib.h"

int main()
{
    int ModelHandle ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // �u�����h���[�h���ύX���ꂽ���Ƃ��킩��悤�ɉ�ʑS�̂�F�œh��Ԃ�
    DrawBox( 0, 0, 640, 480, GetColor( 0,0,255 ), TRUE ) ;

    // ��ʂɉf��ʒu�ɂR�c���f�����ړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, -300.0f, 600.0f ) ) ;

    // �R�c���f���Ɋ܂܂��P�Ԗڂ̃��b�V���̕`��u�����h���[�h�� DX_BLENDMODE_ADD �ɕύX����
    MV1SetMeshDrawBlendMode( ModelHandle, 1, DX_BLENDMODE_ADD ) ;

    // �R�c���f���̕`��
    MV1DrawModel( ModelHandle ) ;

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // �L�[�̓��͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
