#include "DxLib.h"

int main()
{
    float xadd, length ;
    VECTOR Line1, Line2, Tri1, Tri2, Tri3 ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �`���𗠉�ʂɂ���
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // �����̍��W�ƎO�p�`���`������R���_�̍��W���Z�b�g
    Line1 = VGet( 0.0f, 0.0f, 0.0f ) ;
    Line2 = VGet( 0.0f, 400.0f, 0.0f ) ;
    Tri1 = VGet( 320.0f, 200.0f, 0.0f ) ;
    Tri2 = VGet( 280.0f, 260.0f, 0.0f ) ;
    Tri3 = VGet( 360.0f, 260.0f, 0.0f ) ;

    // ���W�Ɖ��Z���̏�����
    xadd = 8.0f ;

    // �E�C���h�E�������邩�����L�[���������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // �����̏I�_���ړ�
        Line2.x += xadd ;
        if( Line2.x < 0.0f || Line2.x > 640.0f )
            xadd = -xadd ;

        // �����ƎO�p�`�̍ŋߓ_�Ԃ̋��������߂�
        length = Segment_Triangle_MinLength( Line1, Line2, Tri1, Tri2, Tri3 ) ;

        // �����̕`��
        DrawLine( Line1.x, Line1.y, Line2.x, Line2.y, GetColor( 255,255,255 ) ) ;

        // �O�p�`�Ƃ̋����� 64 �ȉ���������F��ς��ĕ`��
        if( length < 64.0f )
        {
            DrawTriangle( Tri1.x, Tri1.y, Tri2.x, Tri2.y, Tri3.x, Tri3.y,  GetColor( 255,0,0 ), TRUE ) ;
        }
        else
        {
            DrawTriangle( Tri1.x, Tri1.y, Tri2.x, Tri2.y, Tri3.x, Tri3.y,  GetColor( 0,255,0 ), TRUE ) ;
        }

        // ����ʂ̓��e��\��ʂɔ��f������
        ScreenFlip() ;
    }

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
