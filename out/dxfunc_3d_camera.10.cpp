#include "DxLib.h"

#define X1    100.0f
#define X2    540.0f
#define Y1    100.0f
#define Y2    380.0f
#define Z1    0.0f
#define Z2    1000.0f

int main()
{
    unsigned int Color ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() < 0 )
    {
        // �G���[�����������璼���ɏI��
        return -1 ;
    }

    // �`���𗠉�ʂɂ���
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // �J�����̒����_�̉�ʏ�̈ʒu���E���ɂ���
    SetCameraScreenCenter( 480.0f, 240.0f ) ;

    // �����̂�`�悷��
    Color = GetColor( 255,255,255 ) ;
    DrawLine3D( VGet( X1, Y1, Z1 ), VGet( X2, Y1, Z1 ), Color ) ;
    DrawLine3D( VGet( X2, Y1, Z1 ), VGet( X2, Y2, Z1 ), Color ) ;
    DrawLine3D( VGet( X2, Y2, Z1 ), VGet( X1, Y2, Z1 ), Color ) ;
    DrawLine3D( VGet( X1, Y2, Z1 ), VGet( X1, Y1, Z1 ), Color ) ;
    DrawLine3D( VGet( X1, Y1, Z2 ), VGet( X2, Y1, Z2 ), Color ) ;
    DrawLine3D( VGet( X2, Y1, Z2 ), VGet( X2, Y2, Z2 ), Color ) ;
    DrawLine3D( VGet( X2, Y2, Z2 ), VGet( X1, Y2, Z2 ), Color ) ;
    DrawLine3D( VGet( X1, Y2, Z2 ), VGet( X1, Y1, Z2 ), Color ) ;
    DrawLine3D( VGet( X1, Y1, Z1 ), VGet( X1, Y1, Z2 ), Color ) ;
    DrawLine3D( VGet( X2, Y1, Z1 ), VGet( X2, Y1, Z2 ), Color ) ;
    DrawLine3D( VGet( X2, Y2, Z1 ), VGet( X2, Y2, Z2 ), Color ) ;
    DrawLine3D( VGet( X1, Y2, Z1 ), VGet( X1, Y2, Z2 ), Color ) ;

    // ����ʂ̓��e��\��ʂɔ��f
    ScreenFlip() ;

    // �L�[���͑҂�
    WaitKey() ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
