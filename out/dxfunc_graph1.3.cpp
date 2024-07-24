#include "DxLib.h"

int main()
{
    int handle;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 ) return -1;

    // 20x20�T�C�Y�̃A���t�@�`�����l���Ȃ��̕`��\�摜���쐬����
    handle = MakeScreen( 20, 20, FALSE ) ;

    // �쐬�����摜��`��Ώۂɂ���
    SetDrawScreen( handle ) ;

    // �摜�ɑ΂��āu���v�Ƃ���������`�悷��
    DrawString( 0, 0, "��", GetColor( 255, 255, 255 ) ) ;

    // �`��Ώۂ�\��ʂɂ���
    SetDrawScreen( DX_SCREEN_FRONT ) ;

    // �`��Ώۉ摜����ʂ����ς��Ɋg�債�ĕ`�悷��
    DrawExtendGraph( 0, 0, 640, 480, handle, FALSE ) ;

    // MakeScreen �ō쐬�����O���t�B�b�N�n���h���̍폜
    DeleteGraph( handle ) ;

    // �L�[���͑҂�
    WaitKey();

    // �c�w���C�u�����̌�n��
    DxLib_End();

    // �\�t�g�̏I��
    return 0;
}
