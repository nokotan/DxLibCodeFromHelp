#include <string.h> 
#include "DxLib.h"

int main()
{
    int StrWidth , StrLen ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() == -1 ) return -1 ;

    // �ŏ��̕������`��
    DrawString( 0 , 0 , "�����������V�C��" , GetColor( 255 , 255 , 255 ) ) ;

    // ������̒������擾
    StrLen = strlen( "�����������V�C��" ) ;

    // �`�掞�̕�����̕����擾
    StrWidth = GetDrawStringWidth( "�����������V�C��" , StrLen ) ;

    // �u�����������V�C���v�̒���ɐV���ȕ������`��
    DrawString( StrWidth , 0 , "�����������Ɨǂ��Ȃ�" , GetColor( 255 , 255 , 255 ) ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̎g�p�I��
    DxLib_End() ;

    // �I��
    return 0 ;
}
