#include "DxLib.h"

int main()
{
    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
         return -1;    // �G���[���N�����璼���ɏI��

    // �c�����t�H���g���w��
    ChangeFont( "@�l�r ����" ) ;

    // ��������c����
    DrawVString( 0, 0, "�c�����t�H���g", GetColor( 255,255,255 ) ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    return 0 ;
}
