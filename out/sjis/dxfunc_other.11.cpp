#include "DxLib.h"

int main()
{
    int FileHandle ;
    char String[256] ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() == -1 ) return -1 ;

    // test.cpp �t�@�C�����J��
    FileHandle = FileRead_open( "test.cpp" ) ;

    // ��s�ǂ�
    FileRead_gets( String, 256, FileHandle ) ;

    // ��ʂɕ`��
    DrawString( 0, 0, String, GetColor( 255,255,255 ) ) ;

    // �L�[���͂�҂�
    WaitKey() ;

    // �t�@�C�������
    FileRead_close( FileHandle ) ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    return 0 ;
}
