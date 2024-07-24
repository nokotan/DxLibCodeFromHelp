#include "DxLib.h"

int main()
{
    int ModelHandle, i, ChildNum, FrameIndex ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // �t���[���O�Ԃ̎q�t���[���̐����擾
    ChildNum = MV1GetFrameChildNum( ModelHandle, 0 ) ;

    // �q�t���[���̐��������[�v
    for( i = 0 ; i < ChildNum ; i ++ )
    {
        // �q�t���[���̃t���[���ԍ����擾
        FrameIndex = MV1GetFrameChild( ModelHandle, 0, i ) ;

        // �q�t���[���̖��O��\��
        DrawFormatString( 0, i * 16, GetColor( 255,255,255 ), "%s", MV1GetFrameName( ModelHandle, FrameIndex ) ) ;
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
