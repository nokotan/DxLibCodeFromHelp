#include "DxLib.h"

int main()
{
    char NameBuffer[10][64] ;
    int FontNum ;

    // �c�w���C�u��������������
    if( DxLib_Init() == -1 ) return -1 ;


    // �t�H���g���ő�P�O��
    FontNum = EnumFontName( &NameBuffer[0][0] , 10 ) ;

    // �S�ȉ������t�H���g�����񋓂���Ȃ������玟�̏����͍s��Ȃ�
    if( FontNum >= 4 )
    {
        // �S�ڂɗ񋓂��ꂽ�t�H���g�������t�H���g�ɕύX
        ChangeFont( NameBuffer[3] ) ;

        // �ύX�����t�H���g�ŕ�����`�悵�A���̌�t�H���g�����`��
        DrawString( 100, 100, "�S�ڂ̃t�H���g�͂Ȃ񂾂낤" , GetColor( 255, 255, 255 ) ) ;
        DrawString( 100, 130, NameBuffer[3] , GetColor( 255, 255, 255 ) ) ;
    }

    // �L�[���͂�҂�
    WaitKey() ;

    // �c�w���C�u�����g�p�̏I������
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
