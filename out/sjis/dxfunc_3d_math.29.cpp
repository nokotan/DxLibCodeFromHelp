#include "DxLib.h"

int main()
{
    float yadd ;
    HITRESULT_LINE Result ;
    VECTOR Line1, Line2, Tri1, Tri2, Tri3 ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �`���𗠉�ʂɂ���
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // �����̍��W�ƎO�p�`�̍��W���Z�b�g
    Line1 = VGet( 0.0f, 240.0f, 0.0f ) ;
    Line2 = VGet( 640.0f, 240.0f, 0.0f ) ;
    Tri1 = VGet( 320.0f, 128.0f, 0.0f ) ;
    Tri2 = VGet( 320.0f, 240.0f, 200.0f ) ;
    Tri3 = VGet( 320.0f, 240.0f, -200.0f ) ;

    // ���W�Ɖ��Z���̏�����
    yadd = 4.0f ;

    // �E�C���h�E�������邩�����L�[���������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // ���̏I�_���W���ړ�
        Line2.y += yadd ;
        if( Line2.y < 0.0f || Line2.y > 480.0f )
            yadd = -yadd ;

        // �����Ɠ_���ł��߂Â����W�Ԃ̋��������߂�
        Result = HitCheck_Line_Triangle( Line1, Line2, Tri1, Tri2, Tri3 ) ;

        // �O�p�`��^�����猩���Ƃ��ɂł������`��
        DrawLine( Tri1.x, Tri1.y, Tri2.x, Tri2.y, GetColor( 255,255,255 ) ) ;

        // �O�p�`�ƐڐG���Ă�����n�_�ƐڐG�_�����Ԑ���
        // �����łȂ��ꍇ�͎n�_�ƏI�_�����Ԑ���`�悷��
        if( Result.HitFlag == 1 )
        {
            DrawLine( Line1.x, Line1.y, Result.Position.x, Result.Position.y, GetColor( 255,0,0 ) ) ;
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
