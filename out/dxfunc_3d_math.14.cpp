#include "DxLib.h"

int main()
{
    MATRIX Matrix ;
    VECTOR Vect1, Vect2 ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �K���Ȓl�� Vect1 �ɑ��
    Vect1 = VGet( 100.0f, 8.0f, 56.0f ) ;

    // �w����]�s��� Matrix �ɑ��( 45�x��]����s�� )
    Matrix = MGetRotX( DX_PI_F / 4.0f ) ;

    // Vect1 �� Matrix ���g�p���ĕϊ������l�� Vect2 �ɑ��
    Vect2 = VTransform( Vect1, Matrix ) ;

    // Matrix �̒l����ʂɕ\��
    DrawString( 0, 0, "�w����]�s��", GetColor( 255,255,255 ) ) ;
    DrawFormatString( 0, 16, GetColor( 255,255,255 ), "m00 %f  m01 %f  m02 %f  m03 %f",
        Matrix.m[0][0], Matrix.m[0][1], Matrix.m[0][2], Matrix.m[0][3] ) ;

    DrawFormatString( 0, 32, GetColor( 255,255,255 ), "m10 %f  m11 %f  m12 %f  m13 %f",
        Matrix.m[1][0], Matrix.m[1][1], Matrix.m[1][2], Matrix.m[1][3] ) ;

    DrawFormatString( 0, 48, GetColor( 255,255,255 ), "m20 %f  m21 %f  m22 %f  m23 %f",
        Matrix.m[2][0], Matrix.m[2][1], Matrix.m[2][2], Matrix.m[2][3] ) ;

    DrawFormatString( 0, 64, GetColor( 255,255,255 ), "m30 %f  m31 %f  m32 %f  m33 %f",
        Matrix.m[3][0], Matrix.m[3][1], Matrix.m[3][2], Matrix.m[3][3] ) ;

    // �ϊ����̃x�N�g���l Vect1 ����ʂɕ\��
    DrawString( 0, 96, "�ϊ��O�̃x�N�g��", GetColor( 255,255,255 ) ) ;
    DrawFormatString( 0, 112, GetColor( 255,255,255 ), "x=%f y=%f z=%f", Vect1.x, Vect1.y, Vect1.z ) ;

    // �ϊ���̃x�N�g���l Vect2 ����ʂɕ\��
    DrawString( 0, 144, "�ϊ���̃x�N�g��", GetColor( 255,255,255 ) ) ;
    DrawFormatString( 0, 160, GetColor( 255,255,255 ), "x=%f y=%f z=%f", Vect2.x, Vect2.y, Vect2.z ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
