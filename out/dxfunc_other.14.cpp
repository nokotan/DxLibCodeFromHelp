#include "DxLib.h"

int main()
{
    char String[256] ;
    int FileHandle, y ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() == -1 ) return -1 ;

    // test.cpp ���J��
    FileHandle = FileRead_open( "test.cpp" ) ;

    // �\���x���W�̏�����
    y = 0 ;

    // �t�@�C���̏I�[������܂ŕ\������
    while( FileRead_eof( FileHandle ) == 0 )
    {
        // ��s�ǂݍ���
        FileRead_gets( String, 256, FileHandle ) ;

        // ��ʂɕ`��
        DrawString( 0, y, String, GetColor( 255,255,255 ) ) ;

        // �\���x���W�����ɂ��炷
        y += 16 ;
    }

    // �t�@�C�������
    FileRead_close( FileHandle ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    return 0 ;
}
