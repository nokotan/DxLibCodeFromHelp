#include "DxLib.h"

int main()
{
    int LightHandle ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �f�B���N�V���i�����C�g�^�C�v�̃n���h���̍쐬
    LightHandle = CreateDirLightHandle( VGet( 1.0f, 0.0f, 0.0f ) ) ;

    // ����ɍ폜
    DeleteLightHandle( LightHandle ) ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
