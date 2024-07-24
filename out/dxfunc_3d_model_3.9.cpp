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
    ModelHandle = MV1LoadModel( "BackCulling.mqo" ) ;

    // �o�b�N�J�����O����Ă���̂��킩��Ղ��悤�ɉ�ʑS�̂�œh��Ԃ�
    DrawBox( 0, 0, 640, 480, GetColor( 0,0,255 ), TRUE ) ;

    // ��ʂɉf��ʒu�ɂR�c���f�����ړ�
    MV1SetPosition( ModelHandle, VGet( 490.0f, 50.0f, 600.0f ) ) ;

    // �ŏ��͉��������ɂR�c���f����`��
    MV1DrawModel( ModelHandle ) ;

    // �ŏ��̈ʒu���班���ړ�
    MV1SetPosition( ModelHandle, VGet( 50.0f, 50.0f, 600.0f ) ) ;

    // �R�c���f���Ɋ܂܂��O�Ԗڂ̃o�b�N�J�����O�𖳌��ɂ���
    MV1SetMeshBackCulling( ModelHandle, 0, FALSE ) ;

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
