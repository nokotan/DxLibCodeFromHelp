#include "DxLib.h"

int main()
{
    int handle, i, j, w, h, r, g, b, a ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 ) return -1;

    // �摜�� ARGB8 �`���œǂݍ���
    handle = LoadARGB8ColorSoftImage( "Test1.bmp" ) ;

    // �摜�̃T�C�Y���擾
    GetSoftImageSize( handle, &w, &h ) ;

    // �摜�̑S�s�N�Z���̃A���t�@�l�� 128 �ɂ���
    for( i = 0; i < h; i ++ )
    {
        for( j = 0; j < w; j ++ )
        {
            // �P�h�b�g�̐F���擾
            GetPixelSoftImage( handle, j, i, &r, &g, &b, &a ) ;

            // �A���t�@�l�� 128 �ɂ��ď�������
            DrawPixelSoftImage( handle, j, i, r, g, b, 128 ) ;
        }
    }

    // ��ʂɉ摜��`��
    DrawSoftImage( 0, 0, handle ) ;

    // �g���I���������
    DeleteSoftImage( handle ) ;

    // �L�[���͑҂�
    WaitKey();

    // �c�w���C�u�����̌�n��
    DxLib_End();

    // �\�t�g�̏I��
    return 0;
}
