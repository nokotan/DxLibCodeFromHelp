#include "DxLib.h"

int main()
{
    // �c�w���C�u�����̏�����
    if( DxLib_Init() == -1 ) return 0 ;

    // ��ʂ����F�œh��Ԃ��܂�
    DrawBox( 0 , 0 , 640 , 480 , GetColor( 128,128, 0) , TRUE ) ;

    // �T�C�Y���S�O�ɕύX
    SetFontSize( 40 ) ;

    // �w�c�w���C�u�����x�ƕ`��
    DrawString( 100 , 100 , "�c�w���C�u����" , GetColor( 255,255,255 ) ) ;

    // �t�H���g�̃^�C�v���G�b�W���A���`�G�C���A�X�t�H���g�ɕύX
    ChangeFontType( DX_FONTTYPE_ANTIALIASING_EDGE ) ;

    // �w�c�w���C�u�����x�ƕ`��
    DrawString( 100 , 160 , "�c�w���C�u����" , GetColor( 255,255,255 ), GetColor( 0,0,0 ) ) ;


    // �L�[���͂�҂�
    WaitKey() ;


    // �c�w���C�u�����̏I��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
