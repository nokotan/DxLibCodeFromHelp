#include "DxLib.h"

int main()
{
    int i ;
    int PosX, PosY ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 ) return -1 ;

    // �`���𗠉�ʂɂ���
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // ���C�����[�v
    while( ProcessMessage() == 0 )
    {
        // ��ʂ̃N���A
        ClearDrawScreen() ;

        // �^�b�`����Ă���ӏ��̐������J��Ԃ�
        for( i = 0 ; i < GetTouchInputNum() ; i ++ )
        {
            // �^�b�`����Ă���ӏ��̍��W���擾
            GetTouchInput( i, &PosX, &PosY, NULL, NULL ) ;

            // �^�b�`����Ă���ӏ��̍��W�ɉ~��`��
            DrawCircle( PosX, PosY, 40, GetColor( 255, 255, 255 ), TRUE ) ;
        }

        // ����ʂ̓��e��\��ʂɔ��f
        ScreenFlip() ;
    }

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
