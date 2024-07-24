#include "DxLib.h"

int main()
{
    int handle, w, h, handle2 ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 ) return -1;

    // �摜�̓ǂݍ���
    handle = LoadSoftImage( "Test1.bmp" ) ;

    // �摜�̃T�C�Y���擾
    GetSoftImageSize( handle, &w, &h ) ;

    // �ǂݍ��񂾉摜�Ɠ����T�C�Y�̋�p���b�g�摜�̍쐬
    handle2 = MakePAL8ColorSoftImage( w, h ) ;

    // ��p���b�g�摜�ɓǂݍ��񂾉摜��]��
    BltSoftImage( 0, 0, w, h, handle, 0, 0, handle2 ) ;

    // ��ʂɕ`��
    DrawSoftImage( 0, 0, handle2 ) ;

    // �g���I���������
    DeleteSoftImage( handle ) ;
    DeleteSoftImage( handle2 ) ;

    // �L�[���͑҂�
    WaitKey();

    // �c�w���C�u�����̌�n��
    DxLib_End();

    // �\�t�g�̏I��
    return 0;
}
