#include "DxLib.h"

int main()
{
    char Name[ 31 ] ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() == -1 ) return -1 ;
        
    // ���O���͎w��������̕`��
    DrawString( 0 , 0 , "���O���p���œ��͂��Ă�������" , GetColor( 255 , 255 , 255 ) ) ;

    // ���O�̓���
    KeyInputSingleCharString( 0 , 16 , 30 , Name , FALSE ) ;

    // ��ʂ̏�����
    ClearDrawScreen() ;

    // ���O�̕\��
    DrawString( 0 , 0 , "���Ȃ��̖��O��" , GetColor( 255 , 255 , 255 ) ) ;
    DrawString( 0 , 16 , Name ,  GetColor( 255 , 255 , 255 ) ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̎g�p�I��
    DxLib_End() ;

    // �I��
    return 0 ;
}
