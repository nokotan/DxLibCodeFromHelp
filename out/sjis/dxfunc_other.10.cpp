-- ���M���v���O����
-----------------------------------
#include "DxLib.h"

int main()
{
    IPDATA Ip ;        // ���M�p�h�o�A�h���X�f�[�^
    int NetUDPHandle ;        // �l�b�g���[�N�n���h��

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // �t�c�o�ʐM�p�̃\�P�b�g�n���h�����쐬
    NetUDPHandle = MakeUDPSocket( -1 ) ;

    // �h�o�A�h���X��ݒ�( �����ɂ���S�̂h�o�l�͉��ł� )
    Ip.d1 = 192 ;
    Ip.d2 = 168 ;
    Ip.d3 = 0 ;
    Ip.d4 = 14 ;

    // ������̑��M
    NetWorkSendUDP( NetUDPHandle, Ip, 9850, "���b�Z�[�W�I�I", 15 ) ;

    // ���M������ƕ\��
    DrawString( 0, 0, "������𑗐M���܂����A�����L�[�������ƏI�����܂�", GetColor( 255,255,255 ) ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �t�c�o�\�P�b�g�n���h���̍폜
    DeleteUDPSocket( NetUDPHandle ) ; 

    DxLib_End() ;    // �c�w���C�u�����g�p�̏I������

    return 0 ;    // �\�t�g�̏I��
}

-- ��M���v���O����
-----------------------------------
#include "DxLib.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
    char StrBuf[ 256 ] ;    // �f�[�^�o�b�t�@
    int NetUDPHandle ;        // �l�b�g���[�N�n���h��

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // �t�c�o�ʐM�p�̃\�P�b�g�n���h�����쐬
    NetUDPHandle = MakeUDPSocket( 9850 ) ;

    // ��M�҂�����ƕ\��
    DrawString( 0, 0, "��M�҂�", GetColor( 255,255,255 ) ) ;

    // ������̎�M��҂�
    while( CheckNetWorkRecvUDP( NetUDPHandle ) == FALSE )
    {
        // �E�C���h�E�Y���b�Z�[�W����
        if( ProcessMessage() < 0 ) break ;
    }

    // ��M
    NetWorkRecvUDP( NetUDPHandle, NULL, NULL, StrBuf, 256, FALSE ) ;

    // ��M�������������ʂɕ`��
    ClearDrawScreen() ;
    DrawString( 0, 0, StrBuf, GetColor( 255,255,255 ) ) ;

    // �L�[���͑҂�
    WaitKey() ;

    // �t�c�o�\�P�b�g�n���h���̍폜
    DeleteUDPSocket( NetUDPHandle ) ; 

    DxLib_End() ;    // �c�w���C�u�����g�p�̏I������

    return 0 ;    // �\�t�g�̏I��
}
