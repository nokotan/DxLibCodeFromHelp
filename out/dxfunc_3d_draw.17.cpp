#include "DxLib.h"

int main()
{
    int ModelHandle, i ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �t�H�O��L���ɂ���
    SetFogEnable( TRUE ) ;

    // �t�H�O�̐F�����F�ɂ���
    SetFogColor( 0, 0, 0 ) ;

    // �t�H�O�̊J�n�������O�A�I���������P�T�O�O�ɂ���
    SetFogStartEnd( 0.0f, 1500.0f ) ;

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // �R�c���f�������X�ɉ�ʂ��痣���Ȃ���S�̕`�悷��
    for( i = 0 ; i < 4 ; i ++ )
    {
        // ���f���̍��W���Z�b�g
        MV1SetPosition( ModelHandle, VGet( 700.0f, -300.0f, 200.0f + i * 400.0f ) ) ;
        
        // ���f����`��
        MV1DrawModel( ModelHandle ) ;
    }

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // �L�[�̓��͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
