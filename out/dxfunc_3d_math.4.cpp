#include "DxLib.h"

int main()
{
    VECTOR Vect1, Vect2 ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // Vect1 �� Vect2 �ɒl����
    Vect1 = VGet( 100.0f, 200.0f, 500.0f ) ;
    Vect2 = VGet( 30.0f, 100.0f, 80.0f ) ;

    // Vect1 �� Vect2 �̊O�ʂ� Vect1 �ɑ��
    Vect1 = VCross( Vect1, Vect2 ) ;

    // Vect1 �̓��e����ʂɕ\��
    DrawFormatString( 0, 0, GetColor( 255,255,255 ), "Vect1  x=%f y=%f z=%f", Vect1.x, Vect1.y, Vect1.z ) ;  

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
