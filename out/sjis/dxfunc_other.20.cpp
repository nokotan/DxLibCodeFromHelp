#include "DxLib.h"

int main()
{
    int handle, i, j, grhandle ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 ) return -1;

    // ��̃p���b�g�摜���쐬����
    handle = MakePAL8ColorSoftImage( 256, 256 ) ;

    // �p���b�g�O����Q�T�T�Ɋ|���ėΐF�̃O���f�[�V�������Z�b�g����
    for( i = 0 ; i < 256 ; i ++ )
        SetPaletteSoftImage( handle, i, 0, i, 0, 0 ) ;

    // �c�����ɍ�����ԂɃO���f�[�V���������摜���쐬����
    for( i = 0; i < 256; i ++ )
    {
        for( j = 0; j < 256; j ++ )
        {
            // �p���b�g�ԍ����Z�b�g
            DrawPixelPalCodeSoftImage( handle, j, i, i ) ;
        }
    }

    // �O���t�B�b�N�n���h�����쐬
    grhandle = CreateGraphFromSoftImage( handle ) ;

    // �g���I���������
    DeleteSoftImage( handle ) ;

    // �O���t�B�b�N�n���h����`��
    DrawGraph( 0, 0, grhandle, TRUE ) ;

    // �O���t�B�b�N�n���h���̍폜
    DeleteGraph( grhandle ) ;

    // �L�[���͑҂�
    WaitKey();

    // �c�w���C�u�����̌�n��
    DxLib_End();

    // �\�t�g�̏I��
    return 0;
}
