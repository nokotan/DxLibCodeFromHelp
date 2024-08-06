#include "DxLib.h"

int main()
{
    VECTOR Vect ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // Vect �ɒl����
    Vect = VGet( 100.0f, 200.0f, 500.0f ) ;

    // Vect �̃T�C�Y�̓�����ʂɕ\��
    DrawFormatString( 0, 0, GetColor( 255,255,255 ), "Size  %f", VSquareSize( Vect ) ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
