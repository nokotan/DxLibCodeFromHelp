#include "DxLib.h"

int main()
{
    int BlendGraph, GrHandle1, GrHandle2 ;
    int i ;

    // �c�w���C�u��������������
    if( DxLib_Init() == -1 ) return -1 ;

    // ����ʂ��g�p
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // �u�����h�摜��ǂݍ���
    BlendGraph = LoadBlendGraph( "BlendGraph.bmp" ) ;

    // ��̉摜�̓ǂݍ���
    GrHandle1 = LoadGraph( "Scene1.jpg" ) ;
    GrHandle2 = LoadGraph( "Scene2.jpg" ) ;

    // 256 �t���[���|���Đ؂�ւ�
    for( i = 0 ; i < 256 ; i ++ )
    {
        // ���b�Z�[�W����
        if( ProcessMessage() != 0 ) break ;

        // Scene2.jpg ��`��
        DrawGraph( 0, 0, GrHandle2, FALSE ) ;

        // Scene1.jpg �� BlendGraph.bmp ���������ĕ`��
        // (���E���� 64)
        DrawBlendGraph( 0, 0, GrHandle1, FALSE, BlendGraph, i, 64 ) ;

        // ����ʂ̓��e��\��ʂɔ��f
        ScreenFlip() ;
    }

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( GrHandle1 ) ;
    DeleteGraph( GrHandle2 ) ;

    // �c�w���C�u�����g�p�̏I������
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
