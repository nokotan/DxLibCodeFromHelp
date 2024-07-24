#include "DxLib.h"

int main()
{
    int ModelHandle, AttachIndex ;
    float TotalTime ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // �R�c���f���̂O�Ԗڂ̃A�j���[�V�������A�^�b�`����
    AttachIndex = MV1AttachAnim( ModelHandle, 0, -1, FALSE ) ;

    // �A�j���[�V�����O�Ԃ̑����Ԃ���ʂɕ`��
    TotalTime = MV1GetAttachAnimTotalTime( ModelHandle, AttachIndex ) ;
    DrawFormatString( 0, 0, GetColor( 255,255,255 ), "%f", TotalTime ) ;

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
