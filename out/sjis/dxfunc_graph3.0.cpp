#include "DxLib.h"

int main()
{
    // �c�w���C�u����������
    if( DxLib_Init() == -1 ) return 0;

    // �g�������� �b �v���������I�ƕ\���A�Ō�ɉ��s
    printfDx( "Hello �b World!\n" ) ;

    // ��ʂɓK���ɐ��l��`��
    printfDx( " 600 x 800 = %d \n" , 600 * 800 ) ;

    // ��ʂ��~��؂��قǕ������`��
    printfDx( "������������������������������������" ) ;
    printfDx( "������������������������������������" ) ;
    printfDx( "����������������������������������������" ) ;

    // ��ʂ������
    DrawBox( 0 , 0 , 640 , 480 , GetColor( 0 , 0 , 255 ) , TRUE ) ;

    // �o�͂����������\��
    ScreenFlip() ;

    // �L�[���������܂ő҂�
    WaitKey() ;

    // �c�w���C�u�����̎g�p�I��
    DxLib_End() ;

    return 0 ;
}
