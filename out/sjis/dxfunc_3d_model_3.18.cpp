#include "DxLib.h"

// �J�v�Z���̍���
#define CAPSULE_H        64.0f

int main()
{
    int ModelHandle ;
    int Add, y, i ;
    VECTOR CapsulePos1, CapsulePos2 ;
    MV1_COLL_RESULT_POLY_DIM HitPolyDim ;

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

        // �����蔻����s�����̈ʒu���Z�b�g
        CapsulePos1 = VGet( 250.0f, y, 600.0f ) ;
        CapsulePos2 = VGet( 250.0f, y + CAPSULE_H, 600.0f ) ;

        // ���f���ƃJ�v�Z���Ƃ̓����蔻��
        HitPolyDim = MV1CollCheck_Capsule( ModelHandle, -1, CapsulePos1, CapsulePos2,  100.0f ) ;

        // �J�v�Z���̕`��
        DrawCapsule3D( CapsulePos1, CapsulePos2, 100.0f, 8, GetColor( 255,255,0 ), GetColor( 255,255,255 ), FALSE ) ;

        // �����������ǂ����ŏ����𕪊�
        if( HitPolyDim.HitNum >= 1 )
        {
            // ���������ꍇ�͏Փ˂̏���`�悷��

            // ���������|���S���̐���`��
            DrawFormatString( 0, 0, GetColor( 255,255,255 ), "Hit Poly Num   %d", HitPolyDim.HitNum ) ;

            // ���������|���S���̐������J��Ԃ�
            for( i = 0 ; i < HitPolyDim.HitNum ; i ++ )
            {
                // ���������|���S����`��
                DrawTriangle3D(
                    HitPolyDim.Dim[ i ].Position[ 0 ], 
                    HitPolyDim.Dim[ i ].Position[ 1 ], 
                    HitPolyDim.Dim[ i ].Position[ 2 ], GetColor( 0,255,255 ), TRUE ) ;
            }
        }

        // �����蔻����̌�n��
        MV1CollResultPolyDimTerminate( HitPolyDim ) ;

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
