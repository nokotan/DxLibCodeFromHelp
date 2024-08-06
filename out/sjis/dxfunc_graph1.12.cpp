#include "DxLib.h"

int main()
{
    int GHandle ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() == -1 ) return -1 ;

    // �O���t�B�b�N�̃��[�h
    GHandle = LoadGraph( "testDiv.bmp" ) ;

    // �O���t�B�b�N����(32,32)-(64,64)�̕�������ʍ��W(100,100)��
    // ���ߐF��������A���]�����Ȃ��ŕ`��
    DrawRectGraph( 100, 100, 32, 32, 32, 32, GHandle, TRUE, FALSE ) ;

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( GHandle ) ;

    // �L�[�̓��͑҂�
    WaitKey() ;

    // �c�w���C�u�����g�p�̏I������
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
