#ifndef HAKO_IO_H
#define HAKO_IO_H

#include<iostream.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
#include<unistd.h>

#include"info.h"
#include"value.h"
#include"map.h"
#include"command.h"

class HakoIO {
public:
    // �ėp�o�b�t�@
    static char buffer[8192];
    static char buffer2[8192];
    static char buffer3[8192];
    static char buffer4[8192];

    // CGI���͂̍��ڍő吔
    static const int maxInput = 16;

    // ���O�t�@�C���p�X�g���[��
    static ofstream *logofs;

    // �ʏ�o��
    static void out(char *);

    // �ݒ�t�@�C���ǂݍ���
    static void readConfigFile();

    // �����t�@�C���ǂݍ���
    static int readInfoFile(int = -1);

    // �����t�@�C����������
    static int writeInfoFile();

    // �R�}���h�t�@�C���ǂݍ���
    static int readComFile(int);

    // �R�}���h�t�@�C����������
    static int writeComFile(int);

    // �n�}�t�@�C���ǂݍ���
    static int readMapFile();

    // �n�}�t�@�C����������
    static int writeMapFile();

    // CGI����
    static int cgiInput();

    // �N�b�L�[����
    static void cookieInput();

    // �N�b�L�[�o��
    static void cookieOutput(char *, char *);

    // ���O�t�@�C�����ݒ�
    static void setLogfileName(char *, int);

    // ���O�t�@�C���J��
    static void logOpen();

    // ���O�t�@�C���������݊�{�֐�
    // ��� * �@���t���O * ��֘A�� * ���֘A�� *
    // �R�}���h�̎�� * �� *
    // x���W2 * y���W2 * �n�`
    // �@���t���O: 0�ʏ� 1�֌W���̂� 2���֌W�ȓ��̂�
    static void logOutput(int, int, int, int,
			  int, int, int, int, int);

    // �������O��������
    static void hisOutput(int, char *, char * = 0);

    // �������O10�s�ɐ؂�l��
    static void hisCut();

    // ���O�t�@�C������
    static void logClose();

    // ���O�t�@�C�����炷
    static void logSlide();

    // ���O�t�@�C��JavaScript�o��
    static void logJsOut(int);
};

#endif
