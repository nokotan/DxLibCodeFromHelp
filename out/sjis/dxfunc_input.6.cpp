#include "DxLib.h"

int main()
{
    char StrBuf[ 128 ] , StrBuf2[ 32 ];
    int MouseX , MouseY ;
    int StringCr , BoxCr ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // �}�E�X��\����Ԃɂ���
    SetMouseDispFlag( TRUE ) ;

    // ���F�̒l���擾
    StringCr = GetColor( 255 , 255 , 255 ) ;

    // ���̒l���擾
    BoxCr = GetColor( 0 , 0 , 0 ) ;

    // �L�[���������܂Ń��[�v
    while( CheckHitKeyAll() == 0 )
    {
        // �}�E�X�̈ʒu���擾
        GetMousePoint( &MouseX , &MouseY ) ;

        // ��ʍ���̗̈�ɍ����l�p��`���O�ɕ`���Ă����������������
        DrawBox( 0 , 0 , 640 , 32 , BoxCr , TRUE ) ;

        // ���W�������`��
        DrawFormatString( 0 , 0 , StringCr , "���W�w %d�@�@���W�x %d" , MouseX , MouseY ) ;
                
        // ���b�Z�[�W����
        if( ProcessMessage() == -1 )
        {
            break ;    // �G���[���N�����烋�[�v�𔲂���
        }

        // ��莞�ԑ҂�
        WaitTimer( 100 ) ;
    }

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
