#include "DxLib.h"

int main()
{
    int ShaderVersion ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 ) return -1;

    // �g�p�ł���v���O���}�u���V�F�[�_�[�̃o�[�W�������擾
    ShaderVersion = GetValidShaderVersion() ;

    // �o�[�W�����ԍ����O��������g�p�s�\
    if( ShaderVersion == 0 )
    {
        DrawString( 0, 0, "�v���O���}�u���V�F�[�_�[���g�����Ƃ͂ł��܂���", GetColor( 255,255,255 ) ) ;
    }
    else
    {
        // �O�ȊO��������g�p�\
        DrawFormatString( 0, 0, GetColor( 255,255,255 ), "�v���O���}�u���V�F�[�_�[�o�[�W���� %.1f ���g�p�\�ł�", ShaderVersion / 100.0f ) ;
    }

    // �L�[���͑҂�
    WaitKey();

    // �c�w���C�u�����̌�n��
    DxLib_End();

    // �\�t�g�̏I��
    return 0;
}
