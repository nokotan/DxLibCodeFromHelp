#include "DxLib.h"

int main()
{
    int ModelHandle ;
    int TexIndex ;
    int GrHandle ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // �}�e���A���ԍ��S�Ŏg�p����Ă���e�N�X�`���̔ԍ����擾����
    TexIndex = MV1GetMaterialDifMapTexture( ModelHandle, 4 ) ;

    // ���f���Ŏg�p����Ă���e�N�X�`���̃O���t�B�b�N�n���h�����擾����
    GrHandle = MV1GetTextureGraphHandle( ModelHandle, TexIndex ) ;

    // �擾�����O���t�B�b�N�n���h������ʂɕ`�悷��
    DrawGraph( 0, 0, GrHandle, TRUE ) ;

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // �L�[�̓��͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
