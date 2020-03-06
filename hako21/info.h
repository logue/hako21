#ifndef INFO_H
#define INFO_H

#include<time.h>
#include<fstream.h>

#include "value.h"
#include "hako_io.h"

class Island;

class Info {
public:
    // ���ʃf�[�^
    static int turn;
    static time_t lastTime;
    static int totalNumber;
    static int nextID;

    // �e���̏��
    static Island *islands;

    // �l�����Ƀ\�[�g�A�y�я��ʕω��e�[�u���̏�������
    static void sortIslands(int *);

    // �����f�[�^
    static void initialize();

    // �ǂݍ���
    static void input(ifstream *);

    // ��������
    static void output(ofstream *);

    // ���ʏ��o��
    static void commonOut();

    // estimate�ɂ���ē��o�����l��������
    static void clear();

    // ���̔ԍ�(ID����Ȃ��ď���)�̓����擾
    static Island *getIsland(int);

    // ���̔ԍ�(ID)�̓����擾
    static Island *getIslandByID(int);

    // ���̔ԍ�(ID)�̓��̏��ʂ��擾
    static int getOrderByID(int);

    // JavaScript�o��
    static void jsOut(int);
};

class Island {
public:
    // �ܒ萔
    static const int PrizeTurn1 = 0x0001;
    static const int PrizeTurn2 = 0x0002;
    static const int PrizeTurn3 = 0x0004;
    static const int PrizePros1 = 0x0008;
    static const int PrizePros2 = 0x0010;
    static const int PrizePros3 = 0x0020;
    static const int PrizeDis1  = 0x0040;
    static const int PrizeDis2  = 0x0080;
    static const int PrizeDis3  = 0x0100;
    static const int PrizeWar1  = 0x0200;
    static const int PrizeWar2  = 0x0400;
    static const int PrizeWar3  = 0x0800;

    // ���̑���
    char name[32];     // ����
    int id;            // ID�ԍ�
    int centerX;       // ���S�n��X���W
    int centerY;       // ���S�n��Y���W
    int prize;         // ���
    int monster;       // ���b
    int absent;        // �A�������J�萔
    char comment[100];  // �R�����g
    char password[100]; // �p�X���[�h
    int money;         // ����
    int food;          // �H��
    int pop;           // �l��
    int area;          // �L��
    int farm;          // �_��K��
    int factory;       // �H��K��
    int mountain;      // �̌@��K��

    // �r���Ŏg���l
    int shortage; // �Q���Ԃ���1�A�U�v����������-1�A�łȂ����0
    int target; // ���Ƃ��Ẵ^�[�Q�b�g
    int tx, ty; // �~�T�C�����̃^�[�Q�b�g
    int command; // �s��
    int amount; // �~�T�C�����̐�
    int amonster; // �o���l�����b�̐�
    int boatPeople;
    int order; // ����
    int prePop; // �^�[���J�n���_�ł̐l��
    int boatTotal;   // �󂯓���

    // �ǂݍ���
    void input(ifstream *);

    // ��������
    void output(ofstream *);

    // ������ԂփZ�b�g
    void initialize();

    // estimate�ɂ���ē��o�����l��������
    void clear();

    // �r���Ŏg�p�����l��������
    void clear2();

    // JavaScript�o��
    void jsOut(int);

    // �����A����
    void income();

    // ���
    void getPrize(int);
    void prizeLog(int);
};

#endif
