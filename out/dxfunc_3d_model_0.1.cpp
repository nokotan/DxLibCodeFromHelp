#include "DxLib.h"

int main()
{
    int ModelHandle[ 4 ] ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �R�c���f���̓ǂݍ���
    ModelHandle[ 0 ] = MV1LoadModel( "DxChara.x" ) ;

    // �����f�[�^���g�p���郂�f���n���h�����R�쐬����
    ModelHandle[ 1 ] = MV1DuplicateModel( ModelHandle[ 0 ] ) ;
    ModelHandle[ 2 ] = MV1DuplicateModel( ModelHandle[ 0 ] ) ;
    ModelHandle[ 3 ] = MV1DuplicateModel( ModelHandle[ 0 ] ) ;

    // ��ʂɉf��ʒu�ɂR�c���f�����ړ�
    MV1SetPosition( ModelHandle[ 0 ], VGet( -200.0f, -300.0f, 600.0f ) ) ;
    MV1SetPosition( ModelHandle[ 1 ], VGet(  150.0f, -300.0f, 600.0f ) ) ;
    MV1SetPosition( ModelHandle[ 2 ], VGet(  500.0f, -300.0f, 600.0f ) ) ;
    MV1SetPosition( ModelHandle[ 3 ], VGet(  850.0f, -300.0f, 600.0f ) ) ;

    // �R�c���f���̕`��
    MV1DrawModel( ModelHandle[ 0 ] ) ;
    MV1DrawModel( ModelHandle[ 1 ] ) ;
    MV1DrawModel( ModelHandle[ 2 ] ) ;
    MV1DrawModel( ModelHandle[ 3 ] ) ;

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle[ 0 ] ) ;
    MV1DeleteModel( ModelHandle[ 1 ] ) ;
    MV1DeleteModel( ModelHandle[ 2 ] ) ;
    MV1DeleteModel( ModelHandle[ 3 ] ) ;

    // �L�[�̓��͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
