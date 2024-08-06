#include "DxLib.h"

int main()
{
    MATRIX Matrix, Matrix2 ;
    VECTOR Vect1, Vect2, Vect3 ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // ���s�ړ�����s��� Matrix2 �ɑ��
    Matrix2 = MGetTranslate( VGet( 200.0f, 100.0f, 80.0f ) ) ;

    // Matrix2 �̋t�s��� Matrix �ɑ��
    Matrix = MInverse( Matrix2 ) ;

    // �K���Ȓl�� Vect1 �ɑ��
    Vect1 = VGet( 200.0f, 0.0f, 0.0f ) ;

    // Vect1 �� Matrix2 ���g�p���ĕϊ������l�� Vect2 �ɑ��
    Vect2 = VTransform( Vect1, Matrix2 ) ;

    // Vect2 �� Matrix2 �̋t�s��ł��� Matrix �ŕϊ��������̂� Vect3 �ɑ��
    Vect3 = VTransform( Vect2, Matrix ) ;

    // Matrix2 �̒l����ʂɕ\��
    DrawString( 0, 0, "���s�ړ��s��", GetColor( 255,255,255 ) ) ;
    DrawFormatString( 0, 16, GetColor( 255,255,255 ), "m00 %f  m01 %f  m02 %f  m03 %f",
        Matrix2.m[0][0], Matrix2.m[0][1], Matrix2.m[0][2], Matrix2.m[0][3] ) ;

    DrawFormatString( 0, 32, GetColor( 255,255,255 ), "m10 %f  m11 %f  m12 %f  m13 %f",
        Matrix2.m[1][0], Matrix2.m[1][1], Matrix2.m[1][2], Matrix2.m[1][3] ) ;

    DrawFormatString( 0, 48, GetColor( 255,255,255 ), "m20 %f  m21 %f  m22 %f  m23 %f",
        Matrix2.m[2][0], Matrix2.m[2][1], Matrix2.m[2][2], Matrix2.m[2][3] ) ;

    DrawFormatString( 0, 64, GetColor( 255,255,255 ), "m30 %f  m31 %f  m32 %f  m33 %f",
        Matrix2.m[3][0], Matrix2.m[3][1], Matrix2.m[3][2], Matrix2.m[3][3] ) ;

    // Matrix �̒l����ʂɕ\��
    DrawString( 0, 192, "�t�s��", GetColor( 255,255,255 ) ) ;
    DrawFormatString( 0, 208, GetColor( 255,255,255 ), "m00 %f  m01 %f  m02 %f  m03 %f",
        Matrix.m[0][0], Matrix.m[0][1], Matrix.m[0][2], Matrix.m[0][3] ) ;

    DrawFormatString( 0, 224, GetColor( 255,255,255 ), "m10 %f  m11 %f  m12 %f  m13 %f",
        Matrix.m[1][0], Matrix.m[1][1], Matrix.m[1][2], Matrix.m[1][3] ) ;

    DrawFormatString( 0, 240, GetColor( 255,255,255 ), "m20 %f  m21 %f  m22 %f  m23 %f",
        Matrix.m[2][0], Matrix.m[2][1], Matrix.m[2][2], Matrix.m[2][3] ) ;

    DrawFormatString( 0, 256, GetColor( 255,255,255 ), "m30 %f  m31 %f  m32 %f  m33 %f",
        Matrix.m[3][0], Matrix.m[3][1], Matrix.m[3][2], Matrix.m[3][3] ) ;

    // �ϊ����̃x�N�g���l Vect1 ����ʂɕ\��
    DrawString( 0, 288, "�ϊ��O�̃x�N�g��", GetColor( 255,255,255 ) ) ;
    DrawFormatString( 0, 304, GetColor( 255,255,255 ), "x=%f y=%f z=%f", Vect1.x, Vect1.y, Vect1.z ) ;

    // �ϊ���̃x�N�g���l Vect2 ����ʂɕ\��
    DrawString( 0, 336, "���s�ړ���̃x�N�g��", GetColor( 255,255,255 ) ) ;
    DrawFormatString( 0, 352, GetColor( 255,255,255 ), "x=%f y=%f z=%f", Vect2.x, Vect2.y, Vect2.z ) ;

    // �ϊ���̃x�N�g���l Vect3 ����ʂɕ\��
    DrawString( 0, 384, "�t�s���Z��̃x�N�g��", GetColor( 255,255,255 ) ) ;
    DrawFormatString( 0, 400, GetColor( 255,255,255 ), "x=%f y=%f z=%f", Vect3.x, Vect3.y, Vect3.z ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
