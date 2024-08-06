#include "DxLib.h"

int main()
{
    int CharBytes ;
    int CharNum ;
    int i ;
    const char *String = "a��b��c��d��e��" ;

    // �E�C���h�E���[�h�ŋN��
    ChangeWindowMode( TRUE ) ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 ) return -1 ;

    // �����̐��𐔂���
    i = 0 ;
    CharNum = 0 ;
    while( String[ i ] != '\0' )
    {
        // �����̃o�C�g�����擾
        CharBytes = GetCharBytes( DX_CHARCODEFORMAT_SHIFTJIS, &String[ i ] ) ;

        // �����̐��𑝂₷
        CharNum ++ ;

        // ���ׂ�ʒu���ړ�����
        i += CharBytes ;
    }

    // ���ʂ�\��
    DrawFormatString( 0, 0, GetColor( 255,255,255 ), "�u%s�v�̕������� %d �ł�", String, CharNum ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End();

    // �\�t�g�̏I��
    return 0;
}
