#include "DxLib.h"

#define PI    3.1415926535897932384626433832795f

int main()
{
    char KeyBuf[ 256 ] ;

    // �c�w���C�u��������������
    if( DxLib_Init() == -1 ) return -1;

    // ���b�Z�[�W�̕\��
    DrawString( 0 , 0 , " C �� K �� Y �̃L�[�𓯎��ɉ�������I�����܂� ", GetColor( 255 , 255 , 255 ) ) ;

    // �������[�v
    while( 1 )
    {
        // ���ׂẴL�[�̏�Ԃ𓾂�
        GetHitKeyStateAll( KeyBuf ) ;

        // �b�Ƃj�Ƃx�̃L�[��������Ă����烋�[�v���甲����
        if( KeyBuf[ KEY_INPUT_C ] == 1 &&
            KeyBuf[ KEY_INPUT_K ] == 1 &&
            KeyBuf[ KEY_INPUT_Y ] == 1 )
        {
            break ;
        }

        // Windows �ˑ��̃��b�Z�[�W�������s��
        if( ProcessMessage() == -1 ) break ;
    }

    // �c�w���C�u�����g�p�̏I������
    DxLib_End() ;

    // �\�t�g�̏I��
    return 0 ;
}
