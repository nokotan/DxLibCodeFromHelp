#include "DxLib.h"

int main()
{
    int Handle ;
    int GradHandle ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
        return -1 ;

    // �摜��ǂݍ���
    Handle = LoadGraph( "Src1.bmp" ) ;

    // �O���f�[�V�����}�b�v�ɂ���摜��ǂݍ���
    GradHandle = LoadGraph( "GMap.bmp" ) ;

    // �O���f�[�V�����}�b�v�t�B���^�[���{��
    GraphFilter( Handle, DX_GRAPH_FILTER_GRADIENT_MAP, GradHandle, FALSE ) ;

    // �摜����ʂɕ`��
    DrawGraph( 0, 0, Handle, FALSE ) ;

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( Handle ) ;
    DeleteGraph( GradHandle ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    return 0 ;
}
