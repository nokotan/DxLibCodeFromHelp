#include "DxLib.h"

int main()
{
    int ModelHandle ;
    int Add, y, i ;
    MV1_REF_POLYGONLIST RefPoly ;

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

    // �O�Ԗڂ̃t���[���̎Q�Ɨp���b�V�����\�z
    MV1SetupReferenceMesh( ModelHandle, 0, TRUE ) ;

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

        // �R�c���f�����ړ�����
        MV1SetPosition( ModelHandle, VGet( 320.0f, y, 600.0f ) ) ;

        // �O�Ԗڂ̃t���[���̎Q�Ɨp���b�V�����X�V����
        MV1RefreshReferenceMesh( ModelHandle, 0, TRUE ) ;

        // �O�Ԗڂ̃t���[���̎Q�Ɨp���b�V���̎擾
        RefPoly = MV1GetReferenceMesh( ModelHandle, 0, TRUE ) ;

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
