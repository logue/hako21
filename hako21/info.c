#include"info.h"

int Info::turn = 0;
time_t Info::lastTime = 0;
int Info::totalNumber = 0;
int Info::nextID = 0;
Island *Info::islands = 0;

// ���ʏ��o��
void Info::commonOut() {
    // �ϐ�
    HakoIO::out("currentID = 0;"); // �_�~�[
    sprintf(HakoIO::buffer, "titleName = \"%s\";\n", Value::titleName);
    HakoIO::out(HakoIO::buffer);
    sprintf(HakoIO::buffer, "cname = \"%s\";\n", Value::configName);
    HakoIO::out(HakoIO::buffer);
    sprintf(HakoIO::buffer, "cturn = %d;\n", Info::turn);
    HakoIO::out(HakoIO::buffer);
    sprintf(HakoIO::buffer, "eturn = %d;\n", Value::endTurn);
    HakoIO::out(HakoIO::buffer);
    sprintf(HakoIO::buffer, "tnum = %d;\n", Info::totalNumber);
    HakoIO::out(HakoIO::buffer);

    // �e��ݒ���
    sprintf(HakoIO::buffer, "backUpMax = %d;\n", Value::backUpMax);
    HakoIO::out(HakoIO::buffer);
    sprintf(HakoIO::buffer, "debugMode = %d;\n", Value::debugMode);
    HakoIO::out(HakoIO::buffer);
    sprintf(HakoIO::buffer, "cgiURL = '%s';\n", Value::cgiURL);
    HakoIO::out(HakoIO::buffer);
    sprintf(HakoIO::buffer, "bbs = '%s';\n", Value::bbsURL);
    HakoIO::out(HakoIO::buffer);
    sprintf(HakoIO::buffer, "worldSize = %d;\n", Value::worldSize);
    HakoIO::out(HakoIO::buffer);
    sprintf(HakoIO::buffer, "commandMax = %d;\n", Value::commandMax);
    HakoIO::out(HakoIO::buffer);
    sprintf(HakoIO::buffer, "maxNumber = %d;\n", Value::maxNumber);
    HakoIO::out(HakoIO::buffer);
}

// �l�����Ƀ\�[�g�A�y�я��ʕω��e�[�u���̏�������
void Info::sortIslands(int *newOrder) {
    // �΂Ԃ邻����
    int flag = 1;
    while(flag == 1) {
	flag = 0;
	for(int i = 0; i < totalNumber - 1; i++) {
	    if(islands[i].pop < islands[i + 1].pop) {
		Island tmpIsland = islands[i + 1];
		islands[i + 1] = islands[i];
		islands[i] = tmpIsland;
		SWAP(newOrder[i], newOrder[i + 1]);
		flag = 1;
		
	    }
	}
    }

    // ���ʃe�[�u���ɒl������
    for(int i = 0; i < totalNumber; i++) {
	newOrder[islands[i].order - 1] = i + 1;
    }
}

// �V�K�f�[�^�쐬
void Info::initialize() {
    turn = 1;
    int now = time(0);
    lastTime = now - (now % (Value::unitTime));
    totalNumber = 0;
    Info::nextID = 1;
}

// �X�g���[���������
void Info::input(ifstream *ifs) {
    char *buffer = HakoIO::buffer;

    // ���ʍ��ڏo��
    ifs->getline(buffer, 8192);
    turn = atoi(buffer);
    ifs->getline(buffer, 8192);
    lastTime = atoi(buffer);
    ifs->getline(buffer, 8192);
    totalNumber = atoi(buffer);
    ifs->getline(buffer, 8192);
    nextID = atoi(buffer);

    // �e���̏o��
    islands = new Island[totalNumber + 1];
    for(int i = 0; i < totalNumber; i++) {
	islands[i].input(ifs);
    }
}

// �X�g���[���֏o��
void Info::output(ofstream *ofs) {
    // ���ʍ��ڏo��
    *ofs << turn << "\n";
    *ofs << lastTime << "\n";
    *ofs << totalNumber << "\n";
    *ofs << nextID << "\n";

    // �e���̏o��
    for(int i = 0; i < totalNumber; i++) {
	islands[i].output(ofs);
    }
}

// estimate�ɂ���ē��o�����l��������
void Info::clear() {
    for(int i = 0; i < totalNumber; i++) {
	islands[i].clear();
    }
}

// ���̔ԍ�(ID����Ȃ��ď���)�̓����擾
Island *Info::getIsland(int number) {
    if((number == 0) || (number > totalNumber)) {
	return 0;
    }
    return islands + number - 1;
}

// ���̔ԍ�(ID)�̓����擾
Island *Info::getIslandByID(int id) {
    for(int i = 0; i < totalNumber; i++) {
	if(islands[i].id == id) {
	    return &islands[i];
	}
    }
    return 0;

}

// ���̔ԍ�(ID)�̓����擾
int Info::getOrderByID(int id) {
    for(int i = 0; i < totalNumber; i++) {
	if(islands[i].id == id) {
	    return i + 1;
	}
    }
    return 0;
}

// JavaScript�o��
void Info::jsOut(int id) {
    HakoIO::out("infoData = [\n");
    for(int i = 0; i < totalNumber; i++) {
	islands[i].jsOut(id);
	if(i < totalNumber - 1) {
	    HakoIO::out(",");
	}
	HakoIO::out("\n");
    }
    HakoIO::out("];\n");
}

