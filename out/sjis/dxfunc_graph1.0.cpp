#include "DxLib.h"

int main()
{
    if( DxLib_Init() == -1 )        // �c�w���C�u��������������
    {
         return -1;        // �G���[���N�����璼���ɏI��
    }

    // �a�l�o�摜�̕\��
    LoadGraphScreen( 0 , 0 , "test1.bmp" , TRUE ) ;

    WaitKey() ;            // �L�[�̓��͑҂�(�wWaitKey�x���g�p)

    DxLib_End() ;            // �c�w���C�u�����g�p�̏I������

    return 0 ;            // �\�t�g�̏I��
}
