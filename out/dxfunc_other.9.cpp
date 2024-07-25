#include "DxLib.h"

int main()
{
    char StrBuf[ 256 ] ;    // �f�[�^�o�b�t�@
    IPDATA Ip ;        // �ڑ��p�h�o�A�h���X�f�[�^
    int NetHandle ;        // �l�b�g���[�N�n���h��
    int DataLength ;        // ��M�f�[�^�ʕۑ��p�ϐ�

    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }

    // �h�o�A�h���X��ݒ�( �����ɂ���S�̂h�o�l�͉��ł� )
    Ip.d1 = 192 ;
    Ip.d2 = 168 ;
    Ip.d3 = 5   ;
    Ip.d4 = 227 ;

    // �ʐM���m��
    NetHandle = ConnectNetWork( Ip, 9850 ) ;

    // �m�������������ꍇ�̂ݒ��̏���������
    if( NetHandle != -1 )
    { 
        // �f�[�^���M
        NetWorkSend( NetHandle , "�q���������`�I�H" , 17 ) ;

        // �f�[�^������̂�҂�
        while( !ProcessMessage() )
        {
            // �擾���Ă��Ȃ���M�f�[�^�ʂ𓾂�
            DataLength = GetNetWorkDataLength( NetHandle ) ;

            // �擾���ĂȂ���M�f�[�^�ʂ��O����Ȃ��ꍇ�̓��[�v�𔲂���
            if( DataLength != 0 ) break ;
        }

        // �f�[�^��M
        NetWorkRecv( NetHandle , StrBuf , DataLength ) ;    // �f�[�^���o�b�t�@�Ɏ擾

        // ��M�����f�[�^��`��
        DrawString( 0 , 0 , StrBuf , GetColor( 255 , 255 , 255 ) ) ;

        // �L�[���͑҂�
        WaitKey() ;

        // �ڑ���f��
        CloseNetWork( NetHandle ) ;
    }

    DxLib_End() ;    // �c�w���C�u�����g�p�̏I������

    return 0 ;    // �\�t�g�̏I��
}

//#include "DxLib.h"
//
//int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
//{
//    char StrBuf[ 256 ] ;        // �f�[�^�o�b�t�@
//    int NetHandle , LostHandle ;    // �l�b�g���[�N�n���h��
//    int DataLength ;            // ��M�f�[�^�ʕۑ��p�ϐ�
//    IPDATA Ip ;            // �ڑ���h�o�A�h���X�f�[�^
//
//    if( DxLib_Init() == -1 )    // �c�w���C�u��������������
//    {
//        return -1;    // �G���[���N�����璼���ɏI��
//    }
//
//    // �ڑ����Ă���̂�҂�Ԃɂ���
//    PreparationListenNetWork( 9850 ) ;
//
//    // �ڑ����Ă��邩�d�r�b�L�[���������܂Ń��[�v
//    NetHandle = -1 ;
//    while( !ProcessMessage() && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 )
//    {
//        // �V�����ڑ����������炻�̃l�b�g���[�N�n���h���𓾂�
//        NetHandle = GetNewAcceptNetWork() ;
//        if( NetHandle != -1 ) break ;
//    }
//
//    // �ڑ�����Ă����玟�ɐi��
//    if( NetHandle != -1 )
//    {
//        // �ڑ��̎�t���I������
//        StopListenNetWork() ;
//
//        // �ڑ����Ă����}�V���̂h�o�A�h���X�𓾂�
//        GetNetWorkIP( NetHandle , &Ip ) ;
//
//        // �f�[�^�������ė���܂ő҂�
//        while( !ProcessMessage() )
//        {
//            // �擾���Ă��Ȃ���M�f�[�^�ʂ��O�ȊO�̂Ƃ��̓��[�v���甲����
//            if( GetNetWorkDataLength( NetHandle ) != 0 ) break ;
//        }
//
//        // �f�[�^��M
//        DataLength = GetNetWorkDataLength( NetHandle ) ;    // �f�[�^�̗ʂ��擾
//        NetWorkRecv( NetHandle , StrBuf , DataLength );    // �f�[�^���o�b�t�@�Ɏ擾
//
//        // ��M�����f�[�^��`��
//        DrawString( 0 , 0 , StrBuf , GetColor( 255 , 255 , 255 ) ) ;
//
//        // ��M�����̃f�[�^�𑗐M
//        NetWorkSend( NetHandle , "�q���������`�I�I" , 17 ) ;
//
//        // ���肪�ʐM��ؒf����܂ő҂�
//        while( !ProcessMessage() )
//        {
//            // �V���ɐؒf���ꂽ�l�b�g���[�N�n���h���𓾂�
//            LostHandle = GetLostNetWork() ;
//
//            // �ؒf���ꂽ�ڑ������܂ŒʐM���Ă����肾�����ꍇ���[�v�𔲂���
//            if( LostHandle == NetHandle ) break ;
//        }
//
//        // �ؒf�m�F�\��
//        DrawString( 0 , 16 , "�ؒf���܂���" , GetColor( 255 , 255 , 255 ) ) ;
//
//        // �L�[���͑҂�
//        WaitKey() ;
//    }
//
//    DxLib_End() ;    // �c�w���C�u�����g�p�̏I������
//
//    return 0 ;    // �\�t�g�̏I��
//}
