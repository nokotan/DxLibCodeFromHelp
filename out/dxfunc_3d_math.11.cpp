#include "DxLib.h"

int main()
{
    MATRIX Matrix ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �P�ʍs��� Matrix �ɑ��
    Matrix = MGetIdent() ;

    // Matrix �̒l����ʂɕ\��
    DrawFormatString( 0,  0, GetColor( 255,255,255 ), "m00 %f  m01 %f  m02 %f  m03 %f",
        Matrix.m[0][0], Matrix.m[0][1], Matrix.m[0][2], Matrix.m[0][3] ) ;

    DrawFormatString( 0, 16, GetColor( 255,255,255 ), "m10 %f  m11 %f  m12 %f  m13 %f",
        Matrix.m[1][0], Matrix.m[1][1], Matrix.m[1][2], Matrix.m[1][3] ) ;

    DrawFormatString( 0, 32, GetColor( 255,255,255 ), "m20 %f  m21 %f  m22 %f  m23 %f",
        Matrix.m[2][0], Matrix.m[2][1], Matrix.m[2][2], Matrix.m[2][3] ) ;

    DrawFormatString( 0, 48, GetColor( 255,255,255 ), "m30 %f  m31 %f  m32 %f  m33 %f",
        Matrix.m[3][0], Matrix.m[3][1], Matrix.m[3][2], Matrix.m[3][3] ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
