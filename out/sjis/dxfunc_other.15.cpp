#include "DxLib.h"

int main()
{
    int handle, i, j, w, h, r, g, b, a ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 ) return -1;

    // �摜�̓ǂݍ���
    handle = LoadSoftImage( "Test1.bmp" ) ;

    // �摜�̃T�C�Y���擾
    GetSoftImageSize( handle, &w, &h ) ;

    // �摜�̐F���P�h�b�g�ÂQ�Ƃ��� DrawBox �łR�{�̑傫���ɂ��ĕ`��
    for( i = 0; i < h; i ++ )
    {
        for( j = 0; j < w; j ++ )
        {
            // �P�h�b�g�̐F���擾
            GetPixelSoftImage( handle, j, i, &r, &g, &b, &a ) ;

            // DrawBox �ŕ`��
            DrawBox( j * 3, i * 3, j * 3 + 3, i * 3 + 3, GetColor( r, g, b ), TRUE ) ;
        }
    }

    // �g���I���������
    DeleteSoftImage( handle ) ;

    // �L�[���͑҂�
    WaitKey();

    // �c�w���C�u�����̌�n��
    DxLib_End();

    // �\�t�g�̏I��
    return 0;
}
