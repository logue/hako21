#ifndef TURN_H
#define TURN_H

#include"map.h"
#include"mentenance.h"

class Turn {
public:
    // �^�[���������s��
    static int *order;

    // �w�b�N�X���s��
    static int *orderX;
    static int *orderY;

    // �^�[���������s����ݒ�
    static void makeOrder();

    // �w�b�N�X���s������ݒ�
    static void makeOrderXY();

    // �^�[���i�s
    static void main();

    // ���O�o��
    inline static void log(int, int, int, int, int = 0,
			   int = 0, int = 0, int = 0, int = 0);

};

#endif
