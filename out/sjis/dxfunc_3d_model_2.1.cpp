#include "DxLib.h"

int main()
{
    int ModelHandle ;
    int GrHandle ;
    int TexIndex ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �ΐF�̖ڂ̉摜�̓ǂ݂���
    GrHandle = LoadGraph( "DxCharaEye2.tga" ) ;

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // ���f������ʂɉf��ʒu�Ɉړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, -300.0f, 400.0f ) ) ;

    // �ڂ̕����̃}�e���A���Ŏg�p����Ă���e�N�X�`���̔ԍ����擾
    TexIndex = MV1GetMaterialDifMapTexture( ModelHandle, 4 ) ;

    // �e�N�X�`���Ŏg�p����O���t�B�b�N�n���h����ύX����
    MV1SetTextureGraphHandle( ModelHandle, TexIndex, GrHandle, FALSE ) ;

    // ���f����`�悷��
    MV1DrawModel( ModelHandle ) ;

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
    DeleteGraph( GrHandle ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
