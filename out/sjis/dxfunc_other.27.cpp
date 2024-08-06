#include "DxLib.h"
#include <malloc.h>

int main()
{
    char *NameBuffer ;
    int FontNum ;
    int i ;

    // �c�w���C�u��������������
    if( DxLib_Init() == -1 ) return -1 ;

    // �t�H���g�̐����擾
    FontNum = EnumFontName( NULL , 0 ) ;

    // �������̊m��
    NameBuffer = ( char * )malloc( FontNum * 64 ) ;

    // �t�H���g���̎擾
    EnumFontName( NameBuffer , FontNum ) ;

    // �t�H���g�̃T�C�Y��ύX
    SetFontSize( 32 ) ;

    // �ŏ�����P�O�Ԗڂ܂ł̃t�H���g������ʂɕ`��
    if( FontNum >= 10 ) FontNum = 10 ;
    for( i = 0 ; i < FontNum ; i ++ )
    {
        // �t�H���g�̕ύX
        ChangeFont( NameBuffer + 64 * i ) ;

        // �t�H���g���̕`��
        DrawString( 100 , i * 40 , NameBuffer + 64 * i , GetColor( 255, 255, 255 ) ) ;
    }

    // �m�ۂ����������̉��
    free( NameBuffer ) ;

    // �L�[���͂�҂�
    WaitKey() ;

    // �c�w���C�u�����g�p�̏I������
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
