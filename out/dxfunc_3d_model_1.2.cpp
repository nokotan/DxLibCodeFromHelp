#include "DxLib.h"

int main()
{
    int ModelHandle, AttachIndex ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // ��ʂɉf��ʒu�ɂR�c���f�����ړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, -300.0f, 600.0f ) ) ;

    // �R�c���f���̂O�Ԗڂ̃A�j���[�V�������A�^�b�`����
    AttachIndex = MV1AttachAnim( ModelHandle, 0, -1, FALSE ) ;

    // �A�^�b�`�����A�j���[�V�����̍Đ����Ԃ� 10000.0f �ɂ���
    MV1SetAttachAnimTime( ModelHandle, AttachIndex, 10000.0f ) ;

    // �R�c���f���̕`��
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
