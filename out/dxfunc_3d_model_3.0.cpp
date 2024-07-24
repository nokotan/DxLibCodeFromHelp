#include "DxLib.h"

int main()
{
    int ModelHandle, MeshNum, i ;
    VECTOR Position ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // ���f���Ɋ܂܂�郁�b�V���̐����擾����
    MeshNum = MV1GetMeshNum( ModelHandle ) ;

    // ���b�V���̐��������[�v
    for( i = 0 ; i < MeshNum ; i ++ )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // ���b�V�����g�p���Ă���}�e���A���̕`��
        DrawFormatString( 0,  0, GetColor( 255,255,255 ),  "Material              %d", MV1GetMeshMaterial( ModelHandle, i ) ) ;

        // ���b�V���Ɋ܂܂��O�p�`�|���S���̐���`��
        DrawFormatString( 0, 16, GetColor( 255,255,255 ),  "Triangle Polygon Num  %d", MV1GetMeshTriangleNum( ModelHandle, i ) ) ;

        // ���b�V���̕\���E��\����Ԃ�`��
        DrawFormatString( 0, 32, GetColor( 255,255,255 ),  "Visible               %d", MV1GetMeshVisible( ModelHandle, i ) ) ;

        // ���b�V���ɔ������v�f�����邩�ǂ�����`��
        DrawFormatString( 0, 48, GetColor( 255,255,255 ),  "Semi Trans State      %d", MV1GetMeshSemiTransState( ModelHandle, i ) ) ;

        // ���b�V�����o�b�N�J�����O���s�����ǂ�����`��
        DrawFormatString( 0, 64, GetColor( 255,255,255 ),  "Back Culling          %d", MV1GetMeshBackCulling( ModelHandle, i ) ) ;

        // ���b�V���̒��_�f�B�t���[�Y�J���[���g�p���邩�ǂ�����`��
        DrawFormatString( 0, 80, GetColor( 255,255,255 ),  "Use Vertex Dif Color  %d", MV1GetMeshUseVertDifColor( ModelHandle, i ) ) ;

        // ���b�V���̒��_�X�y�L�����J���[���g�p���邩�ǂ�����`��
        DrawFormatString( 0, 96, GetColor( 255,255,255 ),  "Use Vertex Spc Color  %d", MV1GetMeshUseVertSpcColor( ModelHandle, i ) ) ;

        // ���b�V���Ɋ܂܂�钸�_�̃��[�J�����W�̍ő���W�l��`��
        Position = MV1GetMeshMaxPosition( ModelHandle, i ) ;
        DrawFormatString( 0, 112, GetColor( 255,255,255 ), "Max Position          x %f  y %f  z %f", Position.x, Position.y, Position.z ) ;

        // ���b�V���Ɋ܂܂�钸�_�̃��[�J�����W�̍ŏ����W�l��`��
        Position = MV1GetMeshMinPosition( ModelHandle, i ) ;
        DrawFormatString( 0, 128, GetColor( 255,255,255 ), "Min Position          x %f  y %f  z %f", Position.x, Position.y, Position.z ) ;

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
