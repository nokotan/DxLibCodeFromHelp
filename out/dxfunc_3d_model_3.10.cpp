#include "DxLib.h"

int main()
{
    int ModelHandle, TriangleListNum, i, TriangleListIndex ;
    int y ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // �P�Ԗڂ̃��b�V���Ɋ܂܂��g���C�A���O�����X�g�̐����擾����
    TriangleListNum = MV1GetMeshTListNum( ModelHandle, 1 ) ;

    // �g���C�A���O�����X�g�̐��������[�v
    y = 0 ;
    for( i = 0 ; i < TriangleListNum ; i ++ )
    {
        // �g���C�A���O�����X�g�ԍ��̎擾
        TriangleListIndex = MV1GetMeshTList( ModelHandle, 1, i ) ;

        // �g���C�A���O�����X�g�ԍ���`��
        DrawFormatString( 0, y, GetColor( 255,255,255 ), "TriangleListIndex %d", TriangleListIndex ) ;

        // �g���C�A���O�����X�g�̒��_�^�C�v��`��
        switch( MV1GetTriangleListVertexType( ModelHandle, TriangleListIndex ) )
        {
        case DX_MV1_VERTEX_TYPE_1FRAME :
            DrawString( 0, y + 16, "���_�^�C�v�F�P�t���[���̉e�����󂯂钸�_", GetColor( 255,255,255 ) ) ;
            break ;

        case DX_MV1_VERTEX_TYPE_4FRAME :
            DrawString( 0, y + 16, "���_�^�C�v�F�P�`�S�t���[���̉e�����󂯂钸�_", GetColor( 255,255,255 ) ) ;
            break ;

        case DX_MV1_VERTEX_TYPE_8FRAME :
            DrawString( 0, y + 16, "���_�^�C�v�F�P�`�W�t���[���̉e�����󂯂钸�_", GetColor( 255,255,255 ) ) ;
            break ;

        case DX_MV1_VERTEX_TYPE_FREE_FRAME :
            DrawString( 0, y + 16, "���_�^�C�v�F�X�t���[���ȏ�̉e�����󂯂钸�_", GetColor( 255,255,255 ) ) ;
            break ;

        case DX_MV1_VERTEX_TYPE_NMAP_1FRAME :
            DrawString( 0, y + 16, "���_�^�C�v�F�@���}�b�v�p�̏�񂪊܂܂��P�t���[���̉e�����󂯂钸�_", GetColor( 255,255,255 ) ) ;
            break ;

        case DX_MV1_VERTEX_TYPE_NMAP_4FRAME :
            DrawString( 0, y + 16, "���_�^�C�v�F�@���}�b�v�p�̏�񂪊܂܂��P�`�S�t���[���̉e�����󂯂钸�_", GetColor( 255,255,255 ) ) ;
            break ;

        case DX_MV1_VERTEX_TYPE_NMAP_8FRAME :
            DrawString( 0, y + 16, "���_�^�C�v�F�@���}�b�v�p�̏�񂪊܂܂��P�`�W�t���[���̉e�����󂯂钸�_", GetColor( 255,255,255 ) ) ;
            break ;

        case DX_MV1_VERTEX_TYPE_NMAP_FREE_FRAME :
            DrawString( 0, y + 16, "���_�^�C�v�F�@���}�b�v�p�̏�񂪊܂܂��X�t���[���ȏ�̉e�����󂯂钸�_", GetColor( 255,255,255 ) ) ;
            break ;
        }

        // �g���C�A���O�����X�g�̃|���S�����ƒ��_����`��
        DrawFormatString( 0, y + 32, GetColor( 255,255,255 ), "�|���S�����F%-5d   ���_���F%-5d",
            MV1GetTriangleListPolygonNum( ModelHandle, TriangleListIndex ),
            MV1GetTriangleListVertexNum( ModelHandle, TriangleListIndex ) ) ;

        // �`��x���W��i�߂�
        y += 64 ;
    }

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // �L�[�̓��͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
