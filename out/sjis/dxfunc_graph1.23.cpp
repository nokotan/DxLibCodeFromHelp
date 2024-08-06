#include "DxLib.h"

int main()
{
    int Handle ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
        return -1 ;

    // �摜��ǂݍ���
    Handle = LoadGraph( "Src1.bmp" ) ;

    // ���m�g�[���t�B���^�[�ŃZ�s�A���̉摜�ɕϊ�
    GraphFilter( Handle, DX_GRAPH_FILTER_MONO, -60, 7 ) ;

    // �摜����ʂɕ`��
    DrawGraph( 0, 0, Handle, FALSE ) ;

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( Handle ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    return 0 ;
}