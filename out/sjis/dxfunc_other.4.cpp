#include "DxLib.h"

int main()
{
    LONGLONG StartTime ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // ���݌o�ߎ��Ԃ𓾂�
    StartTime = GetNowHiPerformanceCount() ;

    // �v���J�n����U�b���߂���܂Ń��[�v
    while( GetNowHiPerformanceCount() - StartTime < 6000000 )
    {
        // ���b�Z�[�W����
        if( ProcessMessage() == -1 )
        {
            break ;    // �G���[���N�����烋�[�v���甲����
        }
    }

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
