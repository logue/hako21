#ifndef MAP_H
#define MAP_H

#include<fstream.h>
#include<stdio.h>

#include"util.h"
#include"value.h"
#include"hako_io.h"
#include"monster.h"

class Island;

struct Point {
    int x;
    int y;
};

class Land;

class Map {
public:
    static Land *land;

    // �̈�m��
    static void alloc();

    // ������
    static void initialize();

    // �t�@�C���o��
    static void output(ofstream *);

    // �t�@�C������
    static void input(ifstream *);

    // JavaScript�o��
    static void jsOut(int);

    // ���ӂ̍��W��Ԃ�
    static Point getPoint(int, int, int);

    // �w����W��Land�̃|�C���^��Ԃ�
    static Land *getLand(int, int);

    // �w����W��Land�̃|�C���^��Ԃ�(����Point��)
    inline static Land *getLand(Point p) {
	return getLand(p.x, p.y);
    }

    // �w����W�̎��ӂ�Land�̃|�C���^��Ԃ�
    static Land *getAround(int, int, int);

    // �w����W�̎��ӂ�Land�̃|�C���^��Ԃ�(����Point��)
    inline static Land *getAround(Point p, int n) {
	return getAround(p.x, p.y, n);
    }

    // �w����W���ӂŁA���̎�ނ̓y�n�𐔂���
    static int countAround(int, int, int, int, int, int = -1);

    // �w����W���ӂŁA���̎�ނ̓y�n�𐔂���(����Point��)
    inline static int countAround(Point p, int kind, int from,
				  int to, int param = -1) {
	return countAround(p.x, p.y, kind, from, to, param);
    }

    // �w����W���ӂŁA�����n�т𐔂���
    static int countNeutral(int, int, int, int);

    // �w����W���ӂŁA�����̓y�n�����n�����邩�ǂ���
    static int nearLand(int, int, int, int, int id);

    // �w����W���ӂŁA�����̓y�n�����n���r�n�ȊO�����邩�ǂ���
    static int nearLand2(int, int, int, int, int id);

    // �C�ۓx�v�Z
    static void calcSea(int, int);

    // �̓y�̊���
    static void infLand(int, int);

    // �w����W�ɂ�����w�b�N�X����
    static void process(int, int);

    // �S�̍ЊQ
    static void globalDisaster();

    // �l�����̑��𐔂���
    static void estimate();

    // �n�k
    static void disEarthquake(int, int);

    // �Ôg
    static void disTsunami(int, int);

    // �䕗
    static void disTyphoon(int, int);

    // �����Q
    static void disMeteo(int, int);

    // ����
    static void disEruption(int, int);

    // ���b
    static void disMonster(Land *, int, int, int);

    // �΍Д���
    static int disFire(Land *, int, int, int, int);

    // �H���\��
    static int disRiot(Land *, int, int, int, int);

    // �
    static void getBoatPeople(Island *);

    // �L���Q
    static void wideDamage(int, int);

    // ���̏���
    static void deleteIslands(int *);

    // �y�n�̎�����X�V
    static void changeOwner(int *);

    // �����v�Z
    static int distance(int, int, int, int);

    // ���O�o��
    inline static void log(int, int, int, int, int = 0,
			   int = 0, int = 0, int = 0, int = 0);
};

class Land {
public:
    // �n�`�̎��
    static const int Sea      = 0x0;
    static const int Waste    = 0x1;
    static const int Town     = 0x2;
    static const int Forest   = 0x3;
    static const int Farm     = 0x4;
    static const int Factory  = 0x5;
    static const int Base     = 0x6;
    static const int DBase    = 0x7;
    static const int Mountain = 0x8;
    static const int Monster  = 0x9;
    static const int SBase    = 0xa;
    static const int Monument = 0xb;

    // �n�`�̃p�����[�^
    // �C
    static const int SeaDeep  = 0x0;
    static const int SeaShoal = 0x1;
    static const int SeaOil   = 0x2;

    // �r�n
    static const int WasteNormal  = 0x0;
    static const int WasteMissile = 0x1;

    // �h�q�{��
    static const int DBaseTrue  = 0x0;
    static const int DBaseFalse = 0x1;

    // �C�ۓx
    static const int SeaLevel1 = 12;
    static const int SeaLevel2 = 24;


    unsigned char kind;  // ���
    unsigned char param; // �p�����[�^
    unsigned char owner; // �ǂ��̗̒n��

    // �t���O(�N�����u�Ȃ�)
    unsigned char flag;

    // �C�ۓx
    unsigned char seaLevel;

    // ������
    void initialize();

    // �t�@�C���o��
    void output(ofstream *);

    // �t�@�C���l��
    void input(ifstream *);

    // JavaScript�o��
    void jsOut(int);

    // �l�����̑��𐔂���
    void estimate();

    // ���O�p�̓y�n�ԍ������߂�
    int landValue();

    // �y�n�̎�����X�V
    void changeOwner(int *);

    // ���x�������߂�
    int getLevel();
};

#endif
