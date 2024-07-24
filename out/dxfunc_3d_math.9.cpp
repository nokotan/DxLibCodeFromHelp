#include "DxLib.h"

int main()
{
    VECTOR Vect ;
    MATRIX Matrix ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // Vect �ɒl����
    Vect = VGet( 100.0f, 200.0f, 500.0f ) ;

    // 0.5�{�X�P�[�����O���s���s����쐬
    Matrix = MGetScale( VGet( 0.5f, 0.5f, 0.5f ) ) ;

    // 0.5�{�X�P�[�����O���s���s����g�p���ăx�N�g���̃T�C�Y��0.5�{�������ʂ� Vect �ɑ������
    Vect = VTransform( Vect, Matrix ) ;

    // Vect �̒l����ʂɕ\��
    DrawFormatString( 0, 0, GetColor( 255,255,255 ), "Vect  x=%f y=%f z=%f", Vect.x, Vect.y, Vect.z ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