// �X�g���[���֏o��
void Island::output(ofstream *ofs) {
    *ofs
	<< name << "\n"
        << id << "\n"
        << centerX << "\n"
        << centerY << "\n"
        << prize << "\n"
        << monster << "\n"
        << absent << "\n"
        << comment << "\n"
        << password << "\n"
        << money << "\n"
        << food << "\n"
        << pop << "\n"
        << area << "\n"
        << farm << "\n"
        << factory << "\n"
        << mountain << "\n"
    ;
}

// �X�g���[���������
void Island::input(ifstream *ifs) {
    char *buffer = HakoIO::buffer;
    ifs->getline(buffer, 8192);
    strcpy(name, buffer);
    ifs->getline(buffer, 8192);
    id = atoi(buffer);
    ifs->getline(buffer, 8192);
    centerX = atoi(buffer);
    ifs->getline(buffer, 8192);
    centerY = atoi(buffer);
    ifs->getline(buffer, 8192);
    prize = atoi(buffer);
    ifs->getline(buffer, 8192);
    monster = atoi(buffer);
    ifs->getline(buffer, 8192);
    absent = atoi(buffer);
    ifs->getline(buffer, 8192);
    strcpy(comment, buffer);
    ifs->getline(buffer, 8192);
    strcpy(password, buffer);
    ifs->getline(buffer, 8192);
    money = atoi(buffer);
    ifs->getline(buffer, 8192);
    food = atoi(buffer);
    ifs->getline(buffer, 8192);
    pop = atoi(buffer);
    ifs->getline(buffer, 8192);
    area = atoi(buffer);
    ifs->getline(buffer, 8192);
    farm = atoi(buffer);
    ifs->getline(buffer, 8192);
    factory = atoi(buffer);
    ifs->getline(buffer, 8192);
    mountain = atoi(buffer);
/*
    *ifs
	>> name
        >> id
        >> centerX
        >> centerY
        >> prize
        >> monster
        >> absent
        >> comment
        >> password
        >> money
        >> food
        >> pop
        >> area
        >> farm
        >> factory
        >> mountain
    ;
*/
}

// �V�������l
void Island::initialize() {
    prize = 0;
    monster = 0;
    absent = Value::initialAbsent;
    strcpy(comment, "(���o�^)");
    money = Value::initialMoney;
    food = Value::initialFood;
}

// estimate�ɂ���ē��o�����l��������
void Island::clear() {
    pop = 0;
    area = 0;
    farm = 0;
    factory = 0;
    mountain = 0;
}

// �r���Ŏg�p�����l��������
void Island::clear2() {
    shortage = 0;
    target = 0;
    tx = -1;
    ty = -1;
    command = 0;
    amount = 0;
    amonster = 0;
    boatPeople = 0;
    order = 0;
}

// JavaScript�o��
void Island::jsOut(int pid) {
    int pmoney;
    if(pid == id) {
	// �����͐��m��
	pmoney = money;
    } else {
	// �����͐���l
	pmoney = ((money + 500) / 1000) * 1000;
    }

    sprintf(HakoIO::buffer, "['%s',%d, %d, %d, %d, %d, %d, '%s', %d, %d, %d, %d, %d, %d, %d]", name, id, centerX, centerY, prize, monster, absent, comment, pmoney, food, pop, area, farm, factory, mountain);
    HakoIO::out(HakoIO::buffer);
}

// JavaScript�o��
void Island::income() {
    if(pop > farm * 10) {
	// �_�Ƃ�������肪�]��ꍇ
	food += farm * 10; // �_��t���ғ�
	money += MIN((pop - farm * 10) / 10, factory + mountain);
    } else {
	// �_�Ƃ����Ŏ��t�̏ꍇ
	food += pop;
    }

    // �H������
    int food100 = (food * 100) - (pop * Value::eatenFood);
    if(food100 < 0) {
	food = 0;
	shortage = 1; // �Q��
	HakoIO::logOutput(400,0,id,0,0,0,0,0,0);
    } else {
	food = food100 / 100;
    }
}

// ���
void Island::getPrize(int order) {
    cout << "// prize\n";

    // �Г��
    int dec = prePop - pop;
    if(dec >= 1000) {
	if((prize & PrizeDis1) == 0) {
	    prizeLog(6);
	} else if(dec >= 2500) {
	    if((prize & PrizeDis2) == 0) {
		prizeLog(7);
	    } else if(dec >= 5000) {
		if((prize & PrizeDis3) == 0) {
		    prizeLog(8);
		}
	    }
	}
    }

    // �ɉh��
    if(pop >= 5000) {
	if((prize & PrizePros1) == 0) {
	    prizeLog(3);
	} else if(pop >= 10000) {
	    if((prize & PrizePros2) == 0) {
		prizeLog(4);
	    } else if(pop >= 20000) {
		if((prize & PrizePros3) == 0) {
		    prizeLog(5);
		}
	    }
	}
    }

    // ���a��
    if(boatTotal >= 200) {
	if((prize & PrizeWar1) == 0) {
	    prizeLog(9);
	} else if(boatTotal >= 500) {
	    if((prize & PrizeWar2) == 0) {
		prizeLog(10);
	    } else if(boatTotal >= 800) {
		if((prize & PrizeWar3) == 0) {
		    prizeLog(11);
		}
	    }
	}
    }

    // �^�[���t
    if(order == 1) {
	if((Info::turn % 1000) == 0){
	    prizeLog(2);
	} else if((Info::turn % 300) == 0){
	    prizeLog(1);
	} else if((Info::turn % 100) == 0){
	    prizeLog(0);
	}
    }

}

// ��܃��O
void Island::prizeLog(int k) {
    prize |= 1<<k;
    HakoIO::logOutput(600, 0, id, 0, 0, 0, 0, 0, k);
}
