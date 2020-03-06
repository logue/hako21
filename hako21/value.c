#include "value.h"

// �ǂݍ��݃��[�h
int Value::mode = 0;

// �f�t�H���g�l
char *Value::masterPassword = "\n";
char *Value::specialPassword = "\n";
char *Value::cgiURL = "http://?/?";
char *Value::fileDir = "file://?/?";
char *Value::bbsURL = "http://?/?";
char *Value::htmlBody = "BGCOLOR=\"#EEFFFF\"";
char *Value::titleName = "���돔��2+";
char *Value::configName = "default";
char *Value::dirName = "data";
mode_t Value::dirMode = 0755;
int Value::initialAbsent = 25;
int Value::giveupTurn = 28;
int Value::endTurn = 300;
int Value::initialMoney = 100;
int Value::initialFood = 100;
int Value::worldSize = 60;
int Value::maxNumber = 50;
int Value::commandMax = 20;
int Value::unitTime = 21600;
int Value::backUpTurn = 4;
int Value::backUpMax = 4;
int Value::debugMode = 1;
int Value::eatenFood = 20;
int Value::logMax = 8;
int Value::treeValue = 5;
int Value::monumentVar = 3;
int Value::disFire = 10;
int Value::disEarthquake1 = 80;
int Value::disEarthquake2 = 5;
int Value::disTsunami = 300;
int Value::disTyphoon = 400;
int Value::disMeteo = 200;
int Value::disHugeMeteo = 100;
int Value::disEruption = 200;
int Value::disMaizo = 10;
int Value::disMonster = 2;
int Value::missileReach = 12;

// ���[�h
int Value::mainMode = MODE_TOPPAGE;

// ����
char *Value::islandName = "";

// �p�X���[�h
char *Value::password = "";

// �m�F�p�p�X���[�h
char *Value::password2 = "";

// �ύX�p�p�X���[�h
char *Value::password3 = "";

// X���W
int Value::pointX = 0;

// Y���W
int Value::pointY = 0;

// ����ID
int Value::id = 0;

// ���̓R�}���h������
char *Value::commandList = "";

// ����
char *Value::message = "";

// �ύX����
unsigned int Value::cTime = 0;

// �ǂݍ���
void Value::input(ifstream *ifs) {
    while(!(ifs->eof())) {
	char *line = new char[256];
	ifs->getline(line, 256);
	if(commentLine(line)) {
	    continue;
	}
	if(modeLine(line)) {
	    continue;
	}
	char *cont = contStart(line);
	if(cont) {
	    if(strcmp(line, "masterPassword") == 0) {
		masterPassword = cont;
	    } else if(strcmp(line, "specialPassword") == 0) {
		specialPassword = cont;
	    } else if(strcmp(line, "cgiURL") == 0) {
		cgiURL = cont;
	    } else if(strcmp(line, "bbsURL") == 0) {
		bbsURL = cont;
	    } else if(strcmp(line, "fileDir") == 0) {
		fileDir = cont;
	    } else if(strcmp(line, "htmlBody") == 0) {
		htmlBody = cont;
	    } else if(strcmp(line, "titleName") == 0) {
		titleName = cont;
	    } else if(strcmp(line, "dirName") == 0) {
		dirName = cont;
	    } else if(strcmp(line, "dirMode") == 0) {
		sscanf(cont, "%o", &dirMode);
	    } else if(strcmp(line, "initialAbsent") == 0) {
		initialAbsent = atoi(cont);
	    } else if(strcmp(line, "giveupTurn") == 0) {
		giveupTurn = atoi(cont);
	    } else if(strcmp(line, "endTurn") == 0) {
		endTurn = atoi(cont);
	    } else if(strcmp(line, "initialMoney") == 0) {
		initialMoney = atoi(cont);
	    } else if(strcmp(line, "initialFood") == 0) {
		initialFood = atoi(cont);
	    } else if(strcmp(line, "worldSize") == 0) {
		worldSize = atoi(cont);
	    } else if(strcmp(line, "maxNumber") == 0) {
		maxNumber = atoi(cont);
	    } else if(strcmp(line, "commandMax") == 0) {
		commandMax = atoi(cont);
	    } else if(strcmp(line, "unitTime") == 0) {
		unitTime = atoi(cont);
	    } else if(strcmp(line, "backUpTurn") == 0) {
		backUpTurn = atoi(cont);
	    } else if(strcmp(line, "backUpMax") == 0) {
		backUpMax = atoi(cont);
	    } else if(strcmp(line, "debugMode") == 0) {
		debugMode = atoi(cont);
	    } else if(strcmp(line, "eatenFood") == 0) {
		eatenFood = atoi(cont);
	    } else if(strcmp(line, "treeValue") == 0) {
		treeValue = atoi(cont);
	    } else if(strcmp(line, "monumentVar") == 0) {
		monumentVar = atoi(cont);
	    } else if(strcmp(line, "disFire") == 0) {
		disFire = atoi(cont);
	    } else if(strcmp(line, "disEarthquake1") == 0) {
		disEarthquake1 = atoi(cont);
	    } else if(strcmp(line, "disEarthquake2") == 0) {
		disEarthquake2 = atoi(cont);
	    } else if(strcmp(line, "disTsunami") == 0) {
		disTsunami = atoi(cont);
	    } else if(strcmp(line, "disTyphoon") == 0) {
		disTyphoon = atoi(cont);
	    } else if(strcmp(line, "disMeteo") == 0) {
		disMeteo = atoi(cont);
	    } else if(strcmp(line, "disHugeMeteo") == 0) {
		disHugeMeteo = atoi(cont);
	    } else if(strcmp(line, "disEruption") == 0) {
		disEruption = atoi(cont);
	    } else if(strcmp(line, "disMaizo") == 0) {
		disMaizo = atoi(cont);
	    } else if(strcmp(line, "disMonster") == 0) {
		disMonster = atoi(cont);
	    } else if(strcmp(line, "missileReach") == 0) {
		missileReach = atoi(cont);
	    }
	}
    }
}

// �R�����g�s����
int Value::commentLine(char *line) {
    char *pt = line;
    while(*pt != 0) {
	if((*pt == '\t') ||
	   (*pt == ' ')) {
	    pt++;
	} else if(*pt == '#') {
	    return 1;
	} else {
	    return 0;
	}
    }
    return 0;
}

// �R�����g�s����
int Value::modeLine(char *line) {
    if(*line != ':') {
	return mode;
    }

    if(strcmp(line + 1, Value::configName) == 0) {
	mode = 0;
    } else {
	mode = 1;
    }
    return 1;
}

char *Value::contStart(char *line) {
    char *pt = line;
    while(*pt != 0) {
	if(*pt == '=') {
	    *pt = 0;
	    return (pt + 1);
	}
	pt++;
    }
    return 0;
}
