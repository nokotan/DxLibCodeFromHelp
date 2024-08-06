#include "DxLib.h"

int main()
{
    int GHandle ;
    int i ;
    unsigned int Cr ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // ���F�̒l���擾
    Cr = GetColor( 255 , 255 , 255 ) ;

    // �P�O�O�O�̓_��`��
    for( i = 0 ; i < 1000 ; i ++ )
    {
        // �����_���Ȉʒu�ɓ_��`���i�wGetRand�x���g�p�j 
        DrawPixel( GetRand( 639 ) , GetRand( 479 ) , Cr ) ;
    }

    // ��ʂ̃T�C�Y�Ɠ����T�C�Y�̃O���t�B�b�N���쐬
    GHandle = MakeGraph( 640 , 480 ) ;

    // ��ʃf�[�^�̎�肱��
    GetDrawScreenGraph( 0 , 0 , 640 , 480 , GHandle ) ;

    WaitKey() ;        // ���ʂ����邽�߂ɃL�[�҂�(�wWaitKey�x���g�p)

    // �O���t�B�b�N�n���h���̍폜
    DeleteGraph( GHandle ) ;

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
