#ifndef UTIL_H
#define UTIL_H

#include<stdlib.h>
#include<time.h>
#include<sys/file.h>
#include "hako_io.h"
#include "info.h"

#define SWAP(X,Y) {int tmpval; tmpval = (Y); (Y) = (X); (X) = tmpval; }
#define MIN(X,Y) (((X) > (Y)) ? (Y) : (X))

class Util {
public:
    static int lockFd;

    // ���b�N(�������A�_�~�[)
    static void lock();

    // ���b�N����(�������A�_�~�[)
    static void unlock();

    // ���O�̐��������`�F�b�N
    static int badNameCheck(char *);

    // ���̕������܂ނ��ǂ����`�F�b�N
    static int charCheck(char *, char);

    // ���̖��O�����łɎg���Ă��邩�`�F�b�N
    static int dupCheck(char *);

    // �������16�i��
    static int hex(char *);

    // ����(0 -> n-1)
    static int dice(int);

    // n byte�ȉ��ɐ؂�l�߂�
    static void cutColumn(char *, int);

    // �p�X���[�h�`�F�b�N
    static int passCheck();
};

#endif
