#include "DxLib.h"

int main()
{
    int GHandle ;

    if( DxLib_Init() == -1 )        // �c�w���C�u��������������
    {
         return -1;        // �G���[���N�����璼���ɏI��
    }

    // ���ߐF��ύX
    SetTransColor( 255 , 0 , 255 ) ;

    // �a�l�o�摜�̃������ւ̓ǂ݂���
    GHandle = LoadGraph( "test4.bmp" ) ;

    // ��ʍ���ɕ`�悵�܂�((3-7)�wDrawGraph�x���g�p)
    DrawGraph( 0 , 0 , GHandle , TRUE ) ;

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( GHandle ) ;

    // �L�[�̓��͑҂�((6-3)�wWaitKey�x���g�p)
    WaitKey() ;

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
