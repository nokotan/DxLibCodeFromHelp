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

    // Vect �� 8.0f �{���āA���̌��ʂ� Vect �ɑ��
    Vect = VScale( Vect, 8.0f ) ;

    // Vect �̓��e����ʂɕ\��
    DrawFormatString( 0, 0, GetColor( 255,255,255 ), "Vect  x=%f y=%f z=%f", Vect.x, Vect.y, Vect.z ) ;  

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
