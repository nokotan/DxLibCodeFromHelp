#include "DxLib.h"

#define PI    3.1415926535897932384626433832795f
    
int main()
{
    int GHandle ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // test1.bmp�̓ǂݍ���
    GHandle = LoadGraph( "test1.bmp" ) ;

    // �ǂ݂��񂾃O���t�B�b�N����]�`��
    DrawRotaGraph( 320 , 240 , 1.5f , PI / 2 , GHandle , TRUE ) ;

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( GHandle ) ;

    WaitKey() ;        // ���ʂ����邽�߂ɃL�[�҂�(�wWaitKey�x���g�p)

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
