#include "DxLib.h"

int main()
{
    int GHandle , GHandle2 ;
    int i ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // test1.bmp�̓ǂݍ���
    GHandle = LoadGraph( "test1.bmp" ) ;

    // �K���ȍ��W�ɂP�O��`��
    for( i = 0 ; i < 10 ; i ++ )
    {
        // �摜�������_���ȍ��W�ɕ`�悷��(�wGetRand�x�g�p)
        DrawGraph( GetRand( 639 ), GetRand( 479 ), GHandle, TRUE ) ;
    }

    // ��̃O���t�B�b�N���쐬
    GHandle2 = MakeGraph( 128 , 128 ) ;

    // �K���ȗ̈����肱��
    GetDrawScreenGraph( 156 , 24 , 156 + 128 , 24 + 128 , GHandle2 ) ;
                
    // ��荞�񂾉摜�łP�O��`�� 
    for( i = 0 ; i < 10 ; i ++ )
    {
        // �摜�������_���ȍ��W�ɕ`�悷��(�wGetRand�x�g�p)
        DrawGraph( GetRand( 639 ), GetRand( 479 ), GHandle2, TRUE ) ;
    }

    // �S�O���t�B�b�N��������
    InitGraph() ;
                
    WaitKey() ;        // ���ʂ����邽�߂ɃL�[�҂�(�wWaitKey�x���g�p)

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
