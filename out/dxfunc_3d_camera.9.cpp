#include "DxLib.h"

int main()
{
    int ModelHandle ;
    VECTOR StartPos, EndPos ;
    MV1_COLL_RESULT_POLY HitPoly ;
    int Mx, My ;

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

    // �E�C���h�E�������邩�����L�[���������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // �R�c���f���̕`��
        MV1DrawModel( ModelHandle ) ;

        // �}�E�X�̍��W���擾
        GetMousePoint( &Mx, &My ) ;

        // �}�E�X�|�C���^�������ʏ�̍��W�ɊY������R�c��ԏ�� Near �ʂ̍��W���擾
        StartPos = ConvScreenPosToWorldPos( VGet( Mx, My, 0.0f ) ) ;

        // �}�E�X�|�C���^�������ʏ�̍��W�ɊY������R�c��ԏ�� Far �ʂ̍��W���擾
        EndPos = ConvScreenPosToWorldPos( VGet( Mx, My, 1.0f ) ) ;

        // ���f���Ɛ����Ƃ̓����蔻��
        HitPoly = MV1CollCheck_Line( ModelHandle, -1, StartPos, EndPos ) ;

        // �����������ǂ����ŏ����𕪊�
        if( HitPoly.HitFlag == 1 )
        {
            // ���������ꍇ�͏Փ˂̏���`�悷��

            // ���������|���S�������F�ŕ`�悷��
            DrawTriangle3D( HitPoly.Position[ 0 ], HitPoly.Position[ 1 ], HitPoly.Position[ 2 ], GetColor( 255,255,0 ), TRUE ) ;

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
