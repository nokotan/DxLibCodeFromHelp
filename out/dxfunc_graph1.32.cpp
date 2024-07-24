#include "DxLib.h"

int main()
{
    int SrcHandle ;
    int DestHandle ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
        return -1 ;

    // �摜��ǂݍ���
    SrcHandle = LoadGraph( "Src1.bmp" ) ;

    // �o�͐�Ɏg�p����O���t�B�b�N�n���h�����쐬
    DestHandle = MakeScreen( 256, 256, FALSE ) ;

    // ���m�g�[���t�B���^�[�ŃZ�s�A���̉摜�ɕϊ�
    GraphFilterBlt( SrcHandle, DestHandle, DX_GRAPH_FILTER_MONO, -60, 7 ) ;

    // �摜����ʂɕ`��
    DrawGraph( 0, 0, DestHandle, FALSE ) ;

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( SrcHandle ) ;

    // MakeScreen �ō쐬�����O���t�B�b�N�n���h���̍폜
    DeleteGraph( DestHandle ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    return 0 ;
}
