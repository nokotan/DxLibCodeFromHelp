#include "DxLib.h"

int main()
{
    int i ;
    unsigned int Cr ;
    int x , y ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[������������I��
    }

    // �`����ʂ�\�ɂ���
    SetDrawScreen( DX_SCREEN_FRONT ) ;

    // �P�O�O�O�O�l�p�`��`���܂�
    for( i = 0 ; i < 10000 ; i ++ )
    {
        // �����_���ȐF���擾����wGetRand�x�g�p
        Cr = GetColor( GetRand( 255 ) , GetRand( 255 ) , GetRand( 255 ) ) ;

        // �����_���Ȉʒu�Ɏl�p�`��`�� 
        x = GetRand( 639 ) ;
        y = GetRand( 479 ) ;
        DrawBox( x , y , x + GetRand( 639 ) , y + GetRand( 479 ) , Cr , TRUE ) ;
    }

    WaitKey() ;        // ���ʂ����邽�߂ɃL�[�҂�(�wWaitKey�x���g�p)

    // ��ʂ�������
    ClearDrawScreen() ;

    // �`����ʂ𗠂ɂ���
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // �P�O�O�O�O�l�p�`��`���܂�
    for( i = 0 ; i < 10000 ; i ++ )
    {
        // �����_���ȐF���擾����wGetRand�x�g�p
        Cr = GetColor( GetRand( 255 ) , GetRand( 255 ) , GetRand( 255 ) ) ;

        // �����_���Ȉʒu�Ɏl�p�`��`�� 
        x = GetRand( 639 ) ;
        y = GetRand( 479 ) ;
        DrawBox( x , y , x + GetRand( 639 ) , y + GetRand( 479 ) , Cr , TRUE ) ;
    }

    // ����ʂ̓��e��\��ʂɔ��f���܂�
    ScreenFlip() ;

    WaitKey() ;        // ���ʂ����邽�߂ɃL�[�҂�(�wWaitKey�x���g�p)

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
