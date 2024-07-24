#include "DxLib.h"

int main()
{
    float xadd, length ;
    VECTOR LineA1, LineA2, LineB1, LineB2 ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �`���𗠉�ʂɂ���
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // ������̍��W���Z�b�g
    LineA1 = VGet( 0.0f, 0.0f, 0.0f ) ;
    LineA2 = VGet( 0.0f, 200.0f, 0.0f ) ;
    LineB1 = VGet( 320.0f, 480.0f, 0.0f ) ;
    LineB2 = VGet( 320.0f, 240.0f, 0.0f ) ;

    // ���W�Ɖ��Z���̏�����
    xadd = 8.0f ;

    // �E�C���h�E�������邩�����L�[���������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // �����̕Е��̏I�_���ړ�
        LineA2.x += xadd ;
        if( LineA2.x < 0.0f || LineA2.x > 640.0f )
            xadd = -xadd ;

        // ������̍ŋߓ_�ǂ����̋��������߂�
        length = Segment_Segment_MinLength( LineA1, LineA2, LineB1, LineB2 ) ;

        // �Е��̐����̕`��
        DrawLine( LineB1.x, LineB1.y, LineB2.x, LineB2.y, GetColor( 255,255,255 ) ) ;

        // ������̐����������� 64 �ȉ���������F��ς��ĕ`��
        if( length < 64.0f )
        {
            DrawLine( LineA1.x, LineA1.y, LineA2.x, LineA2.y, GetColor( 255,0,0 ) ) ;
        }
        else
        {
            DrawLine( LineA1.x, LineA1.y, LineA2.x, LineA2.y, GetColor( 0,255,0 ) ) ;
        }

        // ����ʂ̓��e��\��ʂɔ��f������
        ScreenFlip() ;
    }

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
