#include "DxLib.h"

int main()
{
    // �c�w���C�u����������
    if( DxLib_Init() == -1 ) return 0;

    // �`����ʂ𗠉�ʂɂ���
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // �Ȃɂ��L�[���������܂Ń��[�v
    while( CheckHitKeyAll() == 0 )
    {
        // �g�������� �b �v���������I�ƕ\��
        printfDx( "Hello C World" ) ;

        // ��ʂ������
        DrawBox( 0 , 0 , 640 , 480 , GetColor( 0 , 0 , 255 ) , TRUE ) ;

        // �o�͂����������\��
        ScreenFlip() ;

        // Windows�ˑ�����
        if( ProcessMessage() == -1 ) break ;
    }

    // ��ʂ̕����B������
    clsDx() ;

    // ��ʂɃ��b�Z�[�W��\��
    printfDx( "�����܂������H" ) ;

    // ��ʂ�Ԃ�����
    DrawBox( 0 , 0 , 640 , 480 , GetColor( 255 , 0 , 0 ) , TRUE ) ;

    // ��ʂ̏�Ԃ��X�V
    ScreenFlip() ;

    // �L�[���������܂ő҂�
    WaitKey() ;

    // �c�w���C�u�����̎g�p�I��
    DxLib_End() ;

    return 0 ;
}
