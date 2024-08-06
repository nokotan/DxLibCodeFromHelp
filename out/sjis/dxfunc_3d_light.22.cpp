#include "DxLib.h"

int main()
{
    int LightHandle, ModelHandle ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �R�c���f���̓ǂݍ���
    ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;

    // ���C�g�n���h���̃��C�g�̌��ʂ��킩��Ղ��悤�ɕW�����C�g�𖳌���
    SetLightEnable( FALSE ) ;

    // �|�C���g�^�C�v�̃��C�g�n���h�����쐬
    LightHandle = CreatePointLightHandle(
                    VGet( 320.0f, 1000.0f, 600.0f ),
                    2000.0f,
                    0.0f,
                    0.002f,
                    0.0f ) ;

    // ���C�g�n���h���̈ʒu�����f���̏㑤�Ɉړ�
    SetLightPositionHandle( LightHandle, VGet( 320.0f, 1000.0f, 600.0f ) ) ;

    // ��ʂɉf��ʒu�ɂR�c���f�����ړ�
    MV1SetPosition( ModelHandle, VGet( 320.0f, 240.0f, 600.0f ) ) ;

    // �R�c���f���̕`��
    MV1DrawModel( ModelHandle ) ;

    // ���C�g�n���h���̍폜
    DeleteLightHandle( LightHandle ) ;

    // ���f���n���h���̍폜
    MV1DeleteModel( ModelHandle ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
