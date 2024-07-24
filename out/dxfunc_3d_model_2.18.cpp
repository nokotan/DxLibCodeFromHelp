#include "DxLib.h"

int main()
{
    int ModelHandle, MeshNum, i, MeshIndex ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // �P�Ԗڂ̃t���[���Ɋ܂܂�郁�b�V���̐����擾����
    MeshNum = MV1GetFrameMeshNum( ModelHandle, 1 ) ;

    // ���b�V���̐��������[�v
    for( i = 0 ; i < MeshNum ; i ++ )
    {
        // ���b�V���ԍ��̎擾
        MeshIndex = MV1GetFrameMesh( ModelHandle, 1, i ) ;

        // ���b�V�����g�p���Ă���}�e���A���ƃ��b�V���Ɋ܂܂��O�p�`�|���S���̐���`��
        DrawFormatString( 0, i * 16, GetColor( 255,255,255 ), "Mesh No  %d   Material  %d    Triangle Polygon Num  %d",
            i, MV1GetMeshMaterial( ModelHandle, MeshIndex ), MV1GetMeshTriangleNum( ModelHandle, MeshIndex ) ) ;
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
