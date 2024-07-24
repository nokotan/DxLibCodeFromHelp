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

    // ���f����������ʒu�Ɉړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, 240.0f, 800.0f ) ) ;

    // �Q�Ԗڂ̃t���[���ɉ��ɓ����̃��[�J���s����Z�b�g����
    MV1SetFrameUserLocalMatrix( ModelHandle, 2, MGetTranslate( VGet( 0.0f, -300.0f, 0.0f ) ) ) ; 

    // ���f����`��
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
