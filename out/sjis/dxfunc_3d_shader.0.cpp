#include "DxLib.h"

int main()
{
    int Direct3DVersion ;

    // Direct3D 9Ex �̎g�p���w��
    SetUseDirect3DVersion( DX_DIRECT3D_9EX ) ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 ) return -1;

    // �g�p���Ă��� Direct3D �̃o�[�W�������擾
    Direct3DVersion = GetUseDirect3DVersion() ;

    // �g�p�o�[�W������ Direct3D 9Ex ���ǂ������`�F�b�N
    if( Direct3DVersion == DX_DIRECT3D_9EX )
    {
        DrawString( 0, 0, "Direct3D 9Ex ���g�p���Ă��܂�", GetColor( 255,255,255 ) ) ;
    }
    else
    {
        DrawString( 0, 0, "Direct3D 9Ex ���g�p���Ă��܂���", GetColor( 255,255,255 ) ) ;
    }

    // �L�[���͑҂�
    WaitKey();

    // �c�w���C�u�����̌�n��
    DxLib_End();

    // �\�t�g�̏I��
    return 0;
}
