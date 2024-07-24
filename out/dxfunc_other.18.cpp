#include "DxLib.h"

int main()
{
    int handle, i, j, grhandle ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 ) return -1;

    // ��̃t���J���[�摜���쐬����
    handle = MakeARGB8ColorSoftImage( 256, 256 ) ;

    // �c�����ɓ����O���f�[�V���������^���Ԃȉ摜���쐬����
    for( i = 0; i < 256; i ++ )
    {
        for( j = 0; j < 256; j ++ )
        {
            // �F���Z�b�g
            DrawPixelSoftImage( handle, j, i, 255, 0, 0, i ) ;
        }
    }

    // �������ǂ����킩��悤�ɉ�ʂ�΂œh��Ԃ�
    DrawBox( 0, 0, 640, 480, GetColor( 0, 255, 0 ), TRUE ) ;

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
