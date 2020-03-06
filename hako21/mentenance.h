#ifndef MENTENANCE_H
#define MENTENANCE_H

#include "value.h"
#include "hako_io.h"
#include "sys/types.h"
#include "dirent.h"

class Mentenance {
public:
    static void common();
    static void makeData();

    // �f�[�^�폜
    static void deleteData();

    // �f�B���N�g���폜
    static void removeData(int);

    // �o�b�N�A�b�v���s��
    static void backUpData();

    // �o�b�N�A�b�v���s��(����)
    static void slideBack();

    // �X�V�����ύX
    static void changeTime();

    // �o�b�N�A�b�v�f�[�^��������
    static void activateData();

    // �Ō�3������'cgi'���ǂ�������
    static int checkTail(char *);
};

#endif
