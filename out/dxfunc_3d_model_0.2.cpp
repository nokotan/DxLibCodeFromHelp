#include "DxLib.h"

int main()
{
    int ModelHandle, DupModelHandle ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �`���𗠉�ʂɕύX
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // �����{�^����������邩�E�C���h�E��������܂Ń��[�v
    while( ProcessMessage() == 0 && CheckHitKeyAll() == 0 )
    {
        // ��ʂ��N���A
        ClearDrawScreen() ;

        // �ǂݍ��񂾃f�[�^�Ɠ����f�[�^���g�p���郂�f���n���h�����쐬����
        DupModelHandle = MV1DuplicateModel( ModelHandle ) ;

        // ��ʂɉf�郉���_���Ȉʒu�ɂR�c���f�����ړ�
        MV1SetPosition( DupModelHandle, VGet( ( float )GetRand( 639 ), ( float )-GetRand( 300 ), GetRand( 300 ) + 300.0f ) ) ;

        // �R�c���f���̕`��
        MV1DrawModel( DupModelHandle ) ;

        // �R�c���f���̍폜
        MV1DeleteModel( DupModelHandle ) ;

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
