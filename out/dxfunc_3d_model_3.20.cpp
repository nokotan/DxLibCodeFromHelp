#include "DxLib.h"

int main()
{
    int ModelHandle ;
    int i ;
    MV1_REF_POLYGONLIST RefPoly ;

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

    // ���f���S�̂̎Q�Ɨp���b�V�����\�z
    MV1SetupReferenceMesh( ModelHandle, -1, TRUE ) ;

    // �Q�Ɨp���b�V�����̎擾
    RefPoly = MV1GetReferenceMesh( ModelHandle, -1, TRUE ) ;

    // �|���S���̐������J��Ԃ�
    for( i = 0 ; i < RefPoly.PolygonNum ; i ++ )
    {
        // �|���S�����`������O���_���g�p���ă��C���[�t���[����`�悷��
        DrawLine3D(
            RefPoly.Vertexs[ RefPoly.Polygons[ i ].VIndex[ 0 ] ].Position,
            RefPoly.Vertexs[ RefPoly.Polygons[ i ].VIndex[ 1 ] ].Position,
            GetColor( 255,255,0 ) ) ;

        DrawLine3D(
            RefPoly.Vertexs[ RefPoly.Polygons[ i ].VIndex[ 1 ] ].Position,
            RefPoly.Vertexs[ RefPoly.Polygons[ i ].VIndex[ 2 ] ].Position,
            GetColor( 255,255,0 ) ) ;

        DrawLine3D(
            RefPoly.Vertexs[ RefPoly.Polygons[ i ].VIndex[ 2 ] ].Position,
            RefPoly.Vertexs[ RefPoly.Polygons[ i ].VIndex[ 0 ] ].Position,
            GetColor( 255,255,0 ) ) ;
    }

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
