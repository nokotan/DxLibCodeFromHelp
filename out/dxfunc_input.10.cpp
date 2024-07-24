#include "DxLib.h"

int main()
{
    int Rot ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
         return -1;    // �G���[���N�����璼���ɏI��

    // ����ʂ��g�p
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // ���v�l��������
    Rot = 0 ;

    // �����L�[���������܂Ń��[�v
    while( CheckHitKeyAll() == 0 )
    {
        // ���b�Z�[�W����
        if( ProcessMessage() == -1 ) break ;    // �G���[���N�����烋�[�v���甲����

        // �O�� GetMouseWheelRotVol ���Ă΂�Ă��獡��܂ł̉�]�ʂ𑫂�
        Rot += GetMouseWheelRotVol() ;

        // ��ʂ�������
        ClearDrawScreen() ;

        // ��ʂɉ�]�ʂ�`��
        DrawFormatString( 0, 0, GetColor( 255,255,255 ), "%d", Rot ) ;

        // ����ʂ̓��e��\��ʂɕ\��
        ScreenFlip() ;
    }

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
