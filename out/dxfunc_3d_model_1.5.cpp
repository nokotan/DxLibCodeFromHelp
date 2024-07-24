#include "DxLib.h"

int main()
{
    int ModelHandle, AnimNum, i ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "DxChara.x" ) ;

    // ���f���Ɋ܂܂��A�j���[�V�����̐����擾����
    AnimNum = MV1GetAnimNum( ModelHandle ) ;

    // �A�j���[�V�����̈ꗗ��`�悷��
    for( i = 0 ; i < AnimNum ; i ++ )
    {
        // �����珇�ɁA�A�j���[�V�����ԍ��A�A�j���[�V�������A�A�j���[�V�����̑����Ԃ�`�悷��
        DrawFormatString( 0, i * 16, GetColor( 255,255,255 ),
            "No:%d Name:%s Time:%f",
            i,
            MV1GetAnimName( ModelHandle, i ),
            MV1GetAnimTotalTime( ModelHandle, i ) ) ;
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
