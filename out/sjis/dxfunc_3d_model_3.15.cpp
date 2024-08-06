#include "DxLib.h"

int main()
{
    int ModelHandle ;
    int Add, y ;
    VECTOR StartPos, EndPos ;
    MV1_COLL_RESULT_POLY HitPoly ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;

    // �`���𗠉�ʂɕύX
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // ���f���̂O�Ԗڂ̃t���[���̃R���W���������\�z
    MV1SetupCollInfo( ModelHandle, 0, 8, 8, 8 ) ;

    // ���f���̐i�s�������Z�b�g
    Add = 8 ;

    // ���f���̈ړ��ʒu���Z�b�g
    y = 0 ;

    // �E�C���h�E�������邩�d�r�b�L�[���������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // �R�c���f���̈ړ��ʒu���㉺�Ɉړ�������
        y += Add ;
        if( y < -300 || y > 300 )
            Add = -Add ;

        // �R�c���f���̈ʒu��ύX����
        MV1SetPosition( ModelHandle, VGet( 320.0f, 300.0f + y, 600.0f ) ) ;

        // �O�Ԗڂ̃t���[���̃R���W���������X�V����
        MV1RefreshCollInfo( ModelHandle, 0 ) ;

        // �R�c���f���̕`��
        MV1DrawModel( ModelHandle ) ;

        // �O�Ԃ̃t���[���Ɛ����Ƃ̓����蔻��
        StartPos = VGet(    0.0f, 300.0f, 600.0f ) ;
        EndPos   = VGet( 1000.0f, 300.0f, 600.0f ) ;
        HitPoly = MV1CollCheck_Line( ModelHandle, 0, StartPos, EndPos ) ;

        // ���������ꍇ�͂��̈ʒu��`�悷������̏I�_�Ƃ���
        if( HitPoly.HitFlag == 1 )
        {
            EndPos = HitPoly.HitPosition ;
        }

        // �����̕`��
        DrawLine3D( StartPos, EndPos, GetColor( 255,255,0 ) ) ;

        // �����������ǂ�����\������
        DrawFormatString( 0, 0, GetColor( 255,255,255 ), "HIT:%d", HitPoly.HitFlag ) ;

        // ����ʂ̓��e��\��ʂɔ��f
        ScreenFlip() ;
    }

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
