#include "DxLib.h"

int main()
{
    int handle, i, j, r, g, b ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 ) return -1;

    // �摜�̓ǂݍ���
    handle = LoadSoftImage( "Test1.bmp" ) ;

    // �p���b�g�̈ꗗ��`��
    for( i = 0 ; i < 16 ; i ++ )
    {
        for( j = 0 ; j < 16 ; j ++ )
        {
            // �p���b�g�̐F���擾����
            GetPaletteSoftImage( handle, j + i * 16, &r, &g, &b, 0 ) ;

            // DrawBox ���g���ĕ`��
            DrawBox( j * 16, i * 16, j * 16 + 16, i * 16 + 16, GetColor( r, g, b ), TRUE ) ;
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
