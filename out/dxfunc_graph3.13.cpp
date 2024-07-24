#include "DxLib.h"

int main()
{
    int MovieGraphHandle ;

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[������������I��
    }

    // ���[�r�[�t�@�C�������[�h���܂��B
    MovieGraphHandle = LoadGraph( "??.mpg" ) ;

    // ���[�r�[���Đ���Ԃɂ��܂�
    PlayMovieToGraph( MovieGraphHandle ) ;

    // �`���̉�ʂ𗠉�ʂ�
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // ���[�v�AGetMovieStateToGraph �֐��̓��[�r�[�̍Đ���Ԃ𓾂�֐��ł�
    // �߂�l���P�̊Ԃ͍Đ���Ԃł��̂Ń��[�v�𑱂��܂�
    while( ProcessMessage() == 0 && GetMovieStateToGraph( MovieGraphHandle ) == 1 )
    {
        // ���[�r�[�f������ʂ����ς��ɕ`�悵�܂�
        DrawExtendGraph( 0 , 0 , 640 , 480 , MovieGraphHandle , FALSE ) ;

        // ��ʍ���ɍĐ����Ԃ�`�悵�܂�
        DrawFormatString( 0, 0, GetColor( 255,255,255 ), "Time:%d", TellMovieToGraph( MovieGraphHandle ) ) ;

        // ����ʂ̓��e��\��ʂɔ��f���܂�
        ScreenFlip() ;
    }

    // �ǂݍ��񂾃��[�r�[�t�@�C���̃O���t�B�b�N�n���h���̍폜
    DeleteGraph( MovieGraphHandle ) ;

    DxLib_End() ;        // �c�w���C�u�����g�p�̏I������

    return 0 ;        // �\�t�g�̏I��
}
