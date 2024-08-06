#include "DxLib.h"

int main()
{
    int ModelHandle, FrameNum, i, Parent ;
    VECTOR Position ;
    MATRIX Matrix ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // �t���[���̐����擾����
    FrameNum = MV1GetFrameNum( ModelHandle ) ;

    // �t���[���̐��������[�v
    for( i = 0 ; i < FrameNum ; i ++ )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // �t���[�����̕`��
        DrawFormatString( 0, 0, GetColor( 255,255,255 ),      "Name         %s", MV1GetFrameName( ModelHandle, i ) ) ;

        // �e�t���[�����̕`��
        Parent = MV1GetFrameParent( ModelHandle, i ) ;
        if( Parent == -2 )
        {
            DrawFormatString( 0, 16, GetColor( 255,255,255 ), "Parent Name  None" ) ;
        }
        else
        {
            DrawFormatString( 0, 16, GetColor( 255,255,255 ), "Parent Name  %s", MV1GetFrameName( ModelHandle, Parent ) ) ;
        }

        // �q�t���[���̐���`��
        DrawFormatString( 0, 32, GetColor( 255,255,255 ),     "Child Num    %d", MV1GetFrameChildNum( ModelHandle, i ) ) ;

        // �t���[���̃��[���h���W�̕`��
        Position = MV1GetFramePosition( ModelHandle, i ) ;
        DrawFormatString( 0, 48, GetColor( 255,255,255 ),     "Position     x:%f y:%f z:%f", Position.x, Position.y, Position.z ) ;

        // �ϊ��s���`�悷��
        Matrix = MV1GetFrameLocalMatrix( ModelHandle, i ) ;
        DrawFormatString( 0, 64,  GetColor( 255,255,255 ),    "   Matrix    %f %f %f %f", Matrix.m[ 0 ][ 0 ], Matrix.m[ 0 ][ 1 ], Matrix.m[ 0 ][ 2 ], Matrix.m[ 0 ][ 3 ] ) ;
        DrawFormatString( 0, 80,  GetColor( 255,255,255 ),    "             %f %f %f %f", Matrix.m[ 1 ][ 0 ], Matrix.m[ 1 ][ 1 ], Matrix.m[ 1 ][ 2 ], Matrix.m[ 1 ][ 3 ] ) ;
        DrawFormatString( 0, 96,  GetColor( 255,255,255 ),    "             %f %f %f %f", Matrix.m[ 2 ][ 0 ], Matrix.m[ 2 ][ 1 ], Matrix.m[ 2 ][ 2 ], Matrix.m[ 2 ][ 3 ] ) ;
        DrawFormatString( 0, 112, GetColor( 255,255,255 ),    "             %f %f %f %f", Matrix.m[ 3 ][ 0 ], Matrix.m[ 3 ][ 1 ], Matrix.m[ 3 ][ 2 ], Matrix.m[ 3 ][ 3 ] ) ;

        // �t���[���̃��[�J�����W���烏�[���h���W�ɕϊ�����s���`�悷��
        Matrix = MV1GetFrameLocalWorldMatrix( ModelHandle, i ) ;
        DrawFormatString( 0, 128,  GetColor( 255,255,255 ),   "LW Matrix    %f %f %f %f", Matrix.m[ 0 ][ 0 ], Matrix.m[ 0 ][ 1 ], Matrix.m[ 0 ][ 2 ], Matrix.m[ 0 ][ 3 ] ) ;
        DrawFormatString( 0, 144,  GetColor( 255,255,255 ),   "             %f %f %f %f", Matrix.m[ 1 ][ 0 ], Matrix.m[ 1 ][ 1 ], Matrix.m[ 1 ][ 2 ], Matrix.m[ 1 ][ 3 ] ) ;
        DrawFormatString( 0, 160,  GetColor( 255,255,255 ),   "             %f %f %f %f", Matrix.m[ 2 ][ 0 ], Matrix.m[ 2 ][ 1 ], Matrix.m[ 2 ][ 2 ], Matrix.m[ 2 ][ 3 ] ) ;
        DrawFormatString( 0, 176, GetColor( 255,255,255 ),    "             %f %f %f %f", Matrix.m[ 3 ][ 0 ], Matrix.m[ 3 ][ 1 ], Matrix.m[ 3 ][ 2 ], Matrix.m[ 3 ][ 3 ] ) ;

        // �t���[���̕\����Ԃ�`��
        DrawFormatString( 0, 192, GetColor( 255,255,255 ),    "Visible      %d", MV1GetFrameVisible( ModelHandle, i ) ) ;

        // �t���[���ɔ������v�f�����邩�ǂ�����`��
        DrawFormatString( 0, 208, GetColor( 255,255,255 ),    "Semi Trans   %d", MV1GetFrameSemiTransState( ModelHandle, i ) ) ;

        // �t���[���Ɋ܂܂�郁�b�V���̐���`��
        DrawFormatString( 0, 224, GetColor( 255,255,255 ),    "Mesh Num     %d", MV1GetFrameMeshNum( ModelHandle, i ) ) ;

        // �t���[���Ɋ܂܂��O�p�`�|���S���̐���`��
        DrawFormatString( 0, 240, GetColor( 255,255,255 ),    "Triangle Num %d", MV1GetFrameTriangleNum( ModelHandle, i ) ) ;

        // �L�[�̓��͑҂�
        WaitKey() ;
    }

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
