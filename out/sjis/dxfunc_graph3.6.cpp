#include "DxLib.h"

int main()
{
    int i ;
    unsigned int Cr ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[������������I��
    }

    // ���F�̒l���擾
    Cr = GetColor( 255 , 255 , 255 ) ;

    // �P�O�O�O�̓_��`��
    for( i = 0 ; i < 1000 ; i ++ )
    {
        // �����_���Ȉʒu�ɓ_��`���i�wGetRand�x���g�p�j 
        DrawPixel( GetRand( 639 ) , GetRand( 479 ) , Cr ) ;
    }

    WaitKey() ;        // ���ʂ����邽�߂ɃL�[�҂�(�wWaitKey�x���g�p)

    // ��ʂ�������
    ClearDrawScreen() ;

    WaitKey() ;        // �L�[�̓��͑҂�(�wWaitKey�x���g�p)

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
