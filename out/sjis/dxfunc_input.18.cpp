#include "DxLib.h"

int main()
{
    int LineLength ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() == -1 ) return -1 ;

    // ���̒������͎w��������̕`��
    DrawString( 0 , 0 , "���̒�������͂��Ă�������(�O�`�U�S�O)" , GetColor( 255 , 255 , 255 ) ) ;

    // ���̒�������
    LineLength = KeyInputNumber( 0 , 16 , 640 , 0 , FALSE ) ;

    // ��ʂ̏�����
    ClearDrawScreen() ;

    // ���̕`��
    DrawLine( 0 , 100 , LineLength , 100 , GetColor( 255 , 255 , 255 ) ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̎g�p�I��
    DxLib_End() ;

    // �I��
    return 0 ;
}
