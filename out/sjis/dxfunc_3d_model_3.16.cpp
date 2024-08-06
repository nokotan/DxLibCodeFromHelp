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

    // �R�c���f����������ʒu�Ɉړ�����
    MV1SetPosition( ModelHandle, VGet( 320.0f, 300.0f, 600.0f ) ) ;

    // �`���𗠉�ʂɕύX
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // ���f���S�̂̃R���W���������\�z
    MV1SetupCollInfo( ModelHandle, -1, 8, 8, 8 ) ;

    // ���f���̐i�s�������Z�b�g
    Add = 8 ;

    // ���f���̈ړ��ʒu���Z�b�g
    y = 0 ;

    // �E�C���h�E�������邩�����L�[���������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // �R�c���f���̈ړ��ʒu���㉺�Ɉړ�������
        y += Add ;
        if( y < 0 || y > 600 )
            Add = -Add ;

        // �R�c���f���̕`��
        MV1DrawModel( ModelHandle ) ;

        // ���f���Ɛ����Ƃ̓����蔻��
        StartPos = VGet( -300.0f, y, 600.0f ) ;
        EndPos   = VGet( 1000.0f, y, 600.0f ) ;
        HitPoly = MV1CollCheck_Line( ModelHandle, -1, StartPos, EndPos ) ;

        // ���������ꍇ�͂��̈ʒu��`�悷������̏I�_�Ƃ���
        if( HitPoly.HitFlag == 1 )
        {
            EndPos = HitPoly.HitPosition ;
        }

        // �����̕`��
        DrawLine3D( StartPos, EndPos, GetColor( 255,255,0 ) ) ;

        // �����������ǂ����ŏ����𕪊�
        if( HitPoly.HitFlag == 1 )
        {
            // ���������ꍇ�͏Փ˂̏���`�悷��

            // �����������W��`��
            DrawFormatString( 0, 0, GetColor( 255,255,255 ),  "Hit Pos   %f  %f  %f",
                HitPoly.HitPosition.x, HitPoly.HitPosition.y, HitPoly.HitPosition.z ) ;

            // ���������|���S�����܂܂��t���[���̔ԍ���`��
            DrawFormatString( 0, 16, GetColor( 255,255,255 ), "Frame     %d", HitPoly.FrameIndex ) ;

            // ���������|���S�����g�p���Ă���}�e���A���̔ԍ���`��
            DrawFormatString( 0, 32, GetColor( 255,255,255 ), "Material  %d", HitPoly.MaterialIndex ) ;

            // ���������|���S�����`������O���_�̍��W��`��
            DrawFormatString( 0, 48, GetColor( 255,255,255 ), "Position  %f  %f  %f",
                HitPoly.Position[ 0 ].x, HitPoly.Position[ 0 ].y, HitPoly.Position[ 0 ].z ) ;
            DrawFormatString( 0, 64, GetColor( 255,255,255 ), "          %f  %f  %f",
                HitPoly.Position[ 1 ].x, HitPoly.Position[ 1 ].y, HitPoly.Position[ 1 ].z ) ;
            DrawFormatString( 0, 80, GetColor( 255,255,255 ), "          %f  %f  %f",
                HitPoly.Position[ 2 ].x, HitPoly.Position[ 2 ].y, HitPoly.Position[ 2 ].z ) ;

            // ���������|���S���̖@����`��
            DrawFormatString( 0, 96, GetColor( 255,255,255 ), "Normal    %f  %f  %f",
                HitPoly.Normal.x, HitPoly.Normal.y, HitPoly.Normal.z ) ;
        }
        else
        {
            // ������Ȃ������ꍇ�͏Փ˂��Ȃ������|�����`�悷��
            DrawString( 0, 0, "NO HIT", GetColor( 255,255,255 ) ) ;
        }

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
