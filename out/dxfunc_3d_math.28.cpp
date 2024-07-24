#include "DxLib.h"

int main()
{
    float yadd, length ;
    VECTOR Line1, Line2, Point ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �`���𗠉�ʂɂ���
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // �����̍��W�Ɠ_�̍��W���Z�b�g
    Line1 = VGet( 0.0f, 0.0f, 0.0f ) ;
    Line2 = VGet( 640.0f, 480.0f, 0.0f ) ;
    Point = VGet( 320.0f, 0.0f, 0.0f ) ;

    // ���W�Ɖ��Z���̏�����
    yadd = 4.0f ;

    // �E�C���h�E�������邩�����L�[���������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // �_�̍��W���ړ�
        Point.y += yadd ;
        if( Point.y < 0.0f || Point.y > 480.0f )
            yadd = -yadd ;

        // �����Ɠ_���ł��߂Â����W�Ԃ̋��������߂�
        length = Segment_Point_MinLength( Line1, Line2, Point ) ;

        // �_�̕`��
        DrawPixel( Point.x, Point.y, GetColor( 255,255,255 ) ) ;

        // �_�Ƃ̋����� 64 �ȉ���������F��ς��ĕ`��
        if( length < 64.0f )
        {
            DrawLine( Line1.x, Line1.y, Line2.x, Line2.y, GetColor( 255,0,0 ) ) ;
        }
        else
        {
            DrawLine( Line1.x, Line1.y, Line2.x, Line2.y, GetColor( 0,255,0 ) ) ;
        }

        // ����ʂ̓��e��\��ʂɔ��f������
        ScreenFlip() ;
    }

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
