#include "DxLib.h"

int main()
{
    int GHandle[ 10 ] ;
    int i ;

    if( DxLib_Init() == -1 )        // �c�w���C�u��������������
    {
         return -1;        // �G���[���N�����璼���ɏI��
    }

    // �a�l�o�摜�̃������ւ̕����ǂݍ���
    LoadDivGraph( "test2.bmp" , 10 , 4 , 3 , 48 , 56 , GHandle ) ;

    // ���[�h�����O���t�B�b�N�̃A�j���[�V����
    i = 0 ;
    // �L�[���������܂Ń��[�v(�L�[����ɂ́wCheckHitKeyAll�x���g�p)
    while( CheckHitKeyAll() == 0 )
    {
        // �O���t�B�b�N�̕`��(�wDrawGraph�x�g�p)
        DrawGraph( 0 , 0 , GHandle[ i ] , FALSE ) ;

        // �A�j���[�V�����p�^�[���i���o�[��ύX
        i ++ ;
        if( i == 10 ) i = 0 ;

        // ��莞�ԑ҂�(�wWaitTimer�x�g�p)
        WaitTimer( 100 ) ;

        // ���b�Z�[�W����
        if( ProcessMessage() == -1 )
        {
            break ;        // �G���[���N�����烋�[�v���甲����
        }
    }

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    for( i = 0 ; i < 10 ; i ++ )
    {
        DeleteGraph( GHandle[ i ] ) ;
    }

    DxLib_End() ;            // �c�w���C�u�����g�p�̏I������

    return 0 ;            // �\�t�g�̏I��
}
