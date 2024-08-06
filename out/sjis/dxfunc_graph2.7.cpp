#include "DxLib.h"

int main()
{
    int FontHandle ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() == -1 ) return 0 ;


    // �@�f�t�H���g�̃t�H���g�ŁA�T�C�Y�S�O�A�����R�̃t�H���g���쐬��
    // �쐬�����f�[�^�̎��ʔԍ���ϐ� FontHandle �ɕۑ�����
    FontHandle = CreateFontToHandle( NULL , 40 , 3 ) ;

    // �쐬�����t�H���g�ŉ�ʍ���Ɂw�g�����������I�I�x�Ɣ��F�̕������`�悷��
    DrawStringToHandle( 0 , 0 , "�g�d�k�k�n�v�I�I" , GetColor( 255 , 255 , 255 ) , FontHandle ) ;

    // ���ɕW���t�H���g�f�[�^�ŉ�ʂɁw�n�j�H�x�Ƃ����������`�悷��
    DrawString( 0 , 50 , "�n�j�H" , GetColor( 255 , 128 , 100 ) ) ; 


    // �L�[���͂�҂�
    WaitKey() ;

    // �쐬�����t�H���g�f�[�^���폜����
    DeleteFontToHandle( FontHandle ) ;


    // �c�w���C�u�����̏I��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
