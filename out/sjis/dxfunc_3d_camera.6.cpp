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

    // ���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;

    // �J�����𐳎ˉe�ɕύX
    SetupCamera_Ortho( 2000.0f ) ;

    // �J�����̑O���ɉ��s�����W�̈Ⴄ���f�����R�`��
    MV1SetPosition( ModelHandle, VGet( -700.0f + 320.0f, 240.0f, 0.0f ) ) ;
    MV1DrawModel( ModelHandle ) ;

    MV1SetPosition( ModelHandle, VGet(    0.0f + 320.0f, 240.0f, 500.0f ) ) ;
    MV1DrawModel( ModelHandle ) ;

    MV1SetPosition( ModelHandle, VGet(  700.0f + 320.0f, 240.0f, 1000.0f ) ) ;
    MV1DrawModel( ModelHandle ) ;

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
