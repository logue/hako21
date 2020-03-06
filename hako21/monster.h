#ifndef MONSTER_H
#define MONSTER_H

#include"value.h"
#include"info.h"

class Monster {
public:
    static int kind;
    static int hp;
    static int move;

    // ��ނ�����b�����
    static void makeMonster(int);

    // �p�����[�^����e�l��ݒ�
    static void fromParam(int);

    // �p�����[�^���擾
    static int toParam();

    // �d������
    static int isHard();

    // �o���l
    static int getExp();

    // �l�i
    static int getValue();
};

#endif
