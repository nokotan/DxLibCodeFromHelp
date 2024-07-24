#include "DxLib.h"

int main()
{
    int FontHandle ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
         return -1;    // �G���[���N�����璼���ɏI��

    // �c�����t�H���g���쐬
    FontHandle = CreateFontToHandle( "@�l�r ����", -1, -1, -1 ) ;

    // ��������c����
    DrawVStringToHandle( 0, 0, "�c�����t�H���g", GetColor( 255,255,255 ), FontHandle ) ;

    // �쐬�����t�H���g�n���h�����폜����
    DeleteFontToHandle( FontHandle ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    return 0 ;
}
