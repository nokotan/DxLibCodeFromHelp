#include "DxLib.h"

int main()
{
    int GraphHandle ;

    // ��ʃ��[�h���P�U�r�b�g�J���[�ɃZ�b�g
    SetGraphMode( 640 , 480 , 16 ) ;

    // �c�w���C�u����������
    if( DxLib_Init() == -1 )    return -1 ;

    // �摜�̃��[�h
    GraphHandle = LoadGraph( "test1.bmp" ) ;

    // �`��P�x��ݒ�A�Ԑ������O�ɂ���
    SetDrawBright( 0 , 255 , 255 ) ;

    // ��ʂɕ`��
    DrawGraph( 0 , 0 , GraphHandle , FALSE ) ;

    // ��ʑS�̂� Save.bmp �Ƃ��ĕۑ�
    SaveDrawScreen( 0 , 0 , 640 , 480 , "Save.bmp" ) ;

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( GraphHandle ) ;

    // �c�w���C�u�����g�p�̏I������
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
