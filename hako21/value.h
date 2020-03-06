#ifndef VALUE_H
#define VALUE_H

#include<sys/stat.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define MODE_TOPPAGE             100
#define MODE_MENTENANCE          200
#define MODE_MENTENANCE_MAKEDATA 201
#define MODE_MENTENANCE_DELETE   202
#define MODE_MENTENANCE_BACKUP   203
#define MODE_MENTENANCE_TIME     204
#define MODE_MENTENANCE_ACTIVATE 205
#define MODE_MAP                 300
#define MODE_MAP_OWNER           301
#define MODE_MAP_COMMAND         302
#define MODE_NEW                 400
#define MODE_TURN                500
#define MODE_MESSAGE             600
#define MODE_RENAME              700

class Value {
public:
    static int mode;

    // �ǂݍ���
    static void input(ifstream *);

    // �R�����g�s����
    static int commentLine(char *);

    // ���[�h�؂�ւ��s����
    static int modeLine(char *);

    // ���e�̊J�n�_
    static char *contStart(char *);

    // �ݒ�t�@�C������ǂނ��
    // �}�X�^�[�p�X
    static char *masterPassword;

    // ����p�X
    static char *specialPassword;

    // �摜�t�@�C���Ȃǂ�u����
    static char *fileDir;

    // CGI���s�t�@�C���̈ʒu
    static char *cgiURL;

    // �f���̈ʒu
    static char *bbsURL;

    // �ݒ�t�@�C���̍���
    static char *configName;

    // �^�C�g��
    static char *titleName;

    // �f�[�^�f�B���N�g���̖��O
    static char *dirName;

    // �f�[�^�f�B���N�g���̃��[�h
    static mode_t dirMode;

    // BODY�^�O�̃I�v�V����
    static char *htmlBody;

    // �����J�萔�̏����l
    static int initialAbsent;

    // �ŏI�^�[��
    static int endTurn;

    // ���������^�[��
    static int giveupTurn;

    // �����̏����l
    static int initialMoney;

    // �H���̏����l
    static int initialFood;

    // �n�}�̑傫��
    static int worldSize;

    // ���̍ő吔
    static int maxNumber;

    // �R�}���h���͐�
    static int commandMax;

    // 1�^�[���̕b��
    static int unitTime;

    // �o�b�N�A�b�v�̕p�x�A�ێ���
    static int backUpTurn;
    static int backUpMax;

    // �f�o�b�O���[�h���ǂ���
    static int debugMode;

    // �H�����
    static int eatenFood;

    // ���O�ێ��^�[����
    static int logMax;

    // ��1�P�ʂ̒l�i
    static int treeValue;

    // �L�O��̎��
    static int monumentVar;

    // �ЊQ
    static int disFire;        // �Ύ�
    static int disEarthquake1; // �n�k(�V��)
    static int disEarthquake2; // �n�k(�l��)
    static int disTsunami;     // �Ôg
    static int disTyphoon;     // �䕗
    static int disMeteo;       // 覐�
    static int disHugeMeteo;   // ����覐�
    static int disEruption;    // ����
    static int disMaizo;       // ������
    static int disMonster;     // ���b�o����(��)

    // �~�T�C���˒�
    static int missileReach;

    // �ϐ�
    // ���[�h
    static int mainMode;

    // ����
    static char *islandName;

    // �p�X���[�h
    static char *password;

    // �m�F�p�p�X���[�h
    static char *password2;

    // �ύX�p�X���[�h
    static char *password3;

    // X���W
    static int pointX;

    // Y���W
    static int pointY;

    // ����ID(�����e�i���X���̓f�[�^��ID�A������-1)
    static int id;

    // ���̓R�}���h������
    static char *commandList;

    // �R�����g
    static char *message;

    // �ύX����
    static unsigned int cTime;

};

#endif

