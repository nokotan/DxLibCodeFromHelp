#include "DxLib.h"
#include <stdio.h>
#include <malloc.h>

int main()
{
    FILE *fp ;
    unsigned char *Data ;
    int Size, SoundHandle, i ;

    // �c�w���C�u�����̏�����
    if( DxLib_Init() == -1 )
        return -1 ;

    // �t�@�C�� testWav.enc ���ۂ��ƃ������ɓǂݍ���
    {
        // �o�C�i�����[�h�ŊJ��
        fp = fopen( "testWav.enc", "rb" ) ;

        // �t�@�C���̃T�C�Y�𓾂�
        {
            // �t�@�C���|�C���^���t�@�C���̖��[��
            fseek( fp, 0L, SEEK_END ) ;

            // �t�@�C���̖��[�Ńt�@�C���|�C���^�̃A�h���X��
            // �擾����΂���̓t�@�C���̃T�C�Y
            Size = ftell( fp ) ;

            // �t�@�C���|�C���^���t�@�C���̐擪�ɖ߂�
            fseek( fp, 0L, SEEK_SET ) ;
        }

        // �t�@�C�����ہX�ǂݍ��߂郁�����̈���m�ۂ���
        Data = ( unsigned char * )malloc( Size ) ;

        // �t�@�C�����ہX�ǂݍ���
        fread( Data, Size, 1, fp ) ;

        // �t�@�C�������
        fclose( fp ) ;
    }

    // �m�n�s���Z�̈Í�������
    for( i = 0 ; i < Size ; i ++ )
    {
        // �m�n�s���Z���ꂽ�f�[�^�́A�������m�n�s���Z������ƌ��ɖ߂�
        Data[i] = ~Data[i] ;
    }

    // ���ɖ߂����T�E���h�f�[�^�ŃT�E���h�n���h�����쐬����
    SoundHandle = LoadSoundMemByMemImage( Data, Size ) ;

    // �T�E���h�n���h�����쐬���I�������T�E���h�f�[�^��
    // �i�[���Ă����������̈���J������
    free( Data ) ;

    // �������Đ�
    PlaySoundMem( SoundHandle, DX_PLAYTYPE_BACK ) ;

    // �L�[���������܂ő҂�
    WaitKey() ;

    // �T�E���h�n���h���̍폜
    DeleteSoundMem( SoundHandle ) ;

    // �c�w���C�u�����̌�n��
    DxLib_End() ;

    // �\�t�g�I��
    return 0 ;
}
