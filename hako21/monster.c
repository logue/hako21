#include"monster.h"
// ����ދ��邩
const int number = 8;

// ��{HP
const int baseHP[] = {2, 1, 1, 3, 2, 1, 4, 5};

// �ϓ��̗�
const int diffHP[] = {0, 1, 1, 1, 1, 0, 1, 1};

// ����\��
// 0 ���ɂȂ�
// 1 ��������(�ő�2�����邭)
// 2 �����ƂĂ�����(�ő剽�����邭���s��)
// 3 ��^�[���͍d��
// 4 �����^�[���͍d��
const int skill[] = {0, 0, 3, 0, 1, 2, 4, 0};

// �o���l
const int expPoint[] = { 5, 5, 7, 12, 15, 10, 20, 30};

// �c�[�̒l�i
const int value[] = { 0, 400, 500, 1000, 800, 300, 1500, 2000};


int Monster::kind = 0;
int Monster::hp = 0;
int Monster::move = 0;

// ��ނ�����b�����
void Monster::makeMonster(int l) {
    int k = 0;
    switch(l) {
    case 0:
	k = 0;
	break;

    case 1:
	k = 1 + Util::dice(2);
	break;

    case 2:
	k = 1 + Util::dice(5);
	break;

    case 3:
	k = 1 + Util::dice(7);
	break;
    }
    
    int param = k * 20 + baseHP[k] + Util::dice(diffHP[k] + 1);
    fromParam(param);
}

// �p�����[�^����e�l��ݒ�
void Monster::fromParam(int param) {
    kind = param / 20;
    hp = param % 20;
    if(skill[kind] == 1) {
	move = 2;
    } else if(skill[kind] == 2) {
	move = 9999;
    } else {
	move = 1;
    }
}

// �p�����[�^���擾
int Monster::toParam() {
    return kind * 20 + hp;
}

// �d������
int Monster::isHard() {
    int s;
    s = skill[kind];
    switch(s) {
    case 3:
	return ((Info::turn % 2) == 1) ? 1 : 0;

    case 4:
	return ((Info::turn % 2) == 0) ? 1 : 0;

    default:
	return 0;
    }
}

// �o���l
int Monster::getExp() {
    return expPoint[kind];
}

// �l�i
int Monster::getValue() {
    return value[kind];
}
