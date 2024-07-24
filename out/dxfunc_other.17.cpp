#include "DxLib.h"

int main()
{
    int handle, i, j, w, h, r, g, b, a, fhandle ;
    void *image ;
    int image_size ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 ) return -1;

    // �摜�t�@�C�����ۂ��ƃ������ɓǂݍ���
    fhandle = FileRead_open( "test1.bmp" ) ;
    image_size = FileRead_size( "test1.bmp" ) ;
    image = malloc( image_size ) ;
    FileRead_read( image, image_size, fhandle ) ;
    FileRead_close( fhandle ) ;

    // LoadSoftImageToMem �œǂݍ���
    handle = LoadSoftImageToMem( image, image_size ) ;

    // �ǂݍ���ł��܂�����̓t�@�C���C���[�W�͕K�v�Ȃ�
    free( image ) ;

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
