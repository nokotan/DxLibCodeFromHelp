#include "DxLib.h"
#include <malloc.h>

int main()
{
    void *Buffer ;
    int FileSize, FileHandle, GrHandle ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() == -1 ) return -1 ;

    // �t�@�C���̃T�C�Y�𓾂�
    FileSize = FileRead_size( "test1.bmp" ) ;

    // �t�@�C�����i�[���郁�����̈�̊m��
    Buffer = malloc( FileSize ) ;

    // test1.bmp ���J��
    FileHandle = FileRead_open( "test1.bmp" ) ;

    // �t�@�C�����ۂ��ƃ������ɓǂݍ���
    FileRead_read( Buffer, FileSize, FileHandle ) ;

    // �t�@�C�������
    FileRead_close( FileHandle ) ;

    // �O���t�B�b�N�n���h���̍쐬
    GrHandle = CreateGraphFromMem( Buffer, FileSize ) ;

    // �������̉��
    free( Buffer ) ;

    // ��ʂɕ`��
    DrawGraph( 0, 0, GrHandle, TRUE ) ; 

    // �O���t�B�b�N�n���h���̍폜
    DeleteGraph( GrHandle ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    return 0 ;
}
