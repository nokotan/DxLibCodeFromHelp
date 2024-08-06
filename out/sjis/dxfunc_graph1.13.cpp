#include "DxLib.h"

int main()
{
    int Graph, Graph2 ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() == -1 ) return -1 ;

    // �O���t�B�b�N�̃��[�h
    Graph = LoadGraph( "testDiv.bmp" ) ;

    // Graph ���� (0,32)-(32,64) �̕����𔲂��o���A�V����
    // �O���t�B�b�N�n���h�����쐬
    Graph2 = DerivationGraph( 0, 32, 32, 32, Graph ) ;

    // �V���ɍ쐬�����O���t�B�b�N�n���h���ŕ`��
    DrawGraph( 100, 100, Graph2, TRUE ) ;

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( Graph2 ) ;
    DeleteGraph( Graph ) ;

    // �L�[�̓��͑҂�
    WaitKey() ;

    // �c�w���C�u�����g�p�̏I������
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
