#include "DxLib.h"

int main()
{
    int Start , Time ;
    unsigned int Cr ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() == -1 ) return 0;

    // ���̐F�R�[�h��ۑ�
    Cr = GetColor( 255 , 255, 255 ) ;

    // �X�^�[�g�^�C�����擾
    Start = GetNowCount() ;

    // ���b�Z�[�W��\��
    DrawString( 0 , 0 , "�Ȃɂ��L�[�������Ă�������" , Cr ) ;

    // �{�^�����������܂ő҂�
    WaitKey() ;

    // �I���A�o�ߎ��Ԃ��Z�o
    Time = GetNowCount() - Start ;

    // ��ʂɕ\��
    ClearDrawScreen() ;
    DrawFormatString( 0, 0, Cr, "�{�^�����������܂ł� %d�~���b�o�߂��܂���", Time ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����g�p�̏I��
    DxLib_End() ;

    return 0 ;
}
