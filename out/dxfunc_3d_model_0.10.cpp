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

    // �Q�{�Ɋg�債�����ʂɉf��ʒu�ɂR�c���f�����ړ�����s��̃Z�b�g
    MV1SetMatrix( ModelHandle, MMult( MGetScale( VGet( 2.0f, 2.0f, 2.0f ) ), MGetTranslate( VGet( 320.0f, -600.0f, 600.0f ) ) ) ) ;

    // �R�c���f����`��
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
