#include "DxLib.h"

int main()
{
    int GHandle ;

    // ��ʃ��[�h�̐ݒ�
    SetGraphMode( 800 , 600 , 32 ) ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[������������I��
    }

    // test.bmp�̓ǂݍ���
    GHandle = LoadGraph( "test1.bmp" ) ;

    // �O���t�B�b�N�̕`��
    DrawGraph( 0 , 0 , GHandle , FALSE ) ;

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( GHandle ) ;

    // �L�[�҂�(�wWaitKey�x���g�p)
    WaitKey() ;

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
