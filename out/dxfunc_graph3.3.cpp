#include "DxLib.h"

int main()
{
    // �t���X�N���[�����[�h���̉𑜓x���[�h�����j�^�[�̍ő�𑜓x���g�p���郂�[�h�ɐݒ�
    SetFullScreenResolutionMode( DX_FSRESOLUTIONMODE_MAXIMUM ) ;

    // ��ʂ̉𑜓x���c���Q�T�U�h�b�g�ɐݒ�
    SetGraphMode( 256, 256, 32 ) ;

    // �c�w���C�u��������������
    if( DxLib_Init() == -1 )
    {
         return -1;      // �G���[������������I��
    }

    // ��ʂ̒��S�ɉ~��`��
    DrawCircle( 128, 128, 48, GetColor( 255,255,0 ), FALSE ) ;

    // �L�[�҂�(�wWaitKey�x���g�p)
    WaitKey() ;

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;           // �\�t�g�̏I��
}
