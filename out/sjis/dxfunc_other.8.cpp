#include "DxLib.h"

int main()
{
    // �^�C�g���� test �ɕύX
    SetMainWindowText( "test" ) ;

    // �E�C���h�E���[�h�ɕύX
    ChangeWindowMode( TRUE ) ;

    // �c�w���C�u��������������
    if( DxLib_Init() == -1 )
         return -1;    // �G���[���N�����璼���ɏI��

    // �L�[�̓��͑҂�(�wWaitKey�x���g�p)
    WaitKey() ;

    // �c�w���C�u�����g�p�̏I������
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
