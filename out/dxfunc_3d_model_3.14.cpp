#include "DxLib.h"

int main()
{
    int ModelHandle ;
    float y ;
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

    // ��ʂɉf��ʒu�ɂR�c���f�����ړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, 300.0f, 600.0f ) ) ;

    // ���f���̂O�Ԗڂ̃t���[���̃R���W���������\�z
    MV1SetupCollInfo( ModelHandle, 0, 8, 8, 8 ) ;

    // �����蔻��p�̃��C�����o���x���W��������
    y = 300.0f ;

    // �E�C���h�E�������邩�d�r�b�L�[���������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // �㉺�L�[�Ő����� y ���W�𑀍�ł���
        if( CheckHitKey( KEY_INPUT_UP ) == 1 )
        {
            y += 16.0f ;
        }
        if( CheckHitKey( KEY_INPUT_DOWN ) == 1 )
        {
            y -= 16.0f ;
        }

        // �R�c���f���̕`��
        MV1DrawModel( ModelHandle ) ;

        // �O�Ԃ̃t���[���Ɛ����Ƃ̓����蔻��
        StartPos = VGet( 0.0f, y, 600.0f ) ;
        EndPos   = VGet( 1000.0f, y, 600.0f ) ;
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
